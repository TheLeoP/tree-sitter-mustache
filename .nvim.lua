local ok, refactoring = pcall(require, "refactoring")
if not ok then return end

refactoring.setup {
  debug = {
    print_exp = {
      code_generation = {
        print_exp = {
          c = function(opts)
            return ([[lexer->log(lexer, "%s %s %s: %%s \n", %s);]]):format(
              opts.debug_path,
              opts.expression_str,
              opts.count,
              opts.expression
            )
          end,
        },
      },
    },
    print_var = {
      code_generation = {
        print_var = {
          c = function(opts)
            return ([[lexer->log(lexer, "%s %s %s: %%s", %s);]]):format(
              opts.debug_path,
              opts.identifier_str,
              opts.count,
              opts.identifier
            )
          end,
        },
      },
    },
    print_loc = {
      code_generation = {
        print_loc = {
          c = function(opts)
            return ([[lexer->log(lexer, "%s %s");]]):format(opts.debug_path, opts.count)
          end,
        },
      },
    },
  },
}
