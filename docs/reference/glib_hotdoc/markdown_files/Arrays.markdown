### Arrays

arrays of arbitrary elements which grow
     automatically as elements are added

 Arrays are similar to standard C arrays, except that they grow
 automatically as elements are added.

 Array elements can be of any size (though all elements of one array
 are the same size), and the array can be automatically cleared to
 '0's and zero-terminated.

 To create a new array use [](g_array_new).

 To add elements to an array, use [](g_array_append_val),
 [](g_array_append_vals), [](g_array_prepend_val), and
 [](g_array_prepend_vals).

 To access an element of an array, use [](g_array_index).

 To set the size of an array, use [](g_array_set_size).

 To free an array, use [](g_array_free).

 Here is an example that stores integers in a [](GArray):
 
```C

   GArray *garray;
   gint i;
   // We create a new array to store gint values.
   // We don't want it zero-terminated or cleared to 0's.
   garray = g_array_new (FALSE, FALSE, sizeof (gint));
   for (i = 0; i < 10000; i++)
     g_array_append_val (garray, i);
   for (i = 0; i < 10000; i++)
     if (g_array_index (garray, gint, i) != i)
       g_print ("ERROR: got [](d) instead of [](d)\n",
                g_array_index (garray, gint, i), i);
   g_array_free (garray, TRUE);
 
```


* [GArray]()
* [g_array_new]()
* [g_array_sized_new]()
* [g_array_ref]()
* [g_array_unref]()
* [g_array_get_element_size]()
* [g_array_append_val]()
* [g_array_append_vals]()
* [g_array_prepend_val]()
* [g_array_prepend_vals]()
* [g_array_insert_val]()
* [g_array_insert_vals]()
* [g_array_remove_index]()
* [g_array_remove_index_fast]()
* [g_array_remove_range]()
* [g_array_sort]()
* [g_array_sort_with_data]()
* [g_array_index]()
* [g_array_set_size]()
* [g_array_set_clear_func]()
* [g_array_free]()
