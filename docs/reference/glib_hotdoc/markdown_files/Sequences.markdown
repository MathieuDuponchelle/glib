### Sequences

scalable lists

 The [](GSequence) data structure has the API of a list, but is
 implemented internally with a balanced binary tree. This means that
 it is possible to maintain a sorted list of n elements in time O(n log n).
 The data contained in each element can be either integer values, by using
 of the [Type Conversion Macros][glib-Type-Conversion-Macros], or simply
 pointers to any type of data.

 A [](GSequence) is accessed through "iterators", represented by a
 [](GSequenceIter). An iterator represents a position between two
 elements of the sequence. For example, the "begin" iterator
 represents the gap immediately before the first element of the
 sequence, and the "end" iterator represents the gap immediately
 after the last element. In an empty sequence, the begin and end
 iterators are the same.

 Some methods on [](GSequence) operate on ranges of items. For example
 [](g_sequence_foreach_range) will call a user-specified function on
 each element with the given range. The range is delimited by the
 gaps represented by the passed-in iterators, so if you pass in the
 begin and end iterators, the range in question is the entire
 sequence.

 The function [](g_sequence_get) is used with an iterator to access the
 element immediately following the gap that the iterator represents.
 The iterator is said to "point" to that element.

 Iterators are stable across most operations on a [](GSequence). For
 example an iterator pointing to some element of a sequence will
 continue to point to that element even after the sequence is sorted.
 Even moving an element to another sequence using for example
 [](g_sequence_move_range) will not invalidate the iterators pointing
 to it. The only operation that will invalidate an iterator is when
 the element it points to is removed from any sequence.

* [GSequence]()
* [GSequenceIter]()
* [GSequenceIterCompareFunc]()
* [g_sequence_new]()
* [g_sequence_free]()
* [g_sequence_get_length]()
* [g_sequence_foreach]()
* [g_sequence_foreach_range]()
* [g_sequence_sort]()
* [g_sequence_sort_iter]()
* [g_sequence_get_begin_iter]()
* [g_sequence_get_end_iter]()
* [g_sequence_get_iter_at_pos]()
* [g_sequence_append]()
* [g_sequence_prepend]()
* [g_sequence_insert_before]()
* [g_sequence_move]()
* [g_sequence_swap]()
* [g_sequence_insert_sorted]()
* [g_sequence_insert_sorted_iter]()
* [g_sequence_sort_changed]()
* [g_sequence_sort_changed_iter]()
* [g_sequence_remove]()
* [g_sequence_remove_range]()
* [g_sequence_move_range]()
* [g_sequence_search]()
* [g_sequence_search_iter]()
* [g_sequence_lookup]()
* [g_sequence_lookup_iter]()
* [g_sequence_get]()
* [g_sequence_set]()
* [g_sequence_iter_is_begin]()
* [g_sequence_iter_is_end]()
* [g_sequence_iter_next]()
* [g_sequence_iter_prev]()
* [g_sequence_iter_get_position]()
* [g_sequence_iter_move]()
* [g_sequence_iter_get_sequence]()
* [g_sequence_iter_compare]()
* [g_sequence_range_get_midpoint]()
