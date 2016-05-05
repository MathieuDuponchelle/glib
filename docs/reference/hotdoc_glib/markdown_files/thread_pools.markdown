---
short-description: !!python/unicode 'pools of threads to execute work concurrently'
symbols:
- g_thread_pool_set_max_idle_time
- g_thread_pool_set_max_threads
- g_thread_pool_free
- GThreadPool
- g_thread_pool_unprocessed
- g_thread_pool_set_max_unused_threads
- g_thread_pool_set_sort_function
- g_thread_pool_get_num_threads
- g_thread_pool_get_num_unused_threads
- g_thread_pool_push
- g_thread_pool_move_to_front
- g_thread_pool_stop_unused_threads
- g_thread_pool_get_max_threads
- g_thread_pool_get_max_unused_threads
- g_thread_pool_new
- g_thread_pool_get_max_idle_time
title: !!python/unicode 'Thread Pools'
...

Sometimes you wish to asynchronously fork out the execution of work
and continue working in your own thread. If that will happen often,
the overhead of starting and destroying a thread each time might be
too high. In such cases reusing already started threads seems like a
good idea. And it indeed is, but implementing this can be tedious
and error-prone.

Therefore GLib provides thread pools for your convenience. An added
advantage is, that the threads can be shared between the different
subsystems of your program, when they are using GLib.

To create a new thread pool, you use [](g_thread_pool_new).
It is destroyed by [](g_thread_pool_free).

If you want to execute a certain task within a thread pool,
you call [](g_thread_pool_push).

To get the current number of running threads you call
[](g_thread_pool_get_num_threads). To get the number of still
unprocessed tasks you call [](g_thread_pool_unprocessed). To control
the maximal number of threads for a thread pool, you use
[](g_thread_pool_get_max_threads) and [](g_thread_pool_set_max_threads).

Finally you can control the number of unused threads, that are kept
alive by GLib for future use. The current number can be fetched with
[](g_thread_pool_get_num_unused_threads). The maximal number can be
controlled by [](g_thread_pool_get_max_unused_threads) and
[](g_thread_pool_set_max_unused_threads). All currently unused threads
can be stopped by calling [](g_thread_pool_stop_unused_threads).
