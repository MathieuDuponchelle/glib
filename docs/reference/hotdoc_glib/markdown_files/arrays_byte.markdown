---
short-description: !!python/unicode 'arrays of bytes'
symbols:
- g_byte_array_set_size
- g_byte_array_sort_with_data
- g_bytes_hash
- g_byte_array_unref
- g_bytes_ref
- g_bytes_new_take
- g_byte_array_append
- g_bytes_new_with_free_func
- g_bytes_new_static
- g_byte_array_sized_new
- g_bytes_equal
- g_bytes_unref_to_array
- g_byte_array_free
- g_byte_array_new_take
- g_bytes_compare
- g_byte_array_remove_index
- g_byte_array_remove_range
- g_byte_array_prepend
- g_byte_array_free_to_bytes
- g_byte_array_remove_index_fast
- g_bytes_get_data
- g_bytes_unref_to_data
- g_bytes_unref
- g_byte_array_new
- GBytes
- g_byte_array_ref
- g_bytes_new
- g_byte_array_sort
- g_bytes_new_from_bytes
- g_bytes_get_size
- GByteArray
title: !!python/unicode 'Byte Arrays'
...

[](GByteArray) is a mutable array of bytes based on [](GArray), to provide arrays
of bytes which grow automatically as elements are added.

To create a new [](GByteArray) use [](g_byte_array_new). To add elements to a
[](GByteArray), use [](g_byte_array_append), and [](g_byte_array_prepend).

To set the size of a [](GByteArray), use [](g_byte_array_set_size).

To free a [](GByteArray), use [](g_byte_array_free).

An example for using a [](GByteArray):

```
&lt;!-- language="C" --&gt;
GByteArray *gbarray;
gint i;

gbarray = g_byte_array_new ();
for (i = 0; i &lt; 10000; i++)
g_byte_array_append (gbarray, (guint8*) "abcd", 4);

for (i = 0; i &lt; 10000; i++)
{
g_assert (gbarray-&gt;data[4*i] == 'a');
g_assert (gbarray-&gt;data[4*i+1] == 'b');
g_assert (gbarray-&gt;data[4*i+2] == 'c');
g_assert (gbarray-&gt;data[4*i+3] == 'd');
}

g_byte_array_free (gbarray, TRUE);

```


See [](GBytes) if you are interested in an immutable object representing a
sequence of bytes.
