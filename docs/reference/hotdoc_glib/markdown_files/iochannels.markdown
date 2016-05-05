---
short-description: !!python/unicode 'portable support for using files, pipes and sockets'
symbols:
- g_io_channel_ref
- g_io_channel_unix_new
- g_io_channel_shutdown
- g_io_channel_write_unichar
- g_io_channel_read_line_string
- GSeekType
- g_io_channel_seek_position
- g_io_channel_read_line
- g_io_channel_close
- g_io_channel_new_file
- g_io_channel_error_from_errno
- g_io_channel_read
- GIOChannelError
- g_io_watch_funcs
- g_io_channel_error_quark
- g_io_channel_set_encoding
- g_io_channel_unref
- GIOFuncs
- g_io_channel_write_chars
- g_io_channel_set_buffer_size
- g_io_channel_read_to_end
- g_io_create_watch
- g_io_add_watch_full
- g_io_channel_get_line_term
- GIOFlags
- g_io_channel_set_line_term
- G_IO_FLAG_IS_WRITEABLE
- g_io_channel_set_flags
- G_IO_CHANNEL_ERROR
- g_io_channel_get_flags
- g_io_channel_set_buffered
- g_io_channel_seek
- g_io_channel_init
- g_io_channel_flush
- g_io_channel_get_buffered
- GIOCondition
- GIOError
- GIOFunc
- g_io_add_watch
- g_io_channel_read_unichar
- g_io_channel_read_chars
- GIOStatus
- g_io_channel_get_close_on_unref
- GIOChannel
- g_io_channel_get_buffer_condition
- g_io_channel_set_close_on_unref
- g_io_channel_unix_get_fd
- g_io_channel_write
- g_io_channel_get_encoding
- g_io_channel_get_buffer_size
title: !!python/unicode 'IO Channels'
...

The [](GIOChannel) data type aims to provide a portable method for
using file descriptors, pipes, and sockets, and integrating them
into the [main event loop][glib-The-Main-Event-Loop]. Currently,
full support is available on UNIX platforms, support for Windows
is only partially complete.

To create a new [](GIOChannel) on UNIX systems use
[](g_io_channel_unix_new). This works for plain file descriptors,
pipes and sockets. Alternatively, a channel can be created for a
file in a system independent manner using [](g_io_channel_new_file).

Once a [](GIOChannel) has been created, it can be used in a generic
manner with the functions [](g_io_channel_read_chars),
[](g_io_channel_write_chars), [](g_io_channel_seek_position), and
[](g_io_channel_shutdown).

To add a [](GIOChannel) to the [main event loop][glib-The-Main-Event-Loop],
use [](g_io_add_watch) or [](g_io_add_watch_full). Here you specify which
events you are interested in on the [](GIOChannel), and provide a
function to be called whenever these events occur.

[](GIOChannel) instances are created with an initial reference count of 1.
[](g_io_channel_ref) and [](g_io_channel_unref) can be used to
increment or decrement the reference count respectively. When the
reference count falls to 0, the [](GIOChannel) is freed. (Though it
isn't closed automatically, unless it was created using
[](g_io_channel_new_file).) Using [](g_io_add_watch) or
[](g_io_add_watch_full) increments a channel's reference count.

The new functions [](g_io_channel_read_chars),
[](g_io_channel_read_line), [](g_io_channel_read_line_string),
[](g_io_channel_read_to_end), [](g_io_channel_write_chars),
[](g_io_channel_seek_position), and [](g_io_channel_flush) should not be
mixed with the deprecated functions [](g_io_channel_read),
[](g_io_channel_write), and [](g_io_channel_seek) on the same channel.
