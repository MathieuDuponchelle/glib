---
short-description: !!python/unicode 'associations between keys and values so that     given
  a key the value can be found quickly'
symbols:
- g_hash_table_contains
- g_hash_table_steal_all
- g_str_hash
- g_double_hash
- g_hash_table_get_keys_as_array
- g_int_hash
- g_hash_table_replace
- g_hash_table_lookup
- GHFunc
- GHashTable
- g_hash_table_new
- g_hash_table_lookup_extended
- g_hash_table_iter_remove
- g_hash_table_find
- g_double_equal
- g_hash_table_iter_replace
- g_hash_table_freeze
- g_str_equal
- g_int64_equal
- g_hash_table_get_values
- g_hash_table_iter_get_hash_table
- g_hash_table_destroy
- g_int64_hash
- g_hash_table_add
- g_hash_table_new_full
- g_hash_table_foreach_steal
- GHRFunc
- GHashFunc
- g_hash_table_iter_next
- g_hash_table_iter_steal
- g_direct_equal
- g_hash_table_size
- g_hash_table_insert
- g_hash_table_get_keys
- GHashTableIter
- g_hash_table_unref
- g_int_equal
- GEqualFunc
- g_hash_table_foreach_remove
- g_hash_table_thaw
- g_hash_table_remove_all
- g_hash_table_foreach
- g_hash_table_remove
- g_hash_table_iter_init
- g_direct_hash
- g_hash_table_ref
- g_hash_table_steal
title: !!python/unicode 'Hash Tables'
...

A [](GHashTable) provides associations between keys and values which is
optimized so that given a key, the associated value can be found
very quickly.

Note that neither keys nor values are copied when inserted into the
[](GHashTable), so they must exist for the lifetime of the [](GHashTable).
This means that the use of static strings is OK, but temporary
strings (i.e. those created in buffers and those returned by GTK+
widgets) should be copied with [](g_strdup) before being inserted.

If keys or values are dynamically allocated, you must be careful to
ensure that they are freed when they are removed from the
[](GHashTable), and also when they are overwritten by new insertions
into the [](GHashTable). It is also not advisable to mix static strings
and dynamically-allocated strings in a [](GHashTable), because it then
becomes difficult to determine whether the string should be freed.

To create a [](GHashTable), use [](g_hash_table_new).

To insert a key and value into a [](GHashTable), use
[](g_hash_table_insert).

To lookup a value corresponding to a given key, use
[](g_hash_table_lookup) and [](g_hash_table_lookup_extended).

[](g_hash_table_lookup_extended) can also be used to simply
check if a key is present in the hash table.

To remove a key and value, use [](g_hash_table_remove).

To call a function for each key and value pair use
[](g_hash_table_foreach) or use a iterator to iterate over the
key/value pairs in the hash table, see [](GHashTableIter).

To destroy a [](GHashTable) use [](g_hash_table_destroy).

A common use-case for hash tables is to store information about a
set of keys, without associating any particular value with each
key. GHashTable optimizes one way of doing so: If you store only
key-value pairs where key == value, then GHashTable does not
allocate memory to store the values, which can be a considerable
space saving, if your set is large. The functions
[](g_hash_table_add) and [](g_hash_table_contains) are designed to be
used when using [](GHashTable) this way.
