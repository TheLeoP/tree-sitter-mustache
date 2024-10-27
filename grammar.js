/**
 * @file Mustache grammar for tree-sitter
 * @author Luis Calle <eugenio0523@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "mustache",

  externals: ($) => [
    $._start_tag_name,
    $._end_tag_name,
    $._erroneous_end_tag_name,
    $._start_delimiter,
    $._end_delimiter,
    $._comment_content,
    $._identifier_content,
    $._set_start_delimiter_content,
    $._set_end_delimiter_content,
    $._old_end_delimiter,
    $.text,
  ],

  rules: {
    template: ($) => repeat($._declaration),
    _declaration: ($) => choice($.comment_statement, $._statement),
    comment_statement: ($) =>
      seq($._start_delimiter, "!", $._comment_content, $._end_delimiter),

    _statement: ($) =>
      choice(
        $.triple_statement,
        $.ampersand_statement,
        $.section,
        $.inverted_section,
        $.interpolation_statement,
        $.set_delimiter_statement,
        $.text,
      ),
    interpolation_statement: ($) =>
      seq($._start_delimiter, $._expression, $._end_delimiter),
    triple_statement: ($) =>
      seq($._start_delimiter, "{", $._expression, "}", $._end_delimiter),
    ampersand_statement: ($) =>
      seq($._start_delimiter, "&", $._expression, $._end_delimiter),
    set_delimiter_statement: ($) =>
      seq(
        $._start_delimiter,
        "=",
        $._set_start_delimiter_content,
        /\s/,
        $._set_end_delimiter_content,
        "=",
        $._old_end_delimiter,
      ),

    section: ($) =>
      seq(
        $.section_begin,
        repeat($._statement),
        alias($._section_end, $.section_end),
      ),

    _section_end: ($) =>
      seq(
        $._start_delimiter,
        "/",
        choice(
          alias($._end_tag_name, $.tag_name),
          alias($._erroneous_end_tag_name, $.erroneous_tag_name),
        ),
        $._end_delimiter,
      ),

    section_begin: ($) =>
      seq(
        $._start_delimiter,
        "#",
        alias($._start_tag_name, $.tag_name),
        $._end_delimiter,
      ),

    inverted_section: ($) =>
      seq(
        $.inverted_section_begin,
        repeat($._statement),
        alias($._section_end, $.inverted_section_end),
      ),
    inverted_section_begin: ($) =>
      seq(
        $._start_delimiter,
        "^",
        alias($._start_tag_name, $.tag_name),
        $._end_delimiter,
      ),

    _expression: ($) => choice($.path_expression, $.identifier, "."),

    identifier: ($) => $._identifier_content,
    path_expression: ($) => seq($.identifier, repeat1(seq(".", $.identifier))),
  },
});
