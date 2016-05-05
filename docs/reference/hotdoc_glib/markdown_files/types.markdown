---
short-description: !!python/unicode 'standard GLib types, defined for ease-of-use     and
  portability'
symbols:
- G_GUINTPTR_FORMAT
- G_GSIZE_MODIFIER
- G_GINTPTR_FORMAT
- G_GSIZE_FORMAT
- gfloat
- G_GINTPTR_MODIFIER
- G_GINT32_FORMAT
- G_MAXSIZE
- guint
- guchar
- G_MAXLONG
- G_GINT64_CONSTANT
- G_GUINT16_FORMAT
- gpointer
- gint64
- guintptr
- gshort
- glong
- G_GOFFSET_FORMAT
- G_GOFFSET_MODIFIER
- gulong
- G_GINT64_MODIFIER
- G_GINT32_MODIFIER
- gint8
- G_MINOFFSET
- G_MINLONG
- G_GSSIZE_FORMAT
- G_MINSSIZE
- G_GINT16_FORMAT
- gintptr
- G_MAXSHORT
- G_MAXOFFSET
- G_GINT16_MODIFIER
- guint16
- G_MINFLOAT
- gint32
- G_GOFFSET_CONSTANT
- G_MAXUINT
- gsize
- gint16
- G_MINSHORT
- gssize
- G_MAXSSIZE
- gconstpointer
- G_MAXINT
- G_MAXFLOAT
- G_GUINT64_FORMAT
- G_MAXUSHORT
- G_MAXULONG
- G_GUINT64_CONSTANT
- gint
- guint8
- gushort
- G_GSSIZE_MODIFIER
- G_MINDOUBLE
- guint32
- G_GUINT32_FORMAT
- gchar
- gdouble
- G_GINT64_FORMAT
- G_MAXDOUBLE
- guint64
- goffset
- G_MININT
- gboolean
title: !!python/unicode 'Basic Types'
...

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
