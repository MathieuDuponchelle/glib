---
short-description: !!python/unicode 'strongly typed value datatype'
symbols:
- g_variant_get_uint16
- g_variant_new_variant
- g_variant_get_child_value
- g_variant_take_ref
- g_variant_new_int16
- g_variant_iter_new
- g_variant_equal
- g_variant_new_object_path
- g_variant_builder_add_value
- GVariant
- g_variant_dict_lookup_value
- g_variant_new_va
- g_variant_dict_new
- g_variant_get_double
- g_variant_builder_end
- g_variant_new_dict_entry
- g_variant_get_data
- g_variant_ref
- g_variant_get_byte
- GVariantIter
- g_variant_dict_insert
- g_variant_dup_bytestring
- g_variant_new_uint16
- g_variant_ref_sink
- g_variant_iter_free
- g_variant_is_normal_form
- g_variant_get_type
- g_variant_new_from_bytes
- g_variant_new_objv
- g_variant_get_bytestring
- g_variant_get_fixed_array
- g_variant_iter_loop
- g_variant_classify
- g_variant_builder_init
- g_variant_is_signature
- g_variant_is_of_type
- g_variant_hash
- g_variant_is_object_path
- g_variant_get_va
- g_variant_new_array
- g_variant_get_uint32
- g_variant_iter_copy
- g_variant_lookup_value
- g_variant_get_child
- g_variant_dict_ref
- g_variant_new_take_string
- g_variant_new_int32
- g_variant_parser_get_error_quark
- g_variant_builder_close
- g_variant_unref
- GVariantBuilder
- GVariantClass
- g_variant_builder_new
- g_variant_byteswap
- g_variant_parse_error_print_context
- g_variant_new
- GVariantParseError
- g_variant_new_double
- g_variant_new_string
- g_variant_builder_add
- g_variant_get_bytestring_array
- GVariantDict
- g_variant_new_handle
- g_variant_new_bytestring
- g_variant_dup_bytestring_array
- g_variant_new_tuple
- g_variant_dup_objv
- g_variant_parse_error_quark
- g_variant_get_int32
- g_variant_dict_remove
- g_variant_dict_end
- g_variant_new_parsed
- g_variant_get_type_string
- g_variant_new_boolean
- g_variant_dict_lookup
- g_variant_iter_next_value
- g_variant_new_uint64
- g_variant_new_byte
- g_variant_get_normal_form
- g_variant_iter_init
- g_variant_compare
- g_variant_get_maybe
- g_variant_print
- g_variant_get_int16
- g_variant_new_bytestring_array
- g_variant_new_int64
- g_variant_check_format_string
- g_variant_print_string
- g_variant_new_printf
- g_variant_get_string
- g_variant_get_size
- g_variant_new_from_data
- g_variant_new_maybe
- g_variant_is_container
- g_variant_builder_open
- g_variant_iter_n_children
- g_variant_get_int64
- g_variant_store
- g_variant_get_data_as_bytes
- g_variant_is_floating
- g_variant_new_parsed_va
- g_variant_dict_contains
- g_variant_get
- g_variant_dict_insert_value
- g_variant_get_handle
- g_variant_builder_ref
- g_variant_dup_string
- g_variant_parse
- g_variant_n_children
- g_variant_dup_strv
- g_variant_dict_clear
- g_variant_get_variant
- g_variant_builder_clear
- g_variant_get_uint64
- g_variant_builder_unref
- g_variant_new_fixed_array
- g_variant_get_objv
- g_variant_iter_next
- g_variant_new_uint32
- g_variant_dict_unref
- g_variant_lookup
- g_variant_new_signature
- g_variant_dict_init
- g_variant_get_strv
- g_variant_builder_add_parsed
- g_variant_get_boolean
- g_variant_type_checked_
- g_variant_new_strv
title: !!python/unicode 'GVariant'
...

[](GVariant) is a variant datatype; it can contain one or more values
along with information about the type of the values.

A [](GVariant) may contain simple types, like an integer, or a boolean value;
or complex types, like an array of two strings, or a dictionary of key
value pairs. A [](GVariant) is also immutable: once it's been created neither
its type nor its content can be modified further.

GVariant is useful whenever data needs to be serialized, for example when
sending method parameters in DBus, or when saving settings using GSettings.

When creating a new [](GVariant), you pass the data you want to store in it
along with a string representing the type of data you wish to pass to it.

