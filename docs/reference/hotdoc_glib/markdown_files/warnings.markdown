---
short-description: !!python/unicode 'functions to output messages and help debug applications'
symbols:
- GPrintFunc
- g_warn_if_fail
- g_return_if_fail_warning
- g_on_error_stack_trace
- g_printerr
- G_BREAKPOINT
- g_set_print_handler
- g_warn_if_reached
- g_print
- g_return_val_if_fail
- g_assert_warning
- g_return_if_reached
- g_set_printerr_handler
- g_return_val_if_reached
- g_on_error_query
- g_return_if_fail
- g_warn_message
title: !!python/unicode 'Message Output and Debugging Functions'
...

These functions provide support for outputting messages.

The g_return family of macros ([](g_return_if_fail),
[](g_return_val_if_fail), [](g_return_if_reached),
[](g_return_val_if_reached)) should only be used for programming
errors, a typical use case is checking for invalid parameters at
the beginning of a public function. They should not be used if
you just mean "if (error) return", they should only be used if
you mean "if (bug in program) return". The program behavior is
generally considered undefined after one of these checks fails.
They are not intended for normal control flow, only to give a
perhaps-helpful warning before giving up.
