---
short-description: !!python/unicode 'support for automatic completion using a group                     of
  target strings'
symbols:
- GCompletion
- g_completion_new
- GCompletionFunc
- g_completion_add_items
- g_completion_free
- g_completion_set_compare
- GCompletionStrncmpFunc
- g_completion_remove_items
- g_completion_complete_utf8
- g_completion_complete
- g_completion_clear_items
title: !!python/unicode 'Automatic String Completion'
...

[](GCompletion) provides support for automatic completion of a string
using any group of target strings. It is typically used for file
name completion as is common in many UNIX shells.

A [](GCompletion) is created using [](g_completion_new). Target items are
added and removed with [](g_completion_add_items),
[](g_completion_remove_items) and [](g_completion_clear_items). A
completion attempt is requested with [](g_completion_complete) or
[](g_completion_complete_utf8). When no longer needed, the
[](GCompletion) is freed with [](g_completion_free).

Items in the completion can be simple strings (e.g. filenames), or
pointers to arbitrary data structures. If data structures are used
you must provide a [](GCompletionFunc) in [](g_completion_new), which
retrieves the item's string from the data structure. You can change
the way in which strings are compared by setting a different
[](GCompletionStrncmpFunc) in [](g_completion_set_compare).

GCompletion has been marked as deprecated, since this API is rarely
used and not very actively maintained.
