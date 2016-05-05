---
short-description: !!python/unicode 'versatile support for logging messages     with
  different levels of importance'
symbols:
- GLogFunc
- G_LOG_DOMAIN
- g_log_set_always_fatal
- g_log_set_fatal_mask
- g_log
- g_log_set_default_handler
- g_log_set_handler
- GLogLevelFlags
- g_error
- g_log_default_handler
- g_log_remove_handler
- g_critical
- g_logv
- g_log_set_handler_full
- g_message
- g_debug
- G_LOG_FATAL_MASK
- G_LOG_LEVEL_USER_SHIFT
- g_info
- g_warning
title: !!python/unicode 'Message Logging'
...

These functions provide support for logging error messages
or messages used for debugging.

There are several built-in levels of messages, defined in
[](GLogLevelFlags). These can be extended with user-defined levels.
