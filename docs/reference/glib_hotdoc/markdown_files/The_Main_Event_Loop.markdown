### The_Main_Event_Loop

manages all available sources of events

 The main event loop manages all the available sources of events for
 GLib and GTK+ applications. These events can come from any number of
 different types of sources such as file descriptors (plain files,
 pipes or sockets) and timeouts. New types of event sources can also
 be added using [](g_source_attach).

 To allow multiple independent sets of sources to be handled in
 different threads, each source is associated with a [](GMainContext).
 A GMainContext can only be running in a single thread, but
 sources can be added to it and removed from it from other threads.

 Each event source is assigned a priority. The default priority,
 [](G_PRIORITY_DEFAULT), is 0. Values less than 0 denote higher priorities.
 Values greater than 0 denote lower priorities. Events from high priority
 sources are always processed before events from lower priority sources.

 Idle functions can also be added, and assigned a priority. These will
 be run whenever no events with a higher priority are ready to be processed.

 The [](GMainLoop) data type represents a main event loop. A GMainLoop is
 created with [](g_main_loop_new). After adding the initial event sources,
 [](g_main_loop_run) is called. This continuously checks for new events from
 each of the event sources and dispatches them. Finally, the processing of
 an event from one of the sources leads to a call to [](g_main_loop_quit) to
 exit the main loop, and [](g_main_loop_run) returns.

 It is possible to create new instances of [](GMainLoop) recursively.
 This is often used in GTK+ applications when showing modal dialog
 boxes. Note that event sources are associated with a particular
 [](GMainContext), and will be checked and dispatched for all main
 loops associated with that GMainContext.

 GTK+ contains wrappers of some of these functions, e.g. [](gtk_main),
 [](gtk_main_quit) and [](gtk_events_pending).

 ## Creating new source types

 One of the unusual features of the [](GMainLoop) functionality
 is that new types of event source can be created and used in
 addition to the builtin type of event source. A new event source
 type is used for handling GDK events. A new source type is created
 by "deriving" from the [](GSource) structure. The derived type of
 source is represented by a structure that has the [](GSource) structure
 as a first element, and other elements specific to the new source
 type. To create an instance of the new source type, call
 [](g_source_new) passing in the size of the derived structure and
 a table of functions. These [](GSourceFuncs) determine the behavior of
 the new source type.

 New source types basically interact with the main context
 in two ways. Their prepare function in [](GSourceFuncs) can set a timeout
 to determine the maximum amount of time that the main loop will sleep
 before checking the source again. In addition, or as well, the source
 can add file descriptors to the set that the main context checks using
 [](g_source_add_poll).

 ## Customizing the main loop iteration

 Single iterations of a [](GMainContext) can be run with
 [](g_main_context_iteration). In some cases, more detailed control
 of exactly how the details of the main loop work is desired, for
 instance, when integrating the [](GMainLoop) with an external main loop.
 In such cases, you can call the component functions of
 [](g_main_context_iteration) directly. These functions are
 [](g_main_context_prepare), [](g_main_context_query),
 [](g_main_context_check) and [](g_main_context_dispatch).

 ## State of a Main Context # {[](mainloop)-states}

 The operation of these functions can best be seen in terms
 of a state diagram, as shown in this image.

 ![](mainloop-states.gif)

 On UNIX, the GLib mainloop is incompatible with [](fork). Any program
 using the mainloop must either [](exec) or [](exit) from the child
 without returning to the mainloop.