For instance, if you want to create a [](GVariant) holding an integer value you
can use:


```
&lt;!-- language="C" --&gt;
GVariant *v = g_variant_new ('u', 40);

```


The string 'u' in the first argument tells [](GVariant) that the data passed to
the constructor (40) is going to be an unsigned integer.

More advanced examples of [](GVariant) in use can be found in documentation for
[GVariant format strings][gvariant-format-strings-pointers].

The range of possible values is determined by the type.

The type system used by [](GVariant) is [](GVariantType).

[](GVariant) instances always have a type and a value (which are given
at construction time).  The type and value of a [](GVariant) instance
can never change other than by the [](GVariant) itself being
destroyed.  A [](GVariant) cannot contain a pointer.

[](GVariant) is reference counted using [](g_variant_ref) and
[](g_variant_unref).  [](GVariant) also has floating reference counts --
see [](g_variant_ref_sink).

[](GVariant) is completely threadsafe.  A [](GVariant) instance can be
concurrently accessed in any way from any number of threads without
problems.

[](GVariant) is heavily optimised for dealing with data in serialised
form.  It works particularly well with data located in memory-mapped
files.  It can perform nearly all deserialisation operations in a
small constant time, usually touching only a single memory page.
Serialised [](GVariant) data can also be sent over the network.

[](GVariant) is largely compatible with D-Bus.  Almost all types of
[](GVariant) instances can be sent over D-Bus.  See [](GVariantType) for
exceptions.  (However, [](GVariant)'s serialisation format is not the same
as the serialisation format of a D-Bus message body: use [](GDBusMessage),
in the gio library, for those.)

For space-efficiency, the [](GVariant) serialisation format does not
automatically include the variant's length, type or endianness,
which must either be implied from context (such as knowledge that a
particular file format always contains a little-endian
[](G_VARIANT_TYPE_VARIANT) which occupies the whole length of the file)
or supplied out-of-band (for instance, a length, type and/or endianness
indicator could be placed at the beginning of a file, network message
or network stream).

A [](GVariant)'s size is limited mainly by any lower level operating
system constraints, such as the number of bits in [](gsize).  For
example, it is reasonable to have a 2GB file mapped into memory
with [](GMappedFile), and call [](g_variant_new_from_data) on it.

For convenience to C programmers, [](GVariant) features powerful
varargs-based value construction and destruction.  This feature is
designed to be embedded in other libraries.

There is a Python-inspired text language for describing [](GVariant)
values.  [](GVariant) includes a printer for this language and a parser
with type inferencing.

## Memory Use

[](GVariant) tries to be quite efficient with respect to memory use.
This section gives a rough idea of how much memory is used by the
current implementation.  The information here is subject to change
in the future.

The memory allocated by [](GVariant) can be grouped into 4 broad
purposes: memory for serialised data, memory for the type
information cache, buffer management memory and memory for the
[](GVariant) structure itself.

## Serialised Data Memory

This is the memory that is used for storing GVariant data in
serialised form.  This is what would be sent over the network or
what would end up on disk, not counting any indicator of the
endianness, or of the length or type of the top-level variant.

The amount of memory required to store a boolean is 1 byte. 16,
32 and 64 bit integers and double precision floating point numbers
use their "natural" size.  Strings (including object path and
signature strings) are stored with a nul terminator, and as such
use the length of the string plus 1 byte.

Maybe types use no space at all to represent the null value and
use the same amount of space (sometimes plus one byte) as the
equivalent non-maybe-typed value to represent the non-null case.

Arrays use the amount of space required to store each of their
members, concatenated.  Additionally, if the items stored in an
array are not of a fixed-size (ie: strings, other arrays, etc)
then an additional framing offset is stored for each item.  The
size of this offset is either 1, 2 or 4 bytes depending on the
overall size of the container.  Additionally, extra padding bytes
are added as required for alignment of child values.

Tuples (including dictionary entries) use the amount of space
required to store each of their members, concatenated, plus one
framing offset (as per arrays) for each non-fixed-sized item in
the tuple, except for the last one.  Additionally, extra padding
bytes are added as required for alignment of child values.

Variants use the same amount of space as the item inside of the
variant, plus 1 byte, plus the length of the type string for the
item inside the variant.

As an example, consider a dictionary mapping strings to variants.
In the case that the dictionary is empty, 0 bytes are required for
the serialisation.

