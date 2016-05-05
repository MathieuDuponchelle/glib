---
short-description: !!python/unicode 'caches allow sharing of complex data structures                     to
  save resources'
symbols:
- GCache
- g_cache_insert
- g_cache_destroy
- GCacheDestroyFunc
- GCacheNewFunc
- GCacheDupFunc
- g_cache_key_foreach
- g_cache_value_foreach
- g_cache_new
- g_cache_remove
title: !!python/unicode 'Caches'
...

A [](GCache) allows sharing of complex data structures, in order to
save system resources.

GCache uses keys and values. A GCache key describes the properties
of a particular resource. A GCache value is the actual resource.

GCache has been marked as deprecated, since this API is rarely
used and not very actively maintained.
