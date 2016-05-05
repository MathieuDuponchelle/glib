---
short-description: !!python/unicode 'linked lists that can be iterated in one direction'
symbols:
- g_slist_concat
- g_slist_free
- g_slist_insert_sorted_with_data
- GSList
- g_slist_copy
- g_slist_insert_before
- g_slist_nth
- g_slist_free_full
- g_slist_position
- g_slist_free1
- g_slist_remove
- g_slist_insert
- g_slist_alloc
- g_slist_last
- g_slist_reverse
- g_slist_find_custom
- g_slist_sort
- g_slist_delete_link
- g_slist_length
- g_slist_free_1
- g_slist_insert_sorted
- g_slist_remove_all
- g_slist_sort_with_data
- g_slist_find
- g_slist_append
- g_slist_remove_link
- g_slist_copy_deep
- g_slist_prepend
- g_slist_index
- g_slist_next
- g_slist_nth_data
- g_slist_foreach
title: !!python/unicode 'Singly-Linked Lists'
...

The [](GSList) structure and its associated functions provide a
standard singly-linked list data structure.

Each element in the list contains a piece of data, together with a
pointer which links to the next element in the list. Using this
pointer it is possible to move through the list in one direction
only (unlike the [double-linked lists][glib-Doubly-Linked-Lists],
which allow movement in both directions).

The data contained in each element can be either integer values, by
using one of the [Type Conversion Macros][glib-Type-Conversion-Macros],
or simply pointers to any type of data.

List elements are allocated from the [slice allocator][glib-Memory-Slices],
which is more efficient than allocating elements individually.

Note that most of the [](GSList) functions expect to be passed a
pointer to the first element in the list. The functions which insert
elements return the new start of the list, which may have changed.

There is no function to create a [](GSList). [](NULL) is considered to be
the empty list so you simply set a [](GSList)* to [](NULL).

To add elements, use [](g_slist_append), [](g_slist_prepend),
[](g_slist_insert) and [](g_slist_insert_sorted).

To remove elements, use [](g_slist_remove).

To find elements in the list use [](g_slist_last), [](g_slist_next),
[](g_slist_nth), [](g_slist_nth_data), [](g_slist_find) and
[](g_slist_find_custom).

To find the index of an element use [](g_slist_position) and
[](g_slist_index).

To call a function for each element in the list use
[](g_slist_foreach).

To free the entire list, use [](g_slist_free).
