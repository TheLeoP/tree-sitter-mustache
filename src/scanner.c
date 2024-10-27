#include "string.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include "tree_sitter/parser.h"

#include <wctype.h>
enum TokenType {
  START_TAG_NAME,
  END_TAG_NAME,
  ERRONEOUS_END_TAG_NAME,
  START_DELIMITER,
  END_DELIMITER,
  COMMENT_CONTENT,
  IDENTIFIER_CONTENT,
  SET_START_DELIMITER_CONTENT,
  SET_END_DELIMITER_CONTENT,
  OLD_END_DELIMITER,
  TEXT,
};

typedef Array(char) String;

typedef struct {
  String tag_name;
} Tag;

static inline void tag_free(Tag *tag) { array_delete(&tag->tag_name); }

static inline Tag tag_new() {
  Tag tag;
  tag.tag_name = (String)array_new();
  return tag;
}

static inline bool tag_eq(const Tag *self, const Tag *other) {
  if (self->tag_name.size != other->tag_name.size) {
    return false;
  }
  if (memcmp(self->tag_name.contents, other->tag_name.contents,
             self->tag_name.size) != 0) {
    return false;
  }
  return true;
}

typedef struct {
  Array(Tag) tags;
  String start_delimiter;
  String end_delimiter;
  String old_end_delimiter;
} Scanner;

static void pop_tag(Scanner *scanner) {
  Tag popped_tag = array_pop(&scanner->tags);
  tag_free(&popped_tag);
}

static int get_delimiter(String delimiter, int i, char def) {
  if (delimiter.size >= i + 1)
    return *array_get(&delimiter, i);
  return def;
}

static String scan_tag_name(Scanner *scanner, TSLexer *lexer) {
  String tag_name = array_new();
  char first = get_delimiter(scanner->end_delimiter, 0, '}');
  while (lexer->lookahead != first && !lexer->eof(lexer)) {
    array_push(&tag_name, lexer->lookahead);
    lexer->advance(lexer, false);
  }
  return tag_name;
}

static unsigned serialize(Scanner *scanner, char *buffer) {
  uint16_t tag_count =
      scanner->tags.size > UINT16_MAX ? UINT16_MAX : scanner->tags.size;
  uint16_t serialized_tag_count = 0;

  unsigned size = sizeof(tag_count);
  memcpy(&buffer[size], &tag_count, sizeof(tag_count));
  size += sizeof(tag_count);

  for (; serialized_tag_count < tag_count; serialized_tag_count++) {
    Tag tag = scanner->tags.contents[serialized_tag_count];
    unsigned name_length = tag.tag_name.size;
    if (name_length > UINT8_MAX) {
      name_length = UINT8_MAX;
    }
    if (size + 2 + name_length >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
      break;
    }
    buffer[size++] = (char)name_length;
    strncpy(&buffer[size], tag.tag_name.contents, name_length);
    size += name_length;
  }

  memcpy(&buffer[0], &serialized_tag_count, sizeof(serialized_tag_count));

  unsigned start_delimiter_length = scanner->start_delimiter.size;
  if (size + 2 + start_delimiter_length >=
      TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
    return size;
  }
  buffer[size++] = (char)start_delimiter_length;
  strncpy(&buffer[size], scanner->start_delimiter.contents,
          start_delimiter_length);
  size += start_delimiter_length;

  unsigned end_delimiter_length = scanner->end_delimiter.size;
  if (size + 2 + end_delimiter_length >=
      TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
    return size;
  }
  buffer[size++] = (char)end_delimiter_length;
  strncpy(&buffer[size], scanner->end_delimiter.contents, end_delimiter_length);
  size += end_delimiter_length;

  unsigned old_end_delimiter_length = scanner->old_end_delimiter.size;
  if (size + 2 + old_end_delimiter_length >=
      TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
    return size;
  }
  buffer[size++] = (char)old_end_delimiter_length;
  strncpy(&buffer[size], scanner->old_end_delimiter.contents,
          old_end_delimiter_length);
  size += old_end_delimiter_length;

  return size;
}

