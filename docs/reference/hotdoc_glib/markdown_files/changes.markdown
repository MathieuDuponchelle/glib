---
short-description: Incompatible changes made between successing versions of GLib
title: Changes to GLib
...

Changes to GLib

3

Changes to GLib

# Incompatible changes from 2.0 to 2.2

  - GLib changed the seeding algorithm for the pseudo-random number
    generator Mersenne Twister, as used by GRand and GRandom. This was
    necessary, because some seeds would yield very bad pseudo-random
    streams. Also the pseudo-random integers generated by
    `g_rand*_int_range()` will have a slightly better equal distribution
    with the new version of GLib.
    
    Further information can be found at the website of the Mersenne
    Twister random number generator at
    <http://www.math.keio.ac.jp/~matumoto/emt.html>.
    
    The original seeding and generation algorithms, as found in GLib
    2.0.x, can be used instead of the new ones by setting the
    environment variable G\_RANDOM\_VERSION to the value of '2.0'. Use
    the GLib-2.0 algorithms only if you have sequences of numbers
    generated with Glib-2.0 that you need to reproduce exactly.

# Incompatible changes from 1.2 to 2.0

  - The event loop functionality GMain has extensively been revised to
    support multiple separate main loops in separate threads. All
    sources (timeouts, idle functions, etc.) are associated with a
    GMainContext.
    
    Compatibility functions exist so that most application code dealing
    with the main loop will continue to work. However, code that creates
    new custom types of sources will require modification.
    
    The main changes here are:
    
      - Sources are now exposed as `GSource *`, rather than simply as
        numeric ids.
    
      - New types of sources are created by structure "derivation" from
        GSource, so the `source_data` parameter to the GSource virtual
        functions has been replaced with a `GSource *`.
    
      - Sources are first created, then later added to a specific
        GMainContext.
    
      - Dispatching has been modified so both the callback and data are
        passed in to the `dispatch()` virtual function.
    
    To go along with this change, the vtable for GIOChannel has changed
    and `add_watch()` has been replaced by `create_watch()`.

  - `g_list_foreach()` and `g_slist_foreach()` have been changed so they
    are now safe against removal of the current item, not the next item.
    
    It's not recommended to mutate the list in the callback to these
    functions in any case.

  - GDate now works in UTF-8, not in the current locale. If you want to
    use it with the encoding of the locale, you need to convert strings
    using `g_locale_to_utf8()` first.

  - `g_strsplit()` has been fixed to:
    
      - include trailing empty tokens, rather than stripping them
    
      - split into a maximum of `max_tokens` tokens, rather than
        `max_tokens + 1`
    
    Code depending on either of these bugs will need to be fixed.

  - Deprecated functions that got removed: `g_set_error_handler()`,
    `g_set_warning_handler()`, `g_set_message_handler()`, use
    `g_log_set_handler()` instead.
