---
short-description: !!python/unicode 'a structure representing a time zone'
symbols:
- g_time_zone_adjust_time
- g_time_zone_find_interval
- g_time_zone_get_offset
- g_time_zone_get_abbreviation
- g_time_zone_new
- GTimeZone
- g_time_zone_new_local
- g_time_zone_unref
- g_time_zone_is_dst
- g_time_zone_new_utc
- g_time_zone_ref
- GTimeType
title: !!python/unicode 'GTimeZone'
...

[](GTimeZone) is a structure that represents a time zone, at no
particular point in time.  It is refcounted and immutable.

A time zone contains a number of intervals.  Each interval has
an abbreviation to describe it, an offet to UTC and a flag indicating
if the daylight savings time is in effect during that interval.  A
time zone always has at least one interval -- interval 0.

Every UTC time is contained within exactly one interval, but a given
local time may be contained within zero, one or two intervals (due to
incontinuities associated with daylight savings time).

An interval may refer to a specific period of time (eg: the duration
of daylight savings time during 2010) or it may refer to many periods
of time that share the same properties (eg: all periods of daylight
savings time).  It is also possible (usually for political reasons)
that some properties (like the abbreviation) change between intervals
without other properties changing.

[](GTimeZone) is available since GLib 2.26.
