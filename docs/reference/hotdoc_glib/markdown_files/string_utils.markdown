---
short-description: !!python/unicode 'various string-related functions'
symbols:
- g_fprintf
- g_vsprintf
- g_ascii_isdigit
- g_strfreev
- g_strlcpy
- g_strdup
- g_ascii_isxdigit
- g_strjoinv
- g_ascii_xdigit_value
- g_strdup_vprintf
- g_ascii_isupper
- g_ascii_toupper
- g_strescape
- g_vprintf
- g_ascii_isprint
- g_strchug
- g_strjoin
- GStrv
- g_printf
- g_ascii_isalnum
- g_ascii_isalpha
- g_ascii_strdown
- g_ascii_strtoull
- g_strcanon
- g_strconcat
- g_ascii_islower
- g_strv_length
- g_strcompress
- g_strsplit_set
- g_str_to_ascii
- G_STR_DELIMITERS
- g_str_has_prefix
- g_strcmp0
- g_strsplit
- g_ascii_table
- g_strerror
- GAsciiType
- G_ASCII_DTOSTR_BUF_SIZE
- g_strstrip
- g_strrstr_len
- g_ascii_tolower
- g_strv_contains
- g_strnfill
- g_ascii_strtoll
- g_ascii_digit_value
- g_vfprintf
- g_vasprintf
- g_strup
- g_strsignal
- g_strrstr
- g_snprintf
- g_ascii_strcasecmp
- g_ascii_iscntrl
- g_string_ascii_down
- g_vsnprintf
- g_sprintf
- g_ascii_strncasecmp
- g_strdelimit
- g_str_tokenize_and_fold
- g_str_has_suffix
- g_ascii_strup
- g_strtod
- g_str_match_string
- g_ascii_formatd
- g_strdup_printf
- g_str_is_ascii
- g_strdown
- g_ascii_isspace
- g_strcasecmp
- g_strdupv
- g_ascii_dtostr
- g_strchomp
- g_ascii_strtod
- g_printf_string_upper_bound
- g_strreverse
- g_ascii_ispunct
- g_strndup
- g_ascii_isgraph
- g_stpcpy
- g_strlcat
- g_strncasecmp
- g_strstr_len
- g_string_ascii_up
title: !!python/unicode 'String Utility Functions'
...

This section describes a number of utility functions for creating,
duplicating, and manipulating strings.

Note that the functions [](g_printf), [](g_fprintf), [](g_sprintf),
[](g_snprintf), [](g_vprintf), [](g_vfprintf), [](g_vsprintf) and [](g_vsnprintf)
are declared in the header `gprintf.h` which is not included in `glib.h`
(otherwise using `glib.h` would drag in `stdio.h`), so you'll have to
explicitly include `&lt;glib/gprintf.h&gt;` in order to use the GLib
[](printf) functions.

## String precision pitfalls # {[](string)-precision}

While you may use the [](printf) functions to format UTF-8 strings,
notice that the precision of a \[](Ns) parameter is interpreted
as the number of bytes, not characters to print. On top of that,
the GNU libc implementation of the [](printf) functions has the
"feature" that it checks that the string given for the \[](Ns)
parameter consists of a whole number of characters in the current
encoding. So, unless you are sure you are always going to be in an
UTF-8 locale or your know your text is restricted to ASCII, avoid
using \[](Ns). If your intention is to format strings for a
certain number of columns, then \[](Ns) is not a correct solution
anyway, since it fails to take wide characters (see [](g_unichar_iswide))
into account.

Note also that there are various [](printf) parameters which are platform
dependent. GLib provides platform independent macros for these parameters
which should be used instead. A common example is [](G_GUINT64_FORMAT), which
should be used instead of `[](llu)` or similar parameters for formatting
64-bit integers. These macros are all named `G_*_FORMAT`; see
[Basic Types][glib-Basic-Types].
