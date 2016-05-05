---
short-description: !!python/unicode 'a portable way to convert between different byte
  orders'
symbols:
- GLONG_TO_LE
- GSIZE_TO_BE
- GINT_TO_LE
- GUINT16_TO_BE
- GSSIZE_TO_BE
- GINT16_TO_LE
- GUINT32_TO_LE
- GUINT64_TO_BE
- GSIZE_TO_LE
- GINT32_TO_BE
- GULONG_TO_BE
- G_BYTE_ORDER
- GUINT32_TO_BE
- GUINT64_TO_LE
- GUINT_TO_BE
- GUINT16_TO_LE
- GINT32_TO_LE
- GULONG_TO_LE
- GINT64_TO_LE
- GUINT_TO_LE
- GINT16_TO_BE
- GINT64_TO_BE
- GLONG_TO_BE
- GINT_TO_BE
- GSSIZE_TO_LE
title: !!python/unicode 'Byte Order Macros'
...

These macros provide a portable way to determine the host byte order
and to convert values between different byte orders.

The byte order is the order in which bytes are stored to create larger
data types such as the [](gint) and [](glong) values.
The host byte order is the byte order used on the current machine.

Some processors store the most significant bytes (i.e. the bytes that
hold the largest part of the value) first. These are known as big-endian
processors. Other processors (notably the x86 family) store the most
significant byte last. These are known as little-endian processors.

Finally, to complicate matters, some other processors store the bytes in
a rather curious order known as PDP-endian. For a 4-byte word, the 3rd
most significant byte is stored first, then the 4th, then the 1st and
finally the 2nd.

Obviously there is a problem when these different processors communicate
with each other, for example over networks or by using binary file formats.
This is where these macros come in. They are typically used to convert
values into a byte order which has been agreed on for use when
communicating between different processors. The Internet uses what is
known as 'network byte order' as the standard byte order (which is in
fact the big-endian byte order).

Note that the byte order conversion macros may evaluate their arguments
multiple times, thus you should not use them with arguments which have
side-effects.
