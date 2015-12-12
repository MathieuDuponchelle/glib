### Spawning_Processes

process launching

 GLib supports spawning of processes with an API that is more
 convenient than the bare UNIX [](fork) and [](exec).

 The g_spawn family of functions has synchronous ([](g_spawn_sync))
 and asynchronous variants ([](g_spawn_async), [](g_spawn_async_with_pipes)),
 as well as convenience variants that take a complete shell-like
 commandline ([](g_spawn_command_line_sync), [](g_spawn_command_line_async)).

 See [](GSubprocess) in GIO for a higher-level API that provides
 stream interfaces for communication with child processes.

* [GSpawnError]()
* [G_SPAWN_ERROR]()
* [GSpawnFlags]()
* [GSpawnChildSetupFunc]()
* [g_spawn_async_with_pipes]()
* [g_spawn_async]()
* [g_spawn_sync]()
* [G_SPAWN_EXIT_ERROR]()
* [g_spawn_check_exit_status]()
* [g_spawn_command_line_async]()
* [g_spawn_command_line_sync]()
* [g_spawn_close_pid]()
* [g_spawn_error_quark]()
* [g_spawn_exit_error_quark]()
