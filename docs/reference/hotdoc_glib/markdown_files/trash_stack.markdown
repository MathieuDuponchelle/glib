---
short-description: !!python/unicode 'maintain a stack of unused allocated memory chunks'
symbols:
- g_trash_stack_pop
- g_trash_stack_height
- g_trash_stack_push
- g_trash_stack_peek
- GTrashStack
title: !!python/unicode 'Trash Stacks'
...

A [](GTrashStack) is an efficient way to keep a stack of unused allocated
memory chunks. Each memory chunk is required to be large enough to hold
a [](gpointer). This allows the stack to be maintained without any space
overhead, since the stack pointers can be stored inside the memory chunks.

There is no function to create a [](GTrashStack). A [](NULL) [](GTrashStack)*
is a perfectly valid empty stack.

There is no longer any good reason to use [](GTrashStack).  If you have
extra pieces of memory, [](free) them and allocate them again later.

