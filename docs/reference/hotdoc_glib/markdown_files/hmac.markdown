---
short-description: !!python/unicode 'computes the HMAC for data'
symbols:
- g_hmac_update
- g_hmac_new
- g_compute_hmac_for_data
- GHmac
- g_hmac_unref
- g_hmac_ref
- g_hmac_get_digest
- g_hmac_copy
- g_hmac_get_string
- g_compute_hmac_for_string
title: !!python/unicode 'Secure HMAC Digests'
...

HMACs should be used when producing a cookie or hash based on data
and a key. Simple mechanisms for using SHA1 and other algorithms to
digest a key and data together are vulnerable to various security
issues.
[HMAC](http://en.wikipedia.org/wiki/HMAC)
uses algorithms like SHA1 in a secure way to produce a digest of a
key and data.

Both the key and data are arbitrary byte arrays of bytes or characters.

Support for HMAC Digests has been added in GLib 2.30, and support for SHA-512
in GLib 2.42.
