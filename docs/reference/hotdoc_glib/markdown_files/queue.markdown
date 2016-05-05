---
short-description: !!python/unicode 'double-ended queue data structure'
symbols:
- g_queue_pop_head_link
- g_queue_peek_head_link
- g_queue_push_tail
- g_queue_insert_before
- g_queue_insert_sorted
- g_queue_delete_link
- g_queue_is_empty
- g_queue_clear
- g_queue_pop_head
- g_queue_index
- g_queue_peek_head
- G_QUEUE_INIT
- g_queue_push_nth_link
- g_queue_remove_all
- g_queue_peek_tail
- g_queue_foreach
- g_queue_remove
- g_queue_push_head
- g_queue_copy
- g_queue_sort
- g_queue_get_length
- GQueue
- g_queue_pop_tail
- g_queue_push_nth
- g_queue_insert_after
- g_queue_peek_nth
- g_queue_new
- g_queue_peek_tail_link
- g_queue_free
- g_queue_reverse
- g_queue_push_head_link
- g_queue_pop_nth
- g_queue_find_custom
- g_queue_free_full
- g_queue_pop_tail_link
- g_queue_pop_nth_link
- g_queue_peek_nth_link
- g_queue_init
- g_queue_link_index
- g_queue_unlink
- g_queue_find
- g_queue_push_tail_link
title: !!python/unicode 'Double-ended Queues'
...

The [](GQueue) structure and its associated functions provide a standard
queue data structure. Internally, GQueue uses the same data structure
as [](GList) to store elements.

The data contained in each element can be either integer values, by
using one of the [Type Conversion Macros][glib-Type-Conversion-Macros],
or simply pointers to any type of data.

To create a new GQueue, use [](g_queue_new).

To initialize a statically-allocated GQueue, use [](G_QUEUE_INIT) or
[](g_queue_init).

To add elements, use [](g_queue_push_head), [](g_queue_push_head_link),
[](g_queue_push_tail) and [](g_queue_push_tail_link).

To remove elements, use [](g_queue_pop_head) and [](g_queue_pop_tail).

To free the entire queue, use [](g_queue_free).
