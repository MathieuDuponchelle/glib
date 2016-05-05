---
short-description: !!python/unicode 'support for manipulating lists of hook functions'
symbols:
- g_hook_find_func_data
- G_HOOK_FLAGS
- g_hook_list_clear
- GHookCheckMarshaller
- g_hook_find_data
- GHookList
- G_HOOK_IS_UNLINKED
- g_hook_ref
- g_hook_append
- g_hook_next_valid
- g_hook_find_func
- g_hook_first_valid
- g_hook_alloc
- g_hook_get
- GHookMarshaller
- G_HOOK
- g_hook_insert_sorted
- GHookFindFunc
- g_hook_insert_before
- g_hook_free
- GHookFlagMask
- g_hook_destroy_link
- GHookCheckFunc
- g_hook_list_invoke_check
- g_hook_compare_ids
- g_hook_list_marshal_check
- GHookFinalizeFunc
- g_hook_list_marshal
- GHookCompareFunc
- g_hook_find
- G_HOOK_ACTIVE
- G_HOOK_IS_VALID
- g_hook_list_invoke
- GHookFunc
- g_hook_unref
- g_hook_list_init
- G_HOOK_IN_CALL
- G_HOOK_FLAG_USER_SHIFT
- g_hook_destroy
- GHook
- g_hook_prepend
title: !!python/unicode 'Hook Functions'
...

The [](GHookList), [](GHook) and their related functions provide support for
lists of hook functions. Functions can be added and removed from the lists,
and the list of hook functions can be invoked.
