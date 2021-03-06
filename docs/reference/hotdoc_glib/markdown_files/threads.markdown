---
short-description: !!python/unicode 'portable support for threads, mutexes, locks,     conditions
  and thread private data'
symbols:
- g_cond_broadcast
- GOnceStatus
- g_thread_try_new
- GMutexLocker
- g_bit_unlock
- g_cond_timed_wait
- g_rw_lock_reader_lock
- GThreadError
- g_rw_lock_writer_unlock
- g_thread_unref
- GThreadFunc
- g_mutex_locker_free
- g_once_impl
- g_cond_wait_until
- GCond
- g_rec_mutex_clear
- GThread
- g_mutex_locker_new
- g_mutex_init
- G_LOCK_EXTERN
- g_cond_clear
- G_ONCE_INIT
- g_cond_signal
- g_thread_yield
- g_private_set
- g_rec_mutex_trylock
- g_rw_lock_reader_unlock
- G_LOCK_DEFINE_STATIC
- g_get_num_processors
- g_once_init_leave
- g_rw_lock_reader_trylock
- G_UNLOCK
- GRecMutex
- GMutex
- g_private_get
- GRWLock
- g_once
- g_rec_mutex_lock
- g_bit_lock
- g_rec_mutex_unlock
- g_mutex_clear
- g_thread_new
- g_mutex_trylock
- g_bit_trylock
- G_LOCK_DEFINE
- g_thread_self
- G_THREAD_ERROR
- g_rw_lock_init
- g_cond_init
- g_cond_wait
- g_once_init_enter
- g_rw_lock_writer_trylock
- g_private_replace
- g_thread_exit
- G_TRYLOCK
- g_rw_lock_clear
- GPrivate
- g_mutex_unlock
- G_LOCK
- GOnce
- g_thread_join
- g_rw_lock_writer_lock
- g_thread_ref
- g_rec_mutex_init
- g_thread_error_quark
- g_mutex_lock
title: !!python/unicode 'Threads'
...

Threads act almost like processes, but unlike processes all threads
of one process share the same memory. This is good, as it provides
easy communication between the involved threads via this shared
memory, and it is bad, because strange things (so called
"Heisenbugs") might happen if the program is not carefully designed.
In particular, due to the concurrent nature of threads, no
assumptions on the order of execution of code running in different
threads can be made, unless order is explicitly forced by the
programmer through synchronization primitives.

The aim of the thread-related functions in GLib is to provide a
portable means for writing multi-threaded software. There are
primitives for mutexes to protect the access to portions of memory
([](GMutex), [](GRecMutex) and [](GRWLock)). There is a facility to use
individual bits for locks ([](g_bit_lock)). There are primitives
for condition variables to allow synchronization of threads ([](GCond)).
There are primitives for thread-private data - data that every
thread has a private instance of ([](GPrivate)). There are facilities
for one-time initialization ([](GOnce), [](g_once_init_enter)). Finally,
there are primitives to create and manage threads ([](GThread)).

The GLib threading system used to be initialized with [](g_thread_init).
This is no longer necessary. Since version 2.32, the GLib threading
system is automatically initialized at the start of your program,
and all thread-creation functions and synchronization primitives
are available right away.

Note that it is not safe to assume that your program has no threads
even if you don't call [](g_thread_new) yourself. GLib and GIO can
and will create threads for their own purposes in some cases, such
as when using [](g_unix_signal_source_new) or when using GDBus.

Originally, UNIX did not have threads, and therefore some traditional
UNIX APIs are problematic in threaded programs. Some notable examples
are

- C library functions that return data in statically allocated
buffers, such as [](strtok) or [](strerror). For many of these,
there are thread-safe variants with a _r suffix, or you can
look at corresponding GLib APIs (like [](g_strsplit) or [](g_strerror)).

- The functions [](setenv) and [](unsetenv) manipulate the process
environment in a not thread-safe way, and may interfere with [](getenv)
calls in other threads. Note that [](getenv) calls may be hidden behind
other APIs. For example, GNU [](gettext) calls [](getenv) under the
covers. In general, it is best to treat the environment as readonly.
If you absolutely have to modify the environment, do it early in
[](main), when no other threads are around yet.

- The [](setlocale) function changes the locale for the entire process,
affecting all threads. Temporary changes to the locale are often made
to change the behavior of string scanning or formatting functions
like [](scanf) or [](printf). GLib offers a number of string APIs
(like [](g_ascii_formatd) or [](g_ascii_strtod)) that can often be
used as an alternative. Or you can use the [](uselocale) function
to change the locale only for the current thread.

- The [](fork) function only takes the calling thread into the child's
copy of the process image. If other threads were executing in critical
sections they could have left mutexes locked which could easily
cause deadlocks in the new child. For this reason, you should
call [](exit) or [](exec) as soon as possible in the child and only
make signal-safe library calls before that.

- The [](daemon) function uses [](fork) in a way contrary to what is
described above. It should not be used with GLib programs.

GLib itself is internally completely thread-safe (all global data is
automatically locked), but individual data structure instances are
not automatically locked for performance reasons. For example,
you must coordinate accesses to the same [](GHashTable) from multiple
threads. The two notable exceptions from this rule are [](GMainLoop)
and [](GAsyncQueue), which are thread-safe and need no further
application-level locking to be accessed from multiple threads.
Most refcounting functions such as [](g_object_ref) are also thread-safe.

A common use for [](GThreads) is to move a long-running blocking operation out
of the main thread and into a worker thread. For GLib functions, such as
single GIO operations, this is not necessary, and complicates the code.
Instead, the `…[](_async)` version of the function should be used from the main
thread, eliminating the need for locking and synchronisation between multiple
threads. If an operation does need to be moved to a worker thread, consider
using [](g_task_run_in_thread), or a [](GThreadPool). [](GThreadPool) is often a
better choice than [](GThread), as it handles thread reuse and task queueing;
[](GTask) uses this internally.

However, if multiple blocking operations need to be performed in sequence,
and it is not possible to use [](GTask) for them, moving them to a worker thread
can clarify the code.
