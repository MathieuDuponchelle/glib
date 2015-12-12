### Doubly-Linked_Lists

linked lists that can be iterated over in both directions

 The [](GList) structure and its associated functions provide a standard
 doubly-linked list data structure.

 Each element in the list contains a piece of data, together with
 pointers which link to the previous and next elements in the list.
 Using these pointers it is possible to move through the list in both
 directions (unlike the singly-linked [GSList][glib-Singly-Linked-Lists],
 which only allows movement through the list in the forward direction).

 The double linked list does not keep track of the number of items 
 and does not keep track of both the start and end of the list. If
 you want fast access to both the start and the end of the list, 
 and/or the number of items in the list, use a
 [GQueue][glib-Double-ended-Queues] instead.

 The data contained in each element can be either integer values, by
 using one of the [Type Conversion Macros][glib-Type-Conversion-Macros],
 or simply pointers to any type of data.

 List elements are allocated from the [slice allocator][glib-Memory-Slices],
 which is more efficient than allocating elements individually.

 Note that most of the [](GList) functions expect to be passed a pointer
 to the first element in the list. The functions which insert
 elements return the new start of the list, which may have changed.

 There is no function to create a [](GList). [](NULL) is considered to be
 a valid, empty list so you simply set a [](GList)* to [](NULL) to initialize
 it.

 To add elements, use [](g_list_append), [](g_list_prepend),
 [](g_list_insert) and [](g_list_insert_sorted).

 To visit all elements in the list, use a loop over the list:
 
```C

 GList *l;
 for (l = list; l != NULL; l = l->next)
   {
     // do something with l->data
   }
 
```


 To call a function for each element in the list, use [](g_list_foreach).

 To loop over the list and modify it (e.g. remove a certain element)
 a while loop is more appropriate, for example:
 
```C

 GList *l = list;
 while (l != NULL)
   {
     GList *next = l->next;
     if (should_be_removed (l))
       {
         // possibly free l->data
         list = g_list_delete_link (list, l);
       }
     l = next;
   }
 
```


 To remove elements, use [](g_list_remove).

 To navigate in a list, use [](g_list_first), [](g_list_last),
 [](g_list_next), [](g_list_previous).

 To find elements in the list use [](g_list_nth), [](g_list_nth_data),
 [](g_list_find) and [](g_list_find_custom).

 To find the index of an element use [](g_list_position) and
 [](g_list_index).

 To free the entire list, use [](g_list_free) or [](g_list_free_full).

* [GList]()
* [g_list_append]()
* [g_list_prepend]()
* [g_list_insert]()
* [g_list_insert_before]()
* [g_list_insert_sorted]()
* [g_list_remove]()
* [g_list_remove_link]()
* [g_list_delete_link]()
* [g_list_remove_all]()
* [g_list_free]()
* [g_list_free_full]()
* [g_list_alloc]()
* [g_list_free_1]()
* [g_list_free1]()
* [g_list_length]()
* [g_list_copy]()
* [g_list_copy_deep]()
* [g_list_reverse]()
* [g_list_sort]()
* [GCompareFunc]()
* [g_list_insert_sorted_with_data]()
* [g_list_sort_with_data]()
* [GCompareDataFunc]()
* [g_list_concat]()
* [g_list_foreach]()
* [GFunc]()
* [g_list_first]()
* [g_list_last]()
* [g_list_previous]()
* [g_list_next]()
* [g_list_nth]()
* [g_list_nth_data]()
* [g_list_nth_prev]()
* [g_list_find]()
* [g_list_find_custom]()
* [g_list_position]()
* [g_list_index]()
