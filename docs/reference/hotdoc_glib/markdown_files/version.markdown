---
short-description: !!python/unicode 'variables and functions to check the GLib version'
symbols:
- glib_major_version
- GLIB_MINOR_VERSION
- GLIB_VERSION_MIN_REQUIRED
- GLIB_VERSION_2_26
- GLIB_VERSION_2_48
- GLIB_VERSION_2_28
- GLIB_VERSION_2_40
- GLIB_VERSION_2_42
- GLIB_VERSION_2_44
- GLIB_VERSION_2_46
- GLIB_VERSION_MAX_ALLOWED
- glib_micro_version
- GLIB_DISABLE_DEPRECATION_WARNINGS
- glib_minor_version
- GLIB_MICRO_VERSION
- GLIB_MAJOR_VERSION
- glib_interface_age
- glib_binary_age
- glib_check_version
- GLIB_VERSION_2_38
- GLIB_VERSION_2_50
- GLIB_VERSION_2_34
- GLIB_VERSION_2_36
- GLIB_VERSION_2_30
- GLIB_VERSION_2_32
title: !!python/unicode 'Version Information'
...

GLib provides version information, primarily useful in configure
checks for builds that have a configure script. Applications will
not typically use the features described here.

The GLib headers annotate deprecated APIs in a way that produces
compiler warnings if these deprecated APIs are used. The warnings
can be turned off by defining the macro [](GLIB_DISABLE_DEPRECATION_WARNINGS)
before including the glib.h header.

GLib also provides support for building applications against
defined subsets of deprecated or new GLib APIs. Define the macro
[](GLIB_VERSION_MIN_REQUIRED) to specify up to what version of GLib
you want to receive warnings about deprecated APIs. Define the
macro [](GLIB_VERSION_MAX_ALLOWED) to specify the newest version of
GLib whose API you want to use.
