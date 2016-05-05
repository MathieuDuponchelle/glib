---
short-description: !!python/unicode 'portably storing integers in pointer variables'
symbols:
- GINT_TO_POINTER
- GSIZE_TO_POINTER
- GPOINTER_TO_INT
- GPOINTER_TO_SIZE
- GPOINTER_TO_UINT
- GUINT_TO_POINTER
title: !!python/unicode 'Type Conversion Macros'
...

Many times GLib, GTK+, and other libraries allow you to pass "user
data" to a callback, in the form of a void pointer. From time to time
you want to pass an integer instead of a pointer. You could allocate
an integer, with something like:

```
&lt;!-- language="C" --&gt;
int *ip = g_new (int, 1);
*ip = 42;

```

But this is inconvenient, and it's annoying to have to free the
memory at some later time.

Pointers are always at least 32 bits in size (on all platforms GLib
intends to support). Thus you can store at least 32-bit integer values
in a pointer value. Naively, you might try this, but it's incorrect:

```
&lt;!-- language="C" --&gt;
gpointer p;
int i;
p = (void*) 42;
i = (int) p;

```

Again, that example was not correct, don't copy it.
The problem is that on some systems you need to do this:

```
&lt;!-- language="C" --&gt;
gpointer p;
int i;
p = (void*) (long) 42;
i = (int) (long) p;

```

The GLib macros [](GPOINTER_TO_INT), [](GINT_TO_POINTER), etc. take care
to do the right thing on the every platform.

Warning: You may not store pointers in integers. This is not
portable in any way, shape or form. These macros only allow storing
integers in pointers, and only preserve 32 bits of the integer; values
outside the range of a 32-bit integer will be mangled.