static void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
  for (unsigned i = 0; i < scanner->tags.size; i++) {
    tag_free(&scanner->tags.contents[i]);
  }
  array_clear(&scanner->tags);
  array_clear(&scanner->start_delimiter);
  array_clear(&scanner->end_delimiter);

  if (length > 0) {
    unsigned size = 0;
    uint16_t tag_count = 0;
    uint16_t serialized_tag_count = 0;

    memcpy(&serialized_tag_count, &buffer[size], sizeof(serialized_tag_count));
    size += sizeof(serialized_tag_count);

    memcpy(&tag_count, &buffer[size], sizeof(tag_count));
    size += sizeof(tag_count);

    array_reserve(&scanner->tags, tag_count);
    if (tag_count > 0) {
      unsigned iter = 0;
      for (iter = 0; iter < serialized_tag_count; iter++) {
        Tag tag = tag_new();
        uint16_t name_length = (uint8_t)buffer[size++];
        array_reserve(&tag.tag_name, name_length);
        tag.tag_name.size = name_length;
        memcpy(tag.tag_name.contents, &buffer[size], name_length);
        size += name_length;
        array_push(&scanner->tags, tag);
      }
      // add zero tags if we didn't read enough, this is because the
      // buffer had no more room but we held more tags.
      for (; iter < tag_count; iter++) {
        array_push(&scanner->tags, tag_new());
      }
    }

    uint16_t start_delimiter_length = (uint8_t)buffer[size++];
    array_reserve(&scanner->start_delimiter, start_delimiter_length);
    scanner->start_delimiter.size = start_delimiter_length;
    memcpy(scanner->start_delimiter.contents, &buffer[size],
           start_delimiter_length);
    size += start_delimiter_length;

    uint16_t end_delimiter_length = (uint8_t)buffer[size++];
    array_reserve(&scanner->end_delimiter, end_delimiter_length);
    scanner->end_delimiter.size = end_delimiter_length;
    memcpy(scanner->end_delimiter.contents, &buffer[size],
           end_delimiter_length);
    size += end_delimiter_length;

    uint16_t old_end_delimiter_length = (uint8_t)buffer[size++];
    array_reserve(&scanner->old_end_delimiter, old_end_delimiter_length);
    scanner->old_end_delimiter.size = old_end_delimiter_length;
    memcpy(scanner->old_end_delimiter.contents, &buffer[size],
           old_end_delimiter_length);
    size += old_end_delimiter_length;
  }
}

static bool scan_start_tag_name(Scanner *scanner, TSLexer *lexer) {
  String tag_name = scan_tag_name(scanner, lexer);
  if (tag_name.size == 0) {
    array_delete(&tag_name);
    return false;
  }

  Tag tag = tag_new();
  tag.tag_name = tag_name;
  array_push(&scanner->tags, tag);
  lexer->result_symbol = START_TAG_NAME;
  return true;
}

static bool scan_end_tag_name(Scanner *scanner, TSLexer *lexer) {
  String tag_name = scan_tag_name(scanner, lexer);

  if (tag_name.size == 0) {
    array_delete(&tag_name);
    return false;
  }

  Tag tag = tag_new();
  tag.tag_name = tag_name;
  if (scanner->tags.size > 0 && tag_eq(array_back(&scanner->tags), &tag)) {
    pop_tag(scanner);
    lexer->result_symbol = END_TAG_NAME;
  } else {
    lexer->result_symbol = ERRONEOUS_END_TAG_NAME;
  }

  tag_free(&tag);
  return true;
}

static bool scan_start_delimiter(Scanner *scanner, TSLexer *lexer) {
  /* TODO: use i instead of fixed numbers in all calls to this function */
  int first = get_delimiter(scanner->start_delimiter, 0, '{');
  if (first != lexer->lookahead) {
    return false;
  }
  lexer->advance(lexer, false);
  int second = get_delimiter(scanner->start_delimiter, 1, '{');
  if (second != lexer->lookahead) {
    return false;
  }
  lexer->advance(lexer, false);

  lexer->result_symbol = START_DELIMITER;
  return true;
}

static bool scan_end_delimiter(Scanner *scanner, TSLexer *lexer) {
  int first = get_delimiter(scanner->end_delimiter, 0, '}');
  if (first != lexer->lookahead) {
    return false;
  }
  lexer->advance(lexer, false);
  int second = get_delimiter(scanner->end_delimiter, 1, '}');
  if (second != lexer->lookahead) {
    return false;
  }
  lexer->advance(lexer, false);

  lexer->result_symbol = END_DELIMITER;
  return true;
}

static bool scan_comment_content(Scanner *scanner, TSLexer *lexer) {
  int first = get_delimiter(scanner->end_delimiter, 0, '}');
  while (lexer->lookahead != first) {
    if (lexer->eof(lexer))
      return false;
    lexer->advance(lexer, false);
  }
  lexer->result_symbol = COMMENT_CONTENT;
  return true;
}

static bool scan_identifier_content(Scanner *scanner, TSLexer *lexer) {
  int first_start = get_delimiter(scanner->start_delimiter, 0, '{');
  int first_end = get_delimiter(scanner->end_delimiter, 0, '}');
  if (lexer->lookahead == first_start || lexer->lookahead == first_end ||
      lexer->lookahead == '&' || lexer->lookahead == '^' ||
      lexer->lookahead == '=' || lexer->lookahead == '/' ||
      lexer->lookahead == '!' || lexer->lookahead == '#' ||
      lexer->lookahead == '.') {
    return false;
  }
  lexer->advance(lexer, false);
  while (lexer->lookahead != first_end && lexer->lookahead != '.') {
    if (lexer->eof(lexer))
      return false;
    lexer->advance(lexer, false);
  }
  lexer->result_symbol = IDENTIFIER_CONTENT;
  return true;
}

