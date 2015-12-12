### Base64_Encoding

encodes and decodes data in Base64 format

 Base64 is an encoding that allows a sequence of arbitrary bytes to be
 encoded as a sequence of printable ASCII characters. For the definition
 of Base64, see 
 [RFC 1421](http://www.ietf.org/rfc/rfc1421.txt)
 or
 [RFC 2045](http://www.ietf.org/rfc/rfc2045.txt).
 Base64 is most commonly used as a MIME transfer encoding
 for email.

 GLib supports incremental encoding using [](g_base64_encode_step) and
 [](g_base64_encode_close). Incremental decoding can be done with
 [](g_base64_decode_step). To encode or decode data in one go, use
 [](g_base64_encode) or [](g_base64_decode). To avoid memory allocation when
 decoding, you can use [](g_base64_decode_inplace).

 Support for Base64 encoding has been added in GLib 2.12.

* [g_base64_encode_step]()
* [g_base64_encode_close]()
* [g_base64_encode]()
* [g_base64_decode_step]()
* [g_base64_decode]()
* [g_base64_decode_inplace]()
