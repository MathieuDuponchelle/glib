### Strings

text buffers which grow automatically
     as text is added

 A [](GString) is an object that handles the memory management of a C
 string for you.  The emphasis of [](GString) is on text, typically
 UTF-8.  Crucially, the "str" member of a [](GString) is guaranteed to
 have a trailing nul character, and it is therefore always safe to
 call functions such as [](strchr) or [](g_strdup) on it.

 However, a [](GString) can also hold arbitrary binary data, because it
 has a "len" member, which includes any possible embedded nul
 characters in the data.  Conceptually then, [](GString) is like a
 [](GByteArray) with the addition of many convenience methods for text,
 and a guaranteed nul terminator.

* [GString]()
* [g_string_new]()
* [g_string_new_len]()
* [g_string_sized_new]()
* [g_string_assign]()
* [g_string_sprintf]()
* [g_string_sprintfa]()
* [g_string_vprintf]()
* [g_string_append_vprintf]()
* [g_string_printf]()
* [g_string_append_printf]()
* [g_string_append]()
* [g_string_append_c]()
* [g_string_append_unichar]()
* [g_string_append_len]()
* [g_string_append_uri_escaped]()
* [g_string_prepend]()
* [g_string_prepend_c]()
* [g_string_prepend_unichar]()
* [g_string_prepend_len]()
* [g_string_insert]()
* [g_string_insert_c]()
* [g_string_insert_unichar]()
* [g_string_insert_len]()
* [g_string_overwrite]()
* [g_string_overwrite_len]()
* [g_string_erase]()
* [g_string_truncate]()
* [g_string_set_size]()
* [g_string_free]()
* [g_string_free_to_bytes]()
* [g_string_up]()
* [g_string_down]()
* [g_string_hash]()
* [g_string_equal]()
* [g_string_append_c_inline]()
