### Data_Checksums

computes the checksum for data

 GLib provides a generic API for computing checksums (or "digests")
 for a sequence of arbitrary bytes, using various hashing algorithms
 like MD5, SHA-1 and SHA-256. Checksums are commonly used in various
 environments and specifications.

 GLib supports incremental checksums using the GChecksum data
 structure, by calling [](g_checksum_update) as long as there's data
 available and then using [](g_checksum_get_string) or
 [](g_checksum_get_digest) to compute the checksum and return it either
 as a string in hexadecimal form, or as a raw sequence of bytes. To
 compute the checksum for binary blobs and NUL-terminated strings in
 one go, use the convenience functions [](g_compute_checksum_for_data)
 and [](g_compute_checksum_for_string), respectively.

 Support for checksums has been added in GLib 2.16

* [GChecksumType]()
* [g_checksum_type_get_length]()
* [GChecksum]()
* [g_checksum_new]()
* [g_checksum_copy]()
* [g_checksum_free]()
* [g_checksum_reset]()
* [g_checksum_update]()
* [g_checksum_get_string]()
* [g_checksum_get_digest]()
* [g_compute_checksum_for_data]()
* [g_compute_checksum_for_string]()
* [g_compute_checksum_for_bytes]()
