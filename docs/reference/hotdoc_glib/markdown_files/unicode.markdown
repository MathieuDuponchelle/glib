---
short-description: !!python/unicode 'functions operating on Unicode characters and     UTF-8
  strings'
symbols:
- G_UNICODE_COMBINING_MARK
- g_utf16_to_utf8
- g_unichar_isxdigit
- g_unichar_isdigit
- g_ucs4_to_utf16
- g_utf8_get_char
- g_unichar_to_utf8
- g_unicode_script_to_iso15924
- gunichar2
- g_utf8_strup
- g_utf8_to_ucs4_fast
- g_unichar_islower
- g_ucs4_to_utf8
- g_utf8_collate
- g_utf8_pointer_to_offset
- g_unichar_xdigit_value
- g_utf8_prev_char
- g_utf8_strlen
- g_unicode_canonical_ordering
- GUnicodeBreakType
- g_utf8_to_utf16
- g_unichar_isalnum
- GNormalizeMode
- g_utf8_next_char
- g_unichar_get_script
- g_unichar_fully_decompose
- g_utf8_collate_key_for_filename
- g_utf8_strncpy
- gunichar
- g_unichar_isdefined
- g_utf16_to_ucs4
- g_unichar_toupper
- g_unichar_combining_class
- g_unichar_isupper
- g_unichar_tolower
- g_utf8_strrchr
- g_utf8_casefold
- g_unichar_type
- g_utf8_validate
- g_utf8_strdown
- g_utf8_strreverse
- g_utf8_offset_to_pointer
- g_unichar_decompose
- GUnicodeScript
- G_UNICHAR_MAX_DECOMPOSITION_LENGTH
- g_utf8_strchr
- g_unichar_iszerowidth
- g_unicode_script_from_iso15924
- GUnicodeType
- g_unicode_canonical_decomposition
- g_utf8_get_char_validated
- g_utf8_collate_key
- g_utf8_substring
- g_unichar_compose
- g_unichar_iswide
- g_utf8_find_next_char
- g_unichar_get_mirror_char
- g_unichar_iswide_cjk
- g_unichar_isspace
- g_utf8_to_ucs4
- g_utf8_skip
- g_unichar_isprint
- g_unichar_validate
- g_unichar_isgraph
- g_unichar_digit_value
- g_unichar_ismark
- g_unichar_istitle
- g_unichar_iscntrl
- g_utf8_normalize
- g_unichar_totitle
- g_unichar_isalpha
- g_unichar_break_type
- g_unichar_ispunct
- g_utf8_find_prev_char
title: !!python/unicode 'Unicode Manipulation'
...

This section describes a number of functions for dealing with
Unicode characters and strings. There are analogues of the
traditional `ctype.h` character classification and case conversion
functions, UTF-8 analogues of some string utility functions,
functions to perform normalization, case conversion and collation
on UTF-8 strings and finally functions to convert between the UTF-8,
UTF-16 and UCS-4 encodings of Unicode.

The implementations of the Unicode functions in GLib are based
on the Unicode Character Data tables, which are available from
[www.unicode.org](http://www.unicode.org/).
GLib 2.8 supports Unicode 4.0, GLib 2.10 supports Unicode 4.1,
GLib 2.12 supports Unicode 5.0, GLib 2.16.3 supports Unicode 5.1,
GLib 2.30 supports Unicode 6.0.
