#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 56
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 41
#define ALIAS_COUNT 3
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 11
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  anon_sym_BANG = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_AMP = 4,
  anon_sym_EQ = 5,
  aux_sym_set_delimiter_statement_token1 = 6,
  anon_sym_SLASH = 7,
  anon_sym_POUND = 8,
  anon_sym_CARET = 9,
  anon_sym_DOT = 10,
  sym__start_tag_name = 11,
  sym__end_tag_name = 12,
  sym__erroneous_end_tag_name = 13,
  sym_start_delimiter = 14,
  sym_end_delimiter = 15,
  sym__comment_content = 16,
  sym__identifier_content = 17,
  sym__setstart_delimiter_content = 18,
  sym__set_end_delimiter_content = 19,
  sym__old_end_delimiter = 20,
  sym_text = 21,
  sym_template = 22,
  sym__declaration = 23,
  sym_comment_statement = 24,
  sym__statement = 25,
  sym_interpolation_statement = 26,
  sym_triple_statement = 27,
  sym_ampersand_statement = 28,
  sym_set_delimiter_statement = 29,
  sym_section = 30,
  sym__section_end = 31,
  sym_section_begin = 32,
  sym_inverted_section = 33,
  sym_inverted_section_begin = 34,
  sym__expression = 35,
  sym_identifier = 36,
  sym_path_expression = 37,
  aux_sym_template_repeat1 = 38,
  aux_sym_section_repeat1 = 39,
  aux_sym_path_expression_repeat1 = 40,
  alias_sym__end_delimiter = 41,
  alias_sym__start_delimiter = 42,
  alias_sym_inverted_section_end = 43,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_BANG] = "!",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_AMP] = "&",
  [anon_sym_EQ] = "=",
  [aux_sym_set_delimiter_statement_token1] = "set_delimiter_statement_token1",
  [anon_sym_SLASH] = "/",
  [anon_sym_POUND] = "#",
  [anon_sym_CARET] = "^",
  [anon_sym_DOT] = ".",
  [sym__start_tag_name] = "tag_name",
  [sym__end_tag_name] = "tag_name",
  [sym__erroneous_end_tag_name] = "erroneous_tag_name",
  [sym_start_delimiter] = "start_delimiter",
  [sym_end_delimiter] = "end_delimiter",
  [sym__comment_content] = "_comment_content",
  [sym__identifier_content] = "_identifier_content",
  [sym__setstart_delimiter_content] = "_setstart_delimiter_content",
  [sym__set_end_delimiter_content] = "_set_end_delimiter_content",
  [sym__old_end_delimiter] = "end_delimiter",
  [sym_text] = "text",
  [sym_template] = "template",
  [sym__declaration] = "_declaration",
  [sym_comment_statement] = "comment_statement",
  [sym__statement] = "_statement",
  [sym_interpolation_statement] = "interpolation_statement",
  [sym_triple_statement] = "triple_statement",
  [sym_ampersand_statement] = "ampersand_statement",
  [sym_set_delimiter_statement] = "set_delimiter_statement",
  [sym_section] = "section",
  [sym__section_end] = "section_end",
  [sym_section_begin] = "section_begin",
  [sym_inverted_section] = "inverted_section",
  [sym_inverted_section_begin] = "inverted_section_begin",
  [sym__expression] = "_expression",
  [sym_identifier] = "identifier",
  [sym_path_expression] = "path_expression",
  [aux_sym_template_repeat1] = "template_repeat1",
  [aux_sym_section_repeat1] = "section_repeat1",
  [aux_sym_path_expression_repeat1] = "path_expression_repeat1",
  [alias_sym__end_delimiter] = "_end_delimiter",
  [alias_sym__start_delimiter] = "_start_delimiter",
  [alias_sym_inverted_section_end] = "inverted_section_end",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_EQ] = anon_sym_EQ,
  [aux_sym_set_delimiter_statement_token1] = aux_sym_set_delimiter_statement_token1,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_DOT] = anon_sym_DOT,
  [sym__start_tag_name] = sym__start_tag_name,
  [sym__end_tag_name] = sym__start_tag_name,
  [sym__erroneous_end_tag_name] = sym__erroneous_end_tag_name,
  [sym_start_delimiter] = sym_start_delimiter,
  [sym_end_delimiter] = sym_end_delimiter,
  [sym__comment_content] = sym__comment_content,
  [sym__identifier_content] = sym__identifier_content,
  [sym__setstart_delimiter_content] = sym__setstart_delimiter_content,
  [sym__set_end_delimiter_content] = sym__set_end_delimiter_content,
  [sym__old_end_delimiter] = sym_end_delimiter,
  [sym_text] = sym_text,
  [sym_template] = sym_template,
  [sym__declaration] = sym__declaration,
  [sym_comment_statement] = sym_comment_statement,
  [sym__statement] = sym__statement,
  [sym_interpolation_statement] = sym_interpolation_statement,
  [sym_triple_statement] = sym_triple_statement,
  [sym_ampersand_statement] = sym_ampersand_statement,
  [sym_set_delimiter_statement] = sym_set_delimiter_statement,
  [sym_section] = sym_section,
  [sym__section_end] = sym__section_end,
  [sym_section_begin] = sym_section_begin,
  [sym_inverted_section] = sym_inverted_section,
  [sym_inverted_section_begin] = sym_inverted_section_begin,
  [sym__expression] = sym__expression,
  [sym_identifier] = sym_identifier,
  [sym_path_expression] = sym_path_expression,
  [aux_sym_template_repeat1] = aux_sym_template_repeat1,
  [aux_sym_section_repeat1] = aux_sym_section_repeat1,
  [aux_sym_path_expression_repeat1] = aux_sym_path_expression_repeat1,
  [alias_sym__end_delimiter] = alias_sym__end_delimiter,
  [alias_sym__start_delimiter] = alias_sym__start_delimiter,
  [alias_sym_inverted_section_end] = alias_sym_inverted_section_end,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_set_delimiter_statement_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [sym__start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__erroneous_end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_start_delimiter] = {
    .visible = true,
    .named = true,
  },
  [sym_end_delimiter] = {
    .visible = true,
    .named = true,
  },
  [sym__comment_content] = {
    .visible = false,
    .named = true,
  },
  [sym__identifier_content] = {
    .visible = false,
    .named = true,
  },
  [sym__setstart_delimiter_content] = {
    .visible = false,
    .named = true,
  },
  [sym__set_end_delimiter_content] = {
    .visible = false,
    .named = true,
  },
  [sym__old_end_delimiter] = {
    .visible = true,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_template] = {
    .visible = true,
    .named = true,
  },
  [sym__declaration] = {
    .visible = false,
    .named = true,
  },
  [sym_comment_statement] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_interpolation_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_triple_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_ampersand_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_set_delimiter_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_section] = {
    .visible = true,
    .named = true,
  },
  [sym__section_end] = {
    .visible = true,
    .named = true,
  },
  [sym_section_begin] = {
    .visible = true,
    .named = true,
  },
  [sym_inverted_section] = {
    .visible = true,
    .named = true,
  },
  [sym_inverted_section_begin] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_path_expression] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_template_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_section_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_path_expression_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym__end_delimiter] = {
    .visible = true,
    .named = true,
  },
  [alias_sym__start_delimiter] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_inverted_section_end] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [1] = alias_sym_inverted_section_end,
  },
  [2] = {
    [2] = alias_sym_inverted_section_end,
  },
  [3] = {
    [0] = alias_sym__start_delimiter,
    [3] = alias_sym__end_delimiter,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym__section_end, 2,
    sym__section_end,
    alias_sym_inverted_section_end,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 15,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 19,
  [29] = 27,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 35,
  [37] = 34,
  [38] = 30,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(1);
      ADVANCE_MAP(
        '!', 2,
        '#', 9,
        '&', 5,
        '.', 11,
        '/', 8,
        '=', 6,
        '^', 10,
        '{', 3,
        '}', 4,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(aux_sym_set_delimiter_statement_token1);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 0, .external_lex_state = 2},
  [5] = {.lex_state = 0, .external_lex_state = 2},
  [6] = {.lex_state = 0, .external_lex_state = 2},
  [7] = {.lex_state = 0, .external_lex_state = 2},
  [8] = {.lex_state = 0, .external_lex_state = 2},
  [9] = {.lex_state = 0, .external_lex_state = 3},
  [10] = {.lex_state = 0, .external_lex_state = 3},
  [11] = {.lex_state = 0, .external_lex_state = 3},
  [12] = {.lex_state = 0, .external_lex_state = 3},
  [13] = {.lex_state = 0, .external_lex_state = 3},
  [14] = {.lex_state = 0, .external_lex_state = 2},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0, .external_lex_state = 2},
  [17] = {.lex_state = 0, .external_lex_state = 2},
  [18] = {.lex_state = 0, .external_lex_state = 2},
  [19] = {.lex_state = 0, .external_lex_state = 4},
  [20] = {.lex_state = 0, .external_lex_state = 2},
  [21] = {.lex_state = 0, .external_lex_state = 2},
  [22] = {.lex_state = 0, .external_lex_state = 2},
  [23] = {.lex_state = 0, .external_lex_state = 2},
  [24] = {.lex_state = 0, .external_lex_state = 4},
  [25] = {.lex_state = 0, .external_lex_state = 2},
  [26] = {.lex_state = 0, .external_lex_state = 2},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0, .external_lex_state = 4},
  [30] = {.lex_state = 0, .external_lex_state = 4},
  [31] = {.lex_state = 0, .external_lex_state = 5},
  [32] = {.lex_state = 0, .external_lex_state = 2},
  [33] = {.lex_state = 0, .external_lex_state = 2},
  [34] = {.lex_state = 0, .external_lex_state = 4},
  [35] = {.lex_state = 0, .external_lex_state = 3},
  [36] = {.lex_state = 0, .external_lex_state = 3},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0, .external_lex_state = 6},
  [40] = {.lex_state = 0, .external_lex_state = 7},
  [41] = {.lex_state = 0, .external_lex_state = 4},
  [42] = {.lex_state = 0, .external_lex_state = 4},
  [43] = {.lex_state = 0, .external_lex_state = 4},
  [44] = {.lex_state = 0, .external_lex_state = 8},
  [45] = {.lex_state = 0, .external_lex_state = 9},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0, .external_lex_state = 4},
  [48] = {.lex_state = 0, .external_lex_state = 4},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0, .external_lex_state = 4},
  [52] = {.lex_state = 0, .external_lex_state = 6},
  [53] = {.lex_state = 0, .external_lex_state = 10},
  [54] = {.lex_state = 0, .external_lex_state = 4},
  [55] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [aux_sym_set_delimiter_statement_token1] = ACTIONS(3),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [sym__start_tag_name] = ACTIONS(1),
    [sym__end_tag_name] = ACTIONS(1),
    [sym__erroneous_end_tag_name] = ACTIONS(1),
    [sym_start_delimiter] = ACTIONS(1),
    [sym_end_delimiter] = ACTIONS(1),
    [sym__comment_content] = ACTIONS(1),
    [sym__identifier_content] = ACTIONS(1),
    [sym__setstart_delimiter_content] = ACTIONS(1),
    [sym__set_end_delimiter_content] = ACTIONS(1),
    [sym__old_end_delimiter] = ACTIONS(1),
    [sym_text] = ACTIONS(1),
  },
  [1] = {
    [sym_template] = STATE(50),
    [sym__declaration] = STATE(3),
    [sym_comment_statement] = STATE(3),
    [sym__statement] = STATE(3),
    [sym_interpolation_statement] = STATE(3),
    [sym_triple_statement] = STATE(3),
    [sym_ampersand_statement] = STATE(3),
    [sym_set_delimiter_statement] = STATE(3),
    [sym_section] = STATE(3),
    [sym_section_begin] = STATE(5),
    [sym_inverted_section] = STATE(3),
    [sym_inverted_section_begin] = STATE(4),
    [aux_sym_template_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [aux_sym_set_delimiter_statement_token1] = ACTIONS(3),
    [sym_start_delimiter] = ACTIONS(7),
    [sym_text] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      sym_start_delimiter,
    ACTIONS(16), 1,
      sym_text,
    STATE(4), 1,
      sym_inverted_section_begin,
    STATE(5), 1,
      sym_section_begin,
    STATE(2), 10,
      sym__declaration,
      sym_comment_statement,
      sym__statement,
      sym_interpolation_statement,
      sym_triple_statement,
      sym_ampersand_statement,
      sym_set_delimiter_statement,
      sym_section,
      sym_inverted_section,
      aux_sym_template_repeat1,
  [31] = 7,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(7), 1,
      sym_start_delimiter,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      sym_text,
    STATE(4), 1,
      sym_inverted_section_begin,
    STATE(5), 1,
      sym_section_begin,
    STATE(2), 10,
      sym__declaration,
      sym_comment_statement,
      sym__statement,
      sym_interpolation_statement,
      sym_triple_statement,
      sym_ampersand_statement,
      sym_set_delimiter_statement,
      sym_section,
      sym_inverted_section,
      aux_sym_template_repeat1,
  [62] = 7,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(23), 1,
      sym_start_delimiter,
    ACTIONS(25), 1,
      sym_text,
    STATE(4), 1,
      sym_inverted_section_begin,
    STATE(5), 1,
      sym_section_begin,
    STATE(17), 1,
      sym__section_end,
    STATE(7), 8,
      sym__statement,
      sym_interpolation_statement,
      sym_triple_statement,
      sym_ampersand_statement,
      sym_set_delimiter_statement,
      sym_section,
      sym_inverted_section,
      aux_sym_section_repeat1,
  [91] = 7,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(23), 1,
      sym_start_delimiter,
    ACTIONS(27), 1,
      sym_text,
    STATE(4), 1,
      sym_inverted_section_begin,
    STATE(5), 1,
      sym_section_begin,
    STATE(16), 1,
      sym__section_end,
    STATE(6), 8,
      sym__statement,
      sym_interpolation_statement,
      sym_triple_statement,
      sym_ampersand_statement,
      sym_set_delimiter_statement,
      sym_section,
      sym_inverted_section,
      aux_sym_section_repeat1,
  [120] = 7,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(23), 1,
      sym_start_delimiter,
    ACTIONS(29), 1,
      sym_text,
    STATE(4), 1,
      sym_inverted_section_begin,
    STATE(5), 1,
      sym_section_begin,
    STATE(20), 1,
      sym__section_end,
    STATE(8), 8,
      sym__statement,
      sym_interpolation_statement,
      sym_triple_statement,
      sym_ampersand_statement,
      sym_set_delimiter_statement,
      sym_section,
      sym_inverted_section,
      aux_sym_section_repeat1,
  [149] = 7,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(23), 1,
      sym_start_delimiter,
    ACTIONS(29), 1,
      sym_text,
    STATE(4), 1,
      sym_inverted_section_begin,
    STATE(5), 1,
      sym_section_begin,
    STATE(21), 1,
      sym__section_end,
    STATE(8), 8,
      sym__statement,
      sym_interpolation_statement,
      sym_triple_statement,
      sym_ampersand_statement,
      sym_set_delimiter_statement,
      sym_section,
      sym_inverted_section,
      aux_sym_section_repeat1,
  [178] = 6,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(31), 1,
      sym_start_delimiter,
    ACTIONS(34), 1,
      sym_text,
    STATE(4), 1,
      sym_inverted_section_begin,
    STATE(5), 1,
      sym_section_begin,
    STATE(8), 8,
      sym__statement,
      sym_interpolation_statement,
      sym_triple_statement,
      sym_ampersand_statement,
      sym_set_delimiter_statement,
      sym_section,
      sym_inverted_section,
      aux_sym_section_repeat1,
  [204] = 11,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(37), 1,
      anon_sym_BANG,
    ACTIONS(39), 1,
      anon_sym_LBRACE,
    ACTIONS(41), 1,
      anon_sym_AMP,
    ACTIONS(43), 1,
      anon_sym_EQ,
    ACTIONS(45), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(49), 1,
      anon_sym_DOT,
    ACTIONS(51), 1,
      sym__identifier_content,
    STATE(29), 1,
      sym_identifier,
    STATE(48), 2,
      sym__expression,
      sym_path_expression,
  [239] = 11,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(39), 1,
      anon_sym_LBRACE,
    ACTIONS(41), 1,
      anon_sym_AMP,
    ACTIONS(43), 1,
      anon_sym_EQ,
    ACTIONS(45), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(49), 1,
      anon_sym_DOT,
    ACTIONS(51), 1,
      sym__identifier_content,
    ACTIONS(53), 1,
      anon_sym_SLASH,
    STATE(29), 1,
      sym_identifier,
    STATE(48), 2,
      sym__expression,
      sym_path_expression,
  [274] = 10,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(39), 1,
      anon_sym_LBRACE,
    ACTIONS(41), 1,
      anon_sym_AMP,
    ACTIONS(43), 1,
      anon_sym_EQ,
    ACTIONS(45), 1,
      anon_sym_POUND,
    ACTIONS(47), 1,
      anon_sym_CARET,
    ACTIONS(49), 1,
      anon_sym_DOT,
    ACTIONS(51), 1,
      sym__identifier_content,
    STATE(29), 1,
      sym_identifier,
    STATE(48), 2,
      sym__expression,
      sym_path_expression,
  [306] = 5,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(51), 1,
      sym__identifier_content,
    ACTIONS(55), 1,
      anon_sym_DOT,
    STATE(29), 1,
      sym_identifier,
    STATE(43), 2,
      sym__expression,
      sym_path_expression,
  [323] = 5,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(57), 1,
      anon_sym_DOT,
    ACTIONS(59), 1,
      sym__identifier_content,
    STATE(27), 1,
      sym_identifier,
    STATE(46), 2,
      sym__expression,
      sym_path_expression,
  [340] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(61), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [349] = 4,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(63), 1,
      anon_sym_RBRACE,
    ACTIONS(65), 1,
      anon_sym_DOT,
    STATE(15), 1,
      aux_sym_path_expression_repeat1,
  [362] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(68), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [371] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(70), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [380] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(72), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [389] = 4,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(74), 1,
      anon_sym_DOT,
    ACTIONS(76), 1,
      sym_end_delimiter,
    STATE(24), 1,
      aux_sym_path_expression_repeat1,
  [402] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(78), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [411] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(80), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [420] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(82), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [429] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(84), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [438] = 4,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(63), 1,
      sym_end_delimiter,
    ACTIONS(86), 1,
      anon_sym_DOT,
    STATE(24), 1,
      aux_sym_path_expression_repeat1,
  [451] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(89), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [460] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(91), 3,
      sym_start_delimiter,
      sym_text,
      ts_builtin_sym_end,
  [469] = 4,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(93), 1,
      anon_sym_RBRACE,
    ACTIONS(95), 1,
      anon_sym_DOT,
    STATE(28), 1,
      aux_sym_path_expression_repeat1,
  [482] = 4,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(76), 1,
      anon_sym_RBRACE,
    ACTIONS(95), 1,
      anon_sym_DOT,
    STATE(15), 1,
      aux_sym_path_expression_repeat1,
  [495] = 4,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(74), 1,
      anon_sym_DOT,
    ACTIONS(93), 1,
      sym_end_delimiter,
    STATE(19), 1,
      aux_sym_path_expression_repeat1,
  [508] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(63), 2,
      sym_end_delimiter,
      anon_sym_DOT,
  [516] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(97), 2,
      sym__end_tag_name,
      sym__erroneous_end_tag_name,
  [524] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(99), 2,
      sym_start_delimiter,
      sym_text,
  [532] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(101), 2,
      sym_start_delimiter,
      sym_text,
  [540] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(103), 2,
      sym_end_delimiter,
      anon_sym_DOT,
  [548] = 3,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(51), 1,
      sym__identifier_content,
    STATE(30), 1,
      sym_identifier,
  [558] = 3,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(59), 1,
      sym__identifier_content,
    STATE(38), 1,
      sym_identifier,
  [568] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(103), 2,
      anon_sym_RBRACE,
      anon_sym_DOT,
  [576] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(63), 2,
      anon_sym_RBRACE,
      anon_sym_DOT,
  [584] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(105), 1,
      sym__start_tag_name,
  [591] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(107), 1,
      sym__comment_content,
  [598] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(109), 1,
      sym_end_delimiter,
  [605] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(111), 1,
      sym_end_delimiter,
  [612] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(113), 1,
      sym_end_delimiter,
  [619] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(115), 1,
      sym__setstart_delimiter_content,
  [626] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(117), 1,
      sym__set_end_delimiter_content,
  [633] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(119), 1,
      anon_sym_RBRACE,
  [640] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(121), 1,
      sym_end_delimiter,
  [647] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(123), 1,
      sym_end_delimiter,
  [654] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(125), 1,
      anon_sym_EQ,
  [661] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(127), 1,
      ts_builtin_sym_end,
  [668] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(129), 1,
      sym_end_delimiter,
  [675] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(131), 1,
      sym__start_tag_name,
  [682] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(133), 1,
      sym__old_end_delimiter,
  [689] = 2,
    ACTIONS(3), 1,
      aux_sym_set_delimiter_statement_token1,
    ACTIONS(135), 1,
      sym_end_delimiter,
  [696] = 1,
    ACTIONS(137), 1,
      aux_sym_set_delimiter_statement_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 31,
  [SMALL_STATE(4)] = 62,
  [SMALL_STATE(5)] = 91,
  [SMALL_STATE(6)] = 120,
  [SMALL_STATE(7)] = 149,
  [SMALL_STATE(8)] = 178,
  [SMALL_STATE(9)] = 204,
  [SMALL_STATE(10)] = 239,
  [SMALL_STATE(11)] = 274,
  [SMALL_STATE(12)] = 306,
  [SMALL_STATE(13)] = 323,
  [SMALL_STATE(14)] = 340,
  [SMALL_STATE(15)] = 349,
  [SMALL_STATE(16)] = 362,
  [SMALL_STATE(17)] = 371,
  [SMALL_STATE(18)] = 380,
  [SMALL_STATE(19)] = 389,
  [SMALL_STATE(20)] = 402,
  [SMALL_STATE(21)] = 411,
  [SMALL_STATE(22)] = 420,
  [SMALL_STATE(23)] = 429,
  [SMALL_STATE(24)] = 438,
  [SMALL_STATE(25)] = 451,
  [SMALL_STATE(26)] = 460,
  [SMALL_STATE(27)] = 469,
  [SMALL_STATE(28)] = 482,
  [SMALL_STATE(29)] = 495,
  [SMALL_STATE(30)] = 508,
  [SMALL_STATE(31)] = 516,
  [SMALL_STATE(32)] = 524,
  [SMALL_STATE(33)] = 532,
  [SMALL_STATE(34)] = 540,
  [SMALL_STATE(35)] = 548,
  [SMALL_STATE(36)] = 558,
  [SMALL_STATE(37)] = 568,
  [SMALL_STATE(38)] = 576,
  [SMALL_STATE(39)] = 584,
  [SMALL_STATE(40)] = 591,
  [SMALL_STATE(41)] = 598,
  [SMALL_STATE(42)] = 605,
  [SMALL_STATE(43)] = 612,
  [SMALL_STATE(44)] = 619,
  [SMALL_STATE(45)] = 626,
  [SMALL_STATE(46)] = 633,
  [SMALL_STATE(47)] = 640,
  [SMALL_STATE(48)] = 647,
  [SMALL_STATE(49)] = 654,
  [SMALL_STATE(50)] = 661,
  [SMALL_STATE(51)] = 668,
  [SMALL_STATE(52)] = 675,
  [SMALL_STATE(53)] = 682,
  [SMALL_STATE(54)] = 689,
  [SMALL_STATE(55)] = 696,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [16] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_set_delimiter_statement, 7, 0, 0),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_expression_repeat1, 2, 0, 0),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_expression_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 2, 0, 0),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inverted_section, 2, 0, 1),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interpolation_statement, 3, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path_expression, 2, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 3, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inverted_section, 3, 0, 2),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_statement, 4, 0, 3),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ampersand_statement, 4, 0, 0),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_expression_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_triple_statement, 5, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__section_end, 4, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_begin, 4, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inverted_section_begin, 4, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [127] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__start_tag_name = 0,
  ts_external_token__end_tag_name = 1,
  ts_external_token__erroneous_end_tag_name = 2,
  ts_external_token_start_delimiter = 3,
  ts_external_token_end_delimiter = 4,
  ts_external_token__comment_content = 5,
  ts_external_token__identifier_content = 6,
  ts_external_token__setstart_delimiter_content = 7,
  ts_external_token__set_end_delimiter_content = 8,
  ts_external_token__old_end_delimiter = 9,
  ts_external_token_text = 10,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__start_tag_name] = sym__start_tag_name,
  [ts_external_token__end_tag_name] = sym__end_tag_name,
  [ts_external_token__erroneous_end_tag_name] = sym__erroneous_end_tag_name,
  [ts_external_token_start_delimiter] = sym_start_delimiter,
  [ts_external_token_end_delimiter] = sym_end_delimiter,
  [ts_external_token__comment_content] = sym__comment_content,
  [ts_external_token__identifier_content] = sym__identifier_content,
  [ts_external_token__setstart_delimiter_content] = sym__setstart_delimiter_content,
  [ts_external_token__set_end_delimiter_content] = sym__set_end_delimiter_content,
  [ts_external_token__old_end_delimiter] = sym__old_end_delimiter,
  [ts_external_token_text] = sym_text,
};

