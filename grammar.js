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
    $.start_delimiter,
    $.end_delimiter,
    $._comment_content,
    $._identifier_content,
    $._setstart_delimiter_content,
    $._set_end_delimiter_content,
    $._old_end_delimiter,
    $.text,
  ],

  rules: {
    template: ($) => repeat($._declaration),
    _declaration: ($) => choice($.comment_statement, $._statement),
    comment_statement: ($) =>
      seq(
        alias($.start_delimiter, $._start_delimiter),
        "!",
        $._comment_content,
        alias($.end_delimiter, $._end_delimiter),
      ),

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
      seq($.start_delimiter, $._expression, $.end_delimiter),
    triple_statement: ($) =>
      seq($.start_delimiter, "{", $._expression, "}", $.end_delimiter),
    ampersand_statement: ($) =>
      seq($.start_delimiter, "&", $._expression, $.end_delimiter),
    set_delimiter_statement: ($) =>
      seq(
        $.start_delimiter,
        "=",
        $._setstart_delimiter_content,
        /\s/,
        $._set_end_delimiter_content,
        "=",
        alias($._old_end_delimiter, $.end_delimiter),
      ),

    section: ($) =>
      seq(
        $.section_begin,
        repeat($._statement),
        alias($._section_end, $.section_end),
      ),

    _section_end: ($) =>
      seq(
        $.start_delimiter,
        "/",
        choice(
          alias($._end_tag_name, $.tag_name),
          alias($._erroneous_end_tag_name, $.erroneous_tag_name),
        ),
        $.end_delimiter,
      ),

    section_begin: ($) =>
      seq(
        $.start_delimiter,
        "#",
        alias($._start_tag_name, $.tag_name),
        $.end_delimiter,
      ),

    inverted_section: ($) =>
      seq(
        $.inverted_section_begin,
        repeat($._statement),
        alias($._section_end, $.inverted_section_end),
      ),
    inverted_section_begin: ($) =>
      seq(
        $.start_delimiter,
        "^",
        alias($._start_tag_name, $.tag_name),
        $.end_delimiter,
      ),

    _expression: ($) => choice($.path_expression, $.identifier, "."),

    identifier: ($) => $._identifier_content,
    path_expression: ($) => seq($.identifier, repeat1(seq(".", $.identifier))),
  },
});