static bool scan_start_delimiter_content(Scanner *scanner, TSLexer *lexer) {
  String content = array_new();
  while (!iswspace(lexer->lookahead)) {
    if (lexer->lookahead == '=' || lexer->eof(lexer)) {
      array_delete(&content);
      return false;
    }
    array_push(&content, lexer->lookahead);
    lexer->advance(lexer, false);
  }
  if (content.size == 0 || lexer->eof(lexer)) {
    array_delete(&content);
    return false;
  }

  scanner->start_delimiter = content;
  lexer->result_symbol = SET_START_DELIMITER_CONTENT;
  return true;
}

static bool scan_end_delimiter_content(Scanner *scanner, TSLexer *lexer) {
  String content = array_new();
  while (lexer->lookahead != '=') {
    if (lexer->eof(lexer))
      return false;
    array_push(&content, lexer->lookahead);
    lexer->advance(lexer, false);
  }
  if (content.size == 0) {
    array_delete(&content);
    return false;
  }

  scanner->old_end_delimiter = scanner->end_delimiter;
  scanner->end_delimiter = content;
  lexer->result_symbol = SET_END_DELIMITER_CONTENT;
  return true;
}

static bool scan_old_end_delimiter(Scanner *scanner, TSLexer *lexer) {
  int first = get_delimiter(scanner->old_end_delimiter, 0, '}');
  if (first != lexer->lookahead) {
    return false;
  }
  lexer->advance(lexer, false);
  int second = get_delimiter(scanner->old_end_delimiter, 1, '}');
  if (second != lexer->lookahead) {
    return false;
  }
  lexer->advance(lexer, false);

  lexer->result_symbol = OLD_END_DELIMITER;
  return true;
}

static bool scan_text(Scanner *scanner, TSLexer *lexer) {
  int first_start = get_delimiter(scanner->start_delimiter, 0, '{');
  int first_end = get_delimiter(scanner->end_delimiter, 0, '}');
  if (first_start == lexer->lookahead || first_end == lexer->lookahead) {
    return false;
  }
  while (lexer->lookahead != first_start && lexer->lookahead != first_end) {
    lexer->advance(lexer, false);
    if (lexer->eof(lexer)) {
      break;
    }
  }
  lexer->result_symbol = TEXT;
  return true;
}

static bool scan(Scanner *scanner, TSLexer *lexer, const bool *valid_symbols) {

  while (iswspace(lexer->lookahead)) {
    lexer->advance(lexer, true);
  }

  int first_start = get_delimiter(scanner->start_delimiter, 0, '{');
  int first_end = get_delimiter(scanner->end_delimiter, 0, '}');

  if (valid_symbols[START_DELIMITER] && lexer->lookahead == first_start) {
    return scan_start_delimiter(scanner, lexer);
  }
  if (valid_symbols[END_DELIMITER] && lexer->lookahead == first_end) {
    return scan_end_delimiter(scanner, lexer);
  }
  if (valid_symbols[COMMENT_CONTENT]) {
    return scan_comment_content(scanner, lexer);
  }
  if (valid_symbols[IDENTIFIER_CONTENT]) {
    return scan_identifier_content(scanner, lexer);
  }
  if (valid_symbols[SET_START_DELIMITER_CONTENT]) {
    return scan_start_delimiter_content(scanner, lexer);
  }
  if (valid_symbols[SET_END_DELIMITER_CONTENT]) {
    return scan_end_delimiter_content(scanner, lexer);
  }
  if (valid_symbols[OLD_END_DELIMITER]) {
    return scan_old_end_delimiter(scanner, lexer);
  }

  if (valid_symbols[TEXT] && lexer->lookahead != '\0') {
    return scan_text(scanner, lexer);
  }

  if (valid_symbols[START_TAG_NAME]) {
    return scan_start_tag_name(scanner, lexer);
  }
  if (valid_symbols[END_TAG_NAME] || valid_symbols[ERRONEOUS_END_TAG_NAME]) {
    return scan_end_tag_name(scanner, lexer);
  }

  return false;
}

void *tree_sitter_mustache_external_scanner_create(void) {
  Scanner *scanner = (Scanner *)ts_calloc(1, sizeof(Scanner));
  return scanner;
}

void tree_sitter_mustache_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (unsigned i = 0; i < scanner->tags.size; i++) {
    tag_free(&scanner->tags.contents[i]);
  }
  array_delete(&scanner->tags);
  array_delete(&scanner->start_delimiter);
  array_delete(&scanner->end_delimiter);
  ts_free(scanner);
}

unsigned tree_sitter_mustache_external_scanner_serialize(void *payload,
                                                         char *buffer) {
  Scanner *scanner = (Scanner *)payload;
  return serialize(scanner, buffer);
}

void tree_sitter_mustache_external_scanner_deserialize(void *payload,
                                                       const char *buffer,
                                                       unsigned length) {
  Scanner *scanner = (Scanner *)payload;
  deserialize(scanner, buffer, length);
}

bool tree_sitter_mustache_external_scanner_scan(void *payload, TSLexer *lexer,
                                                const bool *valid_symbols) {
  Scanner *scanner = (Scanner *)payload;
  return scan(scanner, lexer, valid_symbols);
}