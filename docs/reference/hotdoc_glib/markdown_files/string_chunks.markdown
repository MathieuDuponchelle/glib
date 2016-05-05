---
short-description: !!python/unicode 'efficient storage of groups of strings'
symbols:
- g_string_chunk_clear
- GStringChunk
- g_string_chunk_insert_len
- g_string_chunk_insert_const
- g_string_chunk_free
- g_string_chunk_new
- g_string_chunk_insert
title: !!python/unicode 'String Chunks'
...

String chunks are used to store groups of strings. Memory is
allocated in blocks, and as strings are added to the [](GStringChunk)
they are copied into the next free position in a block. When a block
is full a new block is allocated.

When storing a large number of strings, string chunks are more
efficient than using [](g_strdup) since fewer calls to [](malloc) are
needed, and less memory is wasted in memory allocation overheads.

By adding strings with [](g_string_chunk_insert_const) it is also
possible to remove duplicates.

To create a new [](GStringChunk) use [](g_string_chunk_new).

To add strings to a [](GStringChunk) use [](g_string_chunk_insert).

To add strings to a [](GStringChunk), but without duplicating strings
which are already in the [](GStringChunk), use
[](g_string_chunk_insert_const).

To free the entire [](GStringChunk) use [](g_string_chunk_free). It is
not possible to free individual strings.
