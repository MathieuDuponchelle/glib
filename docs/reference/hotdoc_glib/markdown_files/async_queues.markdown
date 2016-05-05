---
short-description: !!python/unicode 'asynchronous communication between threads'
symbols:
- g_async_queue_try_pop
- g_async_queue_lock
- g_async_queue_timed_pop
- g_async_queue_new
- g_async_queue_timeout_pop
- g_async_queue_pop_unlocked
- g_async_queue_remove_unlocked
- g_async_queue_push_sorted_unlocked
- g_async_queue_push_front_unlocked
- g_async_queue_length
- g_async_queue_unref
- g_async_queue_new_full
- g_async_queue_timed_pop_unlocked
- g_async_queue_sort
- g_async_queue_length_unlocked
- g_async_queue_timeout_pop_unlocked
- g_async_queue_push_unlocked
- g_async_queue_push_front
- g_async_queue_push
- GAsyncQueue
- g_async_queue_unlock
- g_async_queue_try_pop_unlocked
- g_async_queue_ref
- g_async_queue_push_sorted
- g_async_queue_remove
- g_async_queue_pop
- g_async_queue_sort_unlocked
- g_async_queue_ref_unlocked
- g_async_queue_unref_and_unlock
title: !!python/unicode 'Asynchronous Queues'
...

Often you need to communicate between different threads. In general
it's safer not to do this by shared memory, but by explicit message
passing. These messages only make sense asynchronously for
multi-threaded applications though, as a synchronous operation could
as well be done in the same thread.

Asynchronous queues are an exception from most other GLib data
structures, as they can be used simultaneously from multiple threads
without explicit locking and they bring their own builtin reference
counting. This is because the nature of an asynchronous queue is that
it will always be used by at least 2 concurrent threads.

For using an asynchronous queue you first have to create one with
[](g_async_queue_new). [](GAsyncQueue) structs are reference counted,
use [](g_async_queue_ref) and [](g_async_queue_unref) to manage your
references.

A thread which wants to send a message to that queue simply calls
[](g_async_queue_push) to push the message to the queue.

A thread which is expecting messages from an asynchronous queue
simply calls [](g_async_queue_pop) for that queue. If no message is
available in the queue at that point, the thread is now put to sleep
until a message arrives. The message will be removed from the queue
and returned. The functions [](g_async_queue_try_pop) and
[](g_async_queue_timeout_pop) can be used to only check for the presence
of messages or to only wait a certain time for messages respectively.

For almost every function there exist two variants, one that locks
the queue and one that doesn't. That way you can hold the queue lock
(acquire it with [](g_async_queue_lock) and release it with
[](g_async_queue_unlock)) over multiple queue accessing instructions.
This can be necessary to ensure the integrity of the queue, but should
only be used when really necessary, as it can make your life harder
if used unwisely. Normally you should only use the locking function
variants (those without the _unlocked suffix).

In many cases, it may be more convenient to use [](GThreadPool) when
you need to distribute work to a set of worker threads instead of
using [](GAsyncQueue) manually. [](GThreadPool) uses a GAsyncQueue
internally.
