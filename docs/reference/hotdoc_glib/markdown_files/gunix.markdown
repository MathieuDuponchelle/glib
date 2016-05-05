---
short-description: !!python/unicode 'pipes, signal handling'
symbols:
- g_unix_fd_add
- g_unix_signal_add_full
- g_unix_signal_add
- g_unix_error_quark
- g_unix_fd_add_full
- g_unix_signal_source_new
- g_unix_fd_source_new
- G_UNIX_ERROR
- g_unix_set_fd_nonblocking
- g_unix_open_pipe
- GUnixFDSourceFunc
title: !!python/unicode 'UNIX-specific utilities and integration'
...

Most of GLib is intended to be portable; in contrast, this set of
functions is designed for programs which explicitly target UNIX,
or are using it to build higher level abstractions which would be
conditionally compiled if the platform matches G_OS_UNIX.

To use these functions, you must explicitly include the
"glib-unix.h" header.
