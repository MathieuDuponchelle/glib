### Atomic_Operations

basic atomic integer and pointer operations

 The following is a collection of compiler macros to provide atomic
 access to integer and pointer-sized values.

 The macros that have 'int' in the name will operate on pointers to
 [](gint) and [](guint).  The macros with 'pointer' in the name will operate
 on pointers to any pointer-sized value, including [](gsize).  There is
 no support for 64bit operations on platforms with 32bit pointers
 because it is not generally possible to perform these operations
 atomically.

 The get, set and exchange operations for integers and pointers
 nominally operate on [](gint) and [](gpointer), respectively.  Of the
 arithmetic operations, the 'add' operation operates on (and returns)
 signed integer values ([](gint) and [](gssize)) and the 'and', 'or', and
 'xor' operations operate on (and return) unsigned integer values
 ([](guint) and [](gsize)).

 All of the operations act as a full compiler and (where appropriate)
 hardware memory barrier.  Acquire and release or producer and
 consumer barrier semantics are not available through this API.

 It is very important that all accesses to a particular integer or
 pointer be performed using only this API and that different sizes of
 operation are not mixed or used on overlapping memory regions.  Never
 read or assign directly from or to a value -- always use this API.

 For simple reference counting purposes you should use
 [](g_atomic_int_inc) and [](g_atomic_int_dec_and_test).  Other uses that
 fall outside of simple reference counting patterns are prone to
 subtle bugs and occasionally undefined behaviour.  It is also worth
 noting that since all of these operations require global
 synchronisation of the entire machine, they can be quite slow.  In
 the case of performing multiple atomic operations it can often be
 faster to simply acquire a mutex lock around the critical area,
 perform the operations normally and then release the lock.

* [G_ATOMIC_LOCK_FREE]()
* [g_atomic_int_get]()
* [g_atomic_int_set]()
* [g_atomic_int_inc]()
* [g_atomic_int_dec_and_test]()
* [g_atomic_int_compare_and_exchange]()
* [g_atomic_int_add]()
* [g_atomic_int_and]()
* [g_atomic_int_or]()
* [g_atomic_int_xor]()
* [g_atomic_pointer_get]()
* [g_atomic_pointer_set]()
* [g_atomic_pointer_compare_and_exchange]()
* [g_atomic_pointer_add]()
* [g_atomic_pointer_and]()
* [g_atomic_pointer_or]()
* [g_atomic_pointer_xor]()
* [g_atomic_int_exchange_and_add]()
