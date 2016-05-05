---
short-description: !!python/unicode 'shell-like commandline handling'
symbols:
- g_shell_unquote
- g_shell_parse_argv
- g_shell_quote
- GShellError
- G_SHELL_ERROR
- g_shell_error_quark
title: !!python/unicode 'Shell-related Utilities'
...

GLib provides the functions [](g_shell_quote) and [](g_shell_unquote)
to handle shell-like quoting in strings. The function [](g_shell_parse_argv)
parses a string similar to the way a POSIX shell (/bin/sh) would.

Note that string handling in shells has many obscure and historical
corner-cases which these functions do not necessarily reproduce. They
are good enough in practice, though.
