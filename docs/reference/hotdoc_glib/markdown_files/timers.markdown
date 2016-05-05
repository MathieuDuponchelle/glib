---
short-description: !!python/unicode 'keep track of elapsed time'
symbols:
- GTimer
- g_timer_new
- g_timer_destroy
- g_timer_start
- g_timer_stop
- g_timer_elapsed
- g_timer_reset
- g_timer_continue
title: !!python/unicode 'Timers'
...

[](GTimer) records a start time, and counts microseconds elapsed since
that time. This is done somewhat differently on different platforms,
and can be tricky to get exactly right, so [](GTimer) provides a
portable/convenient interface.
