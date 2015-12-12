### Basic_Types

standard GLib types, defined for ease-of-use
     and portability

 GLib defines a number of commonly used types, which can be divided
 into 4 groups:
 - New types which are not part of standard C (but are defined in
   various C standard library header files) - [](gboolean), [](gsize),
   [](gssize), [](goffset), [](gintptr), [](guintptr).
 - Integer types which are guaranteed to be the same size across
   all platforms - [](gint8), [](guint8), [](gint16), [](guint16), [](gint32),
   [](guint32), [](gint64), [](guint64).
 - Types which are easier to use than their standard C counterparts -
   [](gpointer), [](gconstpointer), [](guchar), [](guint), [](gushort), [](gulong).
 - Types which correspond exactly to standard C types, but are
   included for completeness - [](gchar), [](gint), [](gshort), [](glong),
   [](gfloat), [](gdouble).

 GLib also defines macros for the limits of some of the standard
 integer and floating point types, as well as macros for suitable
 [](printf) formats for these types.

* [gboolean]()
* [gpointer]()
* [gconstpointer]()
* [gchar]()
* [guchar]()
* [gint]()
* [G_MININT]()
* [G_MAXINT]()
* [guint]()
* [G_MAXUINT]()
* [gshort]()
* [G_MINSHORT]()
* [G_MAXSHORT]()
* [gushort]()
* [G_MAXUSHORT]()
* [glong]()
* [G_MINLONG]()
* [G_MAXLONG]()
* [gulong]()
* [G_MAXULONG]()
* [gint8]()
* [G_MININT8]()
* [G_MAXINT8]()
* [guint8]()
* [G_MAXUINT8]()
* [gint16]()
* [G_MININT16]()
* [G_MAXINT16]()
* [G_GINT16_MODIFIER]()
* [G_GINT16_FORMAT]()
* [guint16]()
* [G_MAXUINT16]()
* [G_GUINT16_FORMAT]()
* [gint32]()
* [G_MININT32]()
* [G_MAXINT32]()
* [G_GINT32_MODIFIER]()
* [G_GINT32_FORMAT]()
* [guint32]()
* [G_MAXUINT32]()
* [G_GUINT32_FORMAT]()
* [gint64]()
* [G_MININT64]()
* [G_MAXINT64]()
* [G_GINT64_MODIFIER]()
* [G_GINT64_FORMAT]()
* [G_GINT64_CONSTANT]()
* [guint64]()
* [G_MAXUINT64]()
* [G_GUINT64_FORMAT]()
* [G_GUINT64_CONSTANT]()
* [gfloat]()
* [G_MINFLOAT]()
* [G_MAXFLOAT]()
* [gdouble]()
* [G_MINDOUBLE]()
* [G_MAXDOUBLE]()
* [gsize]()
* [G_MAXSIZE]()
* [G_GSIZE_MODIFIER]()
* [G_GSIZE_FORMAT]()
* [gssize]()
* [G_MINSSIZE]()
* [G_MAXSSIZE]()
* [G_GSSIZE_MODIFIER]()
* [G_GSSIZE_FORMAT]()
* [goffset]()
* [G_MINOFFSET]()
* [G_MAXOFFSET]()
* [G_GOFFSET_MODIFIER]()
* [G_GOFFSET_FORMAT]()
* [G_GOFFSET_CONSTANT]()
* [gintptr]()
* [G_GINTPTR_MODIFIER]()
* [G_GINTPTR_FORMAT]()
* [guintptr]()
* [G_GUINTPTR_FORMAT]()
* [GLIB_SIZEOF_SSIZE_T]()
* [GLIB_SIZEOF_VOID_P]()
* [GLIB_SIZEOF_LONG]()
* [GLIB_SIZEOF_SIZE_T]()
* [G_HAVE_GINT64]()
