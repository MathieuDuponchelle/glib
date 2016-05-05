---
short-description: !!python/unicode 'Internet hostname utilities'
symbols:
- g_hostname_is_ascii_encoded
- g_hostname_is_ip_address
- g_hostname_to_ascii
- g_hostname_to_unicode
- g_hostname_is_non_ascii
title: Hostname Utilities
...

Functions for manipulating internet hostnames; in particular, for
converting between Unicode and ASCII-encoded forms of
Internationalized Domain Names (IDNs).

The
[Internationalized Domain Names for Applications (IDNA)](http://www.ietf.org/rfc/rfc3490.txt)
standards allow for the use
of Unicode domain names in applications, while providing
backward-compatibility with the old ASCII-only DNS, by defining an
ASCII-Compatible Encoding of any given Unicode name, which can be
used with non-IDN-aware applications and protocols. (For example,
"Παν語.org" maps to "xn--4wa8awb4637h.org".)