static const bool ts_external_scanner_states[11][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__start_tag_name] = true,
    [ts_external_token__end_tag_name] = true,
    [ts_external_token__erroneous_end_tag_name] = true,
    [ts_external_token_start_delimiter] = true,
    [ts_external_token_end_delimiter] = true,
    [ts_external_token__comment_content] = true,
    [ts_external_token__identifier_content] = true,
    [ts_external_token__setstart_delimiter_content] = true,
    [ts_external_token__set_end_delimiter_content] = true,
    [ts_external_token__old_end_delimiter] = true,
    [ts_external_token_text] = true,
  },
  [2] = {
    [ts_external_token_start_delimiter] = true,
    [ts_external_token_text] = true,
  },
  [3] = {
    [ts_external_token__identifier_content] = true,
  },
  [4] = {
    [ts_external_token_end_delimiter] = true,
  },
  [5] = {
    [ts_external_token__end_tag_name] = true,
    [ts_external_token__erroneous_end_tag_name] = true,
  },
  [6] = {
    [ts_external_token__start_tag_name] = true,
  },
  [7] = {
    [ts_external_token__comment_content] = true,
  },
  [8] = {
    [ts_external_token__setstart_delimiter_content] = true,
  },
  [9] = {
    [ts_external_token__set_end_delimiter_content] = true,
  },
  [10] = {
    [ts_external_token__old_end_delimiter] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_mustache_external_scanner_create(void);
void tree_sitter_mustache_external_scanner_destroy(void *);
bool tree_sitter_mustache_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_mustache_external_scanner_serialize(void *, char *);
void tree_sitter_mustache_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_mustache(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_mustache_external_scanner_create,
      tree_sitter_mustache_external_scanner_destroy,
      tree_sitter_mustache_external_scanner_scan,
      tree_sitter_mustache_external_scanner_serialize,
      tree_sitter_mustache_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
