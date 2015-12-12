### Version_Information

variables and functions to check the GLib version

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

* [glib_major_version]()
* [glib_minor_version]()
* [glib_micro_version]()
* [glib_binary_age]()
* [glib_interface_age]()
* [glib_check_version]()
* [GLIB_MAJOR_VERSION]()
* [GLIB_MINOR_VERSION]()
* [GLIB_MICRO_VERSION]()
* [GLIB_CHECK_VERSION]()
* [GLIB_VERSION_2_26]()
* [GLIB_VERSION_2_28]()
* [GLIB_VERSION_2_30]()
* [GLIB_VERSION_2_32]()
* [GLIB_VERSION_2_34]()
* [GLIB_VERSION_2_36]()
* [GLIB_VERSION_2_38]()
* [GLIB_VERSION_2_40]()
* [GLIB_VERSION_2_42]()
* [GLIB_VERSION_2_44]()
* [GLIB_VERSION_2_46]()
* [GLIB_VERSION_MIN_REQUIRED]()
* [GLIB_VERSION_MAX_ALLOWED]()
* [GLIB_DISABLE_DEPRECATION_WARNINGS]()
* [G_ENCODE_VERSION]()
* [GLIB_AVAILABLE_IN_ALL]()
* [GLIB_AVAILABLE_IN_2_26]()
* [GLIB_AVAILABLE_IN_2_28]()
* [GLIB_AVAILABLE_IN_2_30]()
* [GLIB_AVAILABLE_IN_2_32]()
* [GLIB_AVAILABLE_IN_2_34]()
* [GLIB_AVAILABLE_IN_2_36]()
* [GLIB_AVAILABLE_IN_2_38]()
* [GLIB_AVAILABLE_IN_2_40]()
* [GLIB_AVAILABLE_IN_2_42]()
* [GLIB_AVAILABLE_IN_2_44]()
* [GLIB_AVAILABLE_IN_2_46]()
* [GLIB_DEPRECATED_IN_2_26]()
* [GLIB_DEPRECATED_IN_2_26_FOR]()
* [GLIB_DEPRECATED_IN_2_28]()
* [GLIB_DEPRECATED_IN_2_28_FOR]()
* [GLIB_DEPRECATED_IN_2_30]()
* [GLIB_DEPRECATED_IN_2_30_FOR]()
* [GLIB_DEPRECATED_IN_2_32]()
* [GLIB_DEPRECATED_IN_2_32_FOR]()
* [GLIB_DEPRECATED_IN_2_34]()
* [GLIB_DEPRECATED_IN_2_34_FOR]()
* [GLIB_DEPRECATED_IN_2_36]()
* [GLIB_DEPRECATED_IN_2_36_FOR]()
* [GLIB_DEPRECATED_IN_2_38]()
* [GLIB_DEPRECATED_IN_2_38_FOR]()
* [GLIB_DEPRECATED_IN_2_40]()
* [GLIB_DEPRECATED_IN_2_40_FOR]()
* [GLIB_DEPRECATED_IN_2_42]()
* [GLIB_DEPRECATED_IN_2_42_FOR]()
* [GLIB_DEPRECATED_IN_2_44]()
* [GLIB_DEPRECATED_IN_2_44_FOR]()
* [GLIB_DEPRECATED_IN_2_46]()
* [GLIB_DEPRECATED_IN_2_46_FOR]()
* [GLIB_VERSION_CUR_STABLE]()
* [GLIB_VERSION_PREV_STABLE]()
