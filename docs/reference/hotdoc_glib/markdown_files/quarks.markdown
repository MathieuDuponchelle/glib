---
short-description: !!python/unicode 'a 2-way association between a string and a     unique
  integer identifier'
symbols:
- GQuark
- g_quark_to_string
- g_quark_from_string
- g_quark_try_string
- g_intern_string
- g_quark_from_static_string
- g_intern_static_string
title: !!python/unicode 'Quarks'
...

Quarks are associations between strings and integer identifiers.
Given either the string or the [](GQuark) identifier it is possible to
retrieve the other.

Quarks are used for both [datasets][glib-Datasets] and
[keyed data lists][glib-Keyed-Data-Lists].

To create a new quark from a string, use [](g_quark_from_string) or
[](g_quark_from_static_string).

To find the string corresponding to a given [](GQuark), use
[](g_quark_to_string).

To find the [](GQuark) corresponding to a given string, use
[](g_quark_try_string).

Another use for the string pool maintained for the quark functions
is string interning, using [](g_intern_string) or
[](g_intern_static_string). An interned string is a canonical
representation for a string. One important advantage of interned
strings is that they can be compared for equality by a simple
pointer comparison, rather than using [](strcmp).
