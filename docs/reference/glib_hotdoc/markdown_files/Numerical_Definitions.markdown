### Numerical_Definitions

mathematical constants, and floating point decomposition

 GLib offers mathematical constants such as [](G_PI) for the value of pi;
 many platforms have these in the C library, but some don't, the GLib
 versions always exist.

 The [](GFloatIEEE754) and [](GDoubleIEEE754) unions are used to access the
 sign, mantissa and exponent of IEEE floats and doubles. These unions are
 defined as appropriate for a given platform. IEEE floats and doubles are
 supported (used for storage) by at least Intel, PPC and Sparc. See
 [IEEE 754-2008](http://en.wikipedia.org/wiki/IEEE_float)
 for more information about IEEE number formats.

* [G_IEEE754_FLOAT_BIAS]()
* [G_IEEE754_DOUBLE_BIAS]()
* [GFloatIEEE754]()
* [GDoubleIEEE754]()
* [G_E]()
* [G_LN2]()
* [G_LN10]()
* [G_PI]()
* [G_PI_2]()
* [G_PI_4]()
* [G_SQRT2]()
* [G_LOG_2_BASE_10]()