* [GMainLoop]()
* [g_main_loop_new]()
* [g_main_loop_ref]()
* [g_main_loop_unref]()
* [g_main_loop_run]()
* [g_main_loop_quit]()
* [g_main_loop_is_running]()
* [g_main_loop_get_context]()
* [g_main_new]()
* [g_main_destroy]()
* [g_main_run]()
* [g_main_quit]()
* [g_main_is_running]()
* [G_PRIORITY_HIGH]()
* [G_PRIORITY_DEFAULT]()
* [G_PRIORITY_HIGH_IDLE]()
* [G_PRIORITY_DEFAULT_IDLE]()
* [G_PRIORITY_LOW]()
* [G_SOURCE_CONTINUE]()
* [G_SOURCE_REMOVE]()
* [GMainContext]()
* [g_main_context_new]()
* [g_main_context_ref]()
* [g_main_context_unref]()
* [g_main_context_default]()
* [g_main_context_iteration]()
* [g_main_iteration]()
* [g_main_context_pending]()
* [g_main_pending]()
* [g_main_context_find_source_by_id]()
* [g_main_context_find_source_by_user_data]()
* [g_main_context_find_source_by_funcs_user_data]()
* [g_main_context_wakeup]()
* [g_main_context_acquire]()
* [g_main_context_release]()
* [g_main_context_is_owner]()
* [g_main_context_wait]()
* [g_main_context_prepare]()
* [g_main_context_query]()
* [g_main_context_check]()
* [g_main_context_dispatch]()
* [g_main_context_set_poll_func]()
* [g_main_context_get_poll_func]()
* [GPollFunc]()
* [g_main_context_add_poll]()
* [g_main_context_remove_poll]()
* [g_main_depth]()
* [g_main_current_source]()
* [g_main_set_poll_func]()
* [g_main_context_invoke]()
* [g_main_context_invoke_full]()
* [g_main_context_get_thread_default]()
* [g_main_context_ref_thread_default]()
* [g_main_context_push_thread_default]()
* [g_main_context_pop_thread_default]()
* [g_timeout_source_new]()
* [g_timeout_source_new_seconds]()
* [g_timeout_add]()
* [g_timeout_add_full]()
* [g_timeout_add_seconds]()
* [g_timeout_add_seconds_full]()
* [g_idle_source_new]()
* [g_idle_add]()
* [g_idle_add_full]()
* [g_idle_remove_by_data]()
* [GPid]()
* [GChildWatchFunc]()
* [g_child_watch_source_new]()
* [g_child_watch_add]()
* [g_child_watch_add_full]()
* [GPollFD]()
* [g_poll]()
* [G_POLLFD_FORMAT]()
* [GSource]()
* [GSourceDummyMarshal]()
* [GSourceFuncs]()
* [GSourceCallbackFuncs]()
* [g_source_new]()
* [g_source_ref]()
* [g_source_unref]()
* [g_source_set_funcs]()
* [g_source_attach]()
* [g_source_destroy]()
* [g_source_is_destroyed]()
* [g_source_set_priority]()
* [g_source_get_priority]()
* [g_source_set_can_recurse]()
* [g_source_get_can_recurse]()
* [g_source_get_id]()
* [g_source_get_name]()
* [g_source_set_name]()
* [g_source_set_name_by_id]()
* [g_source_get_context]()
* [g_source_set_callback]()
* [GSourceFunc]()
* [g_source_set_callback_indirect]()
* [g_source_set_ready_time]()
* [g_source_get_ready_time]()
* [g_source_add_unix_fd]()
* [g_source_remove_unix_fd]()
* [g_source_modify_unix_fd]()
* [g_source_query_unix_fd]()
* [g_source_add_poll]()
* [g_source_remove_poll]()
* [g_source_add_child_source]()
* [g_source_remove_child_source]()
* [g_source_get_time]()
* [g_source_get_current_time]()
* [g_source_remove]()
* [g_source_remove_by_funcs_user_data]()
* [g_source_remove_by_user_data]()
* [GLIB_HAVE_ALLOCA_H]()
* [alloca]()
* [GLIB_USING_SYSTEM_PRINTF]()
* [GLIB_SYSDEF_POLLERR]()
* [GLIB_SYSDEF_POLLHUP]()
* [GLIB_SYSDEF_POLLIN]()
* [GLIB_SYSDEF_POLLNVAL]()
* [GLIB_SYSDEF_POLLOUT]()
* [GLIB_SYSDEF_POLLPRI]()
* [GLIB_SYSDEF_AF_INET]()
* [GLIB_SYSDEF_AF_INET6]()
* [GLIB_SYSDEF_AF_UNIX]()
* [GLIB_SYSDEF_MSG_DONTROUTE]()
* [GLIB_SYSDEF_MSG_OOB]()
* [GLIB_SYSDEF_MSG_PEEK]()
* [G_WIN32_MSG_HANDLE]()
* [g_idle_funcs]()
* [g_timeout_funcs]()
* [g_child_watch_funcs]()
* [g_unix_signal_funcs]()
* [g_unix_fd_source_funcs]()
* [GSourcePrivate]()
