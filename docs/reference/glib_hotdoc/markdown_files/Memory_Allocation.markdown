### Memory_Allocation

general memory-handling

 These functions provide support for allocating and freeing memory.
 
 If any call to allocate memory fails, the application is terminated.
 This also means that there is no need to check if the call succeeded.
 
 It's important to match [](g_malloc) (and wrappers such as [](g_new)) with
 [](g_free), [](g_slice_alloc) (and wrappers such as [](g_slice_new)) with
 [](g_slice_free), plain [](malloc) with [](free), and (if you're using C++)
 new with delete and new[] with delete[]. Otherwise bad things can happen,
 since these allocators may use different memory pools (and new/delete call
 constructors and destructors).

* [g_new]()
* [g_new0]()
* [g_renew]()
* [g_try_new]()
* [g_try_new0]()
* [g_try_renew]()
* [g_malloc]()
* [g_malloc0]()
* [g_realloc]()
* [g_try_malloc]()
* [g_try_malloc0]()
* [g_try_realloc]()
* [g_malloc_n]()
* [g_malloc0_n]()
* [g_realloc_n]()
* [g_try_malloc_n]()
* [g_try_malloc0_n]()
* [g_try_realloc_n]()
* [g_free]()
* [g_clear_pointer]()
* [g_steal_pointer]()
* [g_mem_gc_friendly]()
* [g_alloca]()
* [g_newa]()
* [g_memmove]()
* [g_memdup]()
* [GMemVTable]()
* [g_mem_set_vtable]()
* [g_mem_is_system_malloc]()
* [glib_mem_profiler_table]()
* [g_mem_profile]()
