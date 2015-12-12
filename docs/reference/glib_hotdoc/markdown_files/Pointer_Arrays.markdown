### Pointer_Arrays

arrays of pointers to any type of data, which
     grow automatically as new elements are added

 Pointer Arrays are similar to Arrays but are used only for storing
 pointers.

 If you remove elements from the array, elements at the end of the
 array are moved into the space previously occupied by the removed
 element. This means that you should not rely on the index of particular
 elements remaining the same. You should also be careful when deleting
 elements while iterating over the array.

 To create a pointer array, use [](g_ptr_array_new).

 To add elements to a pointer array, use [](g_ptr_array_add).

 To remove elements from a pointer array, use [](g_ptr_array_remove),
 [](g_ptr_array_remove_index) or [](g_ptr_array_remove_index_fast).

 To access an element of a pointer array, use [](g_ptr_array_index).

 To set the size of a pointer array, use [](g_ptr_array_set_size).

 To free a pointer array, use [](g_ptr_array_free).

 An example using a [](GPtrArray):
 
```C

   GPtrArray *array;
   gchar *string1 = "one";
   gchar *string2 = "two";
   gchar *string3 = "three";

   array = [](g_ptr_array_new);
   g_ptr_array_add (array, (gpointer) string1);
   g_ptr_array_add (array, (gpointer) string2);
   g_ptr_array_add (array, (gpointer) string3);

   if (g_ptr_array_index (array, 0) != (gpointer) string1)
     g_print ("ERROR: got [](p) instead of [](p)\n",
              g_ptr_array_index (array, 0), string1);

   g_ptr_array_free (array, TRUE);
 
```


* [GPtrArray]()
* [g_ptr_array_new]()
* [g_ptr_array_sized_new]()
* [g_ptr_array_new_with_free_func]()
* [g_ptr_array_new_full]()
* [g_ptr_array_set_free_func]()
* [g_ptr_array_ref]()
* [g_ptr_array_unref]()
* [g_ptr_array_add]()
* [g_ptr_array_insert]()
* [g_ptr_array_remove]()
* [g_ptr_array_remove_index]()
* [g_ptr_array_remove_fast]()
* [g_ptr_array_remove_index_fast]()
* [g_ptr_array_remove_range]()
* [g_ptr_array_sort]()
* [g_ptr_array_sort_with_data]()
* [g_ptr_array_set_size]()
* [g_ptr_array_index]()
* [g_ptr_array_free]()
* [g_ptr_array_foreach]()
