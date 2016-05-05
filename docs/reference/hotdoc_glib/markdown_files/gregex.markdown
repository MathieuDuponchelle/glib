---
short-description: !!python/unicode 'matches strings against regular expressions'
symbols:
- GRegexError
- g_regex_split
- g_regex_match_full
- g_regex_error_quark
- g_regex_ref
- g_match_info_free
- g_match_info_fetch
- g_regex_match_all
- g_regex_replace_eval
- GRegexMatchFlags
- g_regex_get_max_lookbehind
- g_regex_replace
- g_match_info_expand_references
- g_regex_get_string_number
- GMatchInfo
- g_match_info_matches
- g_match_info_get_regex
- g_regex_split_full
- GRegexCompileFlags
- g_regex_get_compile_flags
- GRegexEvalCallback
- g_match_info_unref
- g_match_info_next
- g_regex_new
- g_regex_match_all_full
- g_match_info_fetch_named_pos
- g_regex_replace_literal
- g_regex_get_pattern
- g_regex_get_max_backref
- g_match_info_get_string
- g_match_info_ref
- g_regex_check_replacement
- g_regex_get_match_flags
- g_regex_match
- g_regex_unref
- g_regex_escape_string
- g_regex_escape_nul
- g_match_info_get_match_count
- g_regex_get_capture_count
- g_match_info_is_partial_match
- g_regex_split_simple
- G_REGEX_ERROR
- g_regex_get_has_cr_or_lf
- g_regex_match_simple
- g_match_info_fetch_all
- g_match_info_fetch_pos
- GRegex
- g_match_info_fetch_named
title: !!python/unicode 'Perl-compatible regular expressions'
...

The g_regex_*() functions implement regular
expression pattern matching using syntax and semantics similar to
Perl regular expression.

Some functions accept a _start_position_ argument, setting it differs
from just passing over a shortened string and setting [](G_REGEX_MATCH_NOTBOL)
in the case of a pattern that begins with any kind of lookbehind assertion.
For example, consider the pattern "\Biss\B" which finds occurrences of "iss"
in the middle of words. ("\B" matches only if the current position in the
subject is not a word boundary.) When applied to the string "Mississipi"
from the fourth byte, namely "issipi", it does not match, because "\B" is
always false at the start of the subject, which is deemed to be a word
boundary. However, if the entire string is passed , but with
_start_position_ set to 4, it finds the second occurrence of "iss" because
it is able to look behind the starting point to discover that it is
preceded by a letter.

Note that, unless you set the [](G_REGEX_RAW) flag, all the strings passed
to these functions must be encoded in UTF-8. The lengths and the positions
inside the strings are in bytes and not in characters, so, for instance,
"\xc3\xa0" (i.e. "à") is two bytes long but it is treated as a
single character. If you set [](G_REGEX_RAW) the strings can be non-valid
UTF-8 strings and a byte is treated as a character, so "\xc3\xa0" is two
bytes and two characters long.

When matching a pattern, "\n" matches only against a "\n" character in
the string, and "\r" matches only a "\r" character. To match any newline
sequence use "\R". This particular group matches either the two-character
sequence CR + LF ("\r\n"), or one of the single characters LF (linefeed,
U+000A, "\n"), VT vertical tab, U+000B, "\v"), FF (formfeed, U+000C, "\f"),
CR (carriage return, U+000D, "\r"), NEL (next line, U+0085), LS (line
separator, U+2028), or PS (paragraph separator, U+2029).

The behaviour of the dot, circumflex, and dollar metacharacters are
affected by newline characters, the default is to recognize any newline
character (the same characters recognized by "\R"). This can be changed
with [](G_REGEX_NEWLINE_CR), [](G_REGEX_NEWLINE_LF) and [](G_REGEX_NEWLINE_CRLF)
compile options, and with [](G_REGEX_MATCH_NEWLINE_ANY),
[](G_REGEX_MATCH_NEWLINE_CR), [](G_REGEX_MATCH_NEWLINE_LF) and
[](G_REGEX_MATCH_NEWLINE_CRLF) match options. These settings are also
relevant when compiling a pattern if [](G_REGEX_EXTENDED) is set, and an
unescaped "#" outside a character class is encountered. This indicates
a comment that lasts until after the next newline.

When setting the [](G_REGEX_JAVASCRIPT_COMPAT) flag, pattern syntax and pattern
matching is changed to be compatible with the way that regular expressions
work in JavaScript. More precisely, a lonely ']' character in the pattern
is a syntax error; the '\x' escape only allows 0 to 2 hexadecimal digits, and
you must use the '\u' escape sequence with 4 hex digits to specify a unicode
codepoint instead of '\x' or 'x{....}'. If '\x' or '\u' are not followed by
the specified number of hex digits, they match 'x' and 'u' literally; also
'\U' always matches 'U' instead of being an error in the pattern. Finally,
pattern matching is modified so that back references to an unset subpattern
group produces a match with the empty string instead of an error. See
pcreapi(3) for more information.

Creating and manipulating the same [](GRegex) structure from different
threads is not a problem as [](GRegex) does not modify its internal
state between creation and destruction, on the other hand [](GMatchInfo)
is not threadsafe.

The regular expressions low-level functionalities are obtained through
the excellent
[PCRE](http://www.pcre.org/)
library written by Philip Hazel.
