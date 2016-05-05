---
short-description: !!python/unicode 'general memory-handling'
symbols:
- g_alloca
- g_mem_gc_friendly
- g_steal_pointer
- g_try_realloc_n
- g_malloc_n
- g_mem_profile
- g_try_malloc
- g_memdup
- g_realloc_n
- g_try_malloc_n
- g_malloc0_n
- g_try_malloc0
- g_newa
- g_realloc
- g_free
- g_try_new
- g_new
- GMemVTable
- g_try_renew
- g_renew
- glib_mem_profiler_table
- g_malloc
- g_try_malloc0_n
- g_new0
- g_memmove
- g_mem_is_system_malloc
- g_malloc0
- g_mem_set_vtable
- g_try_realloc
- g_try_new0
title: !!python/unicode 'Memory Allocation'
...

These functions provide support for allocating and freeing memory.

If any call to allocate memory fails, the application is terminated.
This also means that there is no need to check if the call succeeded.

It's important to match [](g_malloc) (and wrappers such as [](g_new)) with
[](g_free), [](g_slice_alloc) (and wrappers such as [](g_slice_new)) with
[](g_slice_free), plain [](malloc) with [](free), and (if you're using C++)
new with delete and new[] with delete[]. Otherwise bad things can happen,
since these allocators may use different memory pools (and new/delete call
constructors and destructors).
