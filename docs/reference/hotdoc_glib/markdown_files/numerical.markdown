---
short-description: !!python/unicode 'mathematical constants, and floating point decomposition'
symbols:
- GFloatIEEE754
- GDoubleIEEE754
title: !!python/unicode 'Numerical Definitions'
...

GLib offers mathematical constants such as [](G_PI) for the value of pi;
many platforms have these in the C library, but some don't, the GLib
versions always exist.

The [](GFloatIEEE754) and [](GDoubleIEEE754) unions are used to access the
sign, mantissa and exponent of IEEE floats and doubles. These unions are
defined as appropriate for a given platform. IEEE floats and doubles are
supported (used for storage) by at least Intel, PPC and Sparc. See
[IEEE 754-2008](http://en.wikipedia.org/wiki/IEEE_float)
for more information about IEEE number formats.
