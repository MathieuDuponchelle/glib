### Trash_Stacks

maintain a stack of unused allocated memory chunks

 A [](GTrashStack) is an efficient way to keep a stack of unused allocated
 memory chunks. Each memory chunk is required to be large enough to hold
 a [](gpointer). This allows the stack to be maintained without any space
 overhead, since the stack pointers can be stored inside the memory chunks.

 There is no function to create a [](GTrashStack). A [](NULL) [](GTrashStack)*
 is a perfectly valid empty stack.

* [GTrashStack]()
* [g_trash_stack_push]()
* [g_trash_stack_pop]()
* [g_trash_stack_peek]()
* [g_trash_stack_height]()