If we add an item "width" that maps to the int32 value of 500 then
we will use 4 byte to store the int32 (so 6 for the variant
containing it) and 6 bytes for the string.  The variant must be
aligned to 8 after the 6 bytes of the string, so that's 2 extra
bytes.  6 (string) + 2 (padding) + 6 (variant) is 14 bytes used
for the dictionary entry.  An additional 1 byte is added to the
array as a framing offset making a total of 15 bytes.

If we add another entry, "title" that maps to a nullable string
that happens to have a value of null, then we use 0 bytes for the
null value (and 3 bytes for the variant to contain it along with
its type string) plus 6 bytes for the string.  Again, we need 2
padding bytes.  That makes a total of 6 + 2 + 3 = 11 bytes.

We now require extra padding between the two items in the array.
After the 14 bytes of the first item, that's 2 bytes required.
We now require 2 framing offsets for an extra two
bytes. 14 + 2 + 11 + 2 = 29 bytes to encode the entire two-item
dictionary.

## Type Information Cache

For each GVariant type that currently exists in the program a type
information structure is kept in the type information cache.  The
type information structure is required for rapid deserialisation.

Continuing with the above example, if a [](GVariant) exists with the
type "a{sv}" then a type information struct will exist for
"a{sv}", "{sv}", "s", and "v".  Multiple uses of the same type
will share the same type information.  Additionally, all
single-digit types are stored in read-only static memory and do
not contribute to the writable memory footprint of a program using
[](GVariant).

Aside from the type information structures stored in read-only
memory, there are two forms of type information.  One is used for
container types where there is a single element type: arrays and
maybe types.  The other is used for container types where there
are multiple element types: tuples and dictionary entries.

Array type info structures are 6 * sizeof (void *), plus the
memory required to store the type string itself.  This means that
on 32-bit systems, the cache entry for "a{sv}" would require 30
bytes of memory (plus malloc overhead).

Tuple type info structures are 6 * sizeof (void *), plus 4 *
sizeof (void *) for each item in the tuple, plus the memory
required to store the type string itself.  A 2-item tuple, for
example, would have a type information structure that consumed
writable memory in the size of 14 * sizeof (void *) (plus type
string)  This means that on 32-bit systems, the cache entry for
"{sv}" would require 61 bytes of memory (plus malloc overhead).

This means that in total, for our "a{sv}" example, 91 bytes of
type information would be allocated.

The type information cache, additionally, uses a [](GHashTable) to
store and lookup the cached items and stores a pointer to this
hash table in static storage.  The hash table is freed when there
are zero items in the type cache.

Although these sizes may seem large it is important to remember
that a program will probably only have a very small number of
different types of values in it and that only one type information
structure is required for many different values of the same type.

## Buffer Management Memory

[](GVariant) uses an internal buffer management structure to deal
with the various different possible sources of serialised data
that it uses.  The buffer is responsible for ensuring that the
correct call is made when the data is no longer in use by
[](GVariant).  This may involve a [](g_free) or a [](g_slice_free) or
even [](g_mapped_file_unref).

One buffer management structure is used for each chunk of
serialised data.  The size of the buffer management structure
is 4 * (void *).  On 32-bit systems, that's 16 bytes.

## GVariant structure

The size of a [](GVariant) structure is 6 * (void *).  On 32-bit
systems, that's 24 bytes.

[](GVariant) structures only exist if they are explicitly created
with API calls.  For example, if a [](GVariant) is constructed out of
serialised data for the example given above (with the dictionary)
then although there are 9 individual values that comprise the
entire dictionary (two keys, two values, two variants containing
the values, two dictionary entries, plus the dictionary itself),
only 1 [](GVariant) instance exists -- the one referring to the
dictionary.

If calls are made to start accessing the other values then
[](GVariant) instances will exist for those values only for as long
as they are in use (ie: until you call [](g_variant_unref)).  The
type information is shared.  The serialised data and the buffer
management structure for that serialised data is shared by the
child.

## Summary

To put the entire example together, for our dictionary mapping
strings to variants (with two entries, as given above), we are
using 91 bytes of memory for type information, 29 byes of memory
for the serialised data, 16 bytes for buffer management and 24
bytes for the [](GVariant) instance, or a total of 160 bytes, plus
malloc overhead.  If we were to use [](g_variant_get_child_value) to
access the two dictionary entries, we would use an additional 48
bytes.  If we were to have other dictionaries of the same type, we
would use more memory for the serialised data and buffer
management for those dictionaries, but the type information would
be shared.
