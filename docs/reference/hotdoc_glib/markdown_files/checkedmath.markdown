---
short-description: !!python/unicode 'a set of helpers for performing checked integer
  arithmetic'
symbols: []
title: !!python/unicode 'Bounds-checking integer arithmetic'
...

GLib offers a set of macros for doing additions and multiplications
of unsigned integers, with checks for overflows.

The helpers all have three arguments.  A pointer to the destination
is always the first argument and the operands to the operation are
the other two.

Following standard GLib convention, the helpers return [](TRUE) in case
of success (ie: no overflow).

The helpers may be macros, normal functions or inlines.  They may be
implemented with inline assembly or compiler intrinsics where
available.

