### Balanced_Binary_Trees

a sorted collection of key/value pairs optimized
                     for searching and traversing in order

 The [](GTree) structure and its associated functions provide a sorted
 collection of key/value pairs optimized for searching and traversing
 in order.

 To create a new [](GTree) use [](g_tree_new).

 To insert a key/value pair into a [](GTree) use [](g_tree_insert).

 To lookup the value corresponding to a given key, use
 [](g_tree_lookup) and [](g_tree_lookup_extended).

 To find out the number of nodes in a [](GTree), use [](g_tree_nnodes). To
 get the height of a [](GTree), use [](g_tree_height).

 To traverse a [](GTree), calling a function for each node visited in
 the traversal, use [](g_tree_foreach).

 To remove a key/value pair use [](g_tree_remove).

 To destroy a [](GTree), use [](g_tree_destroy).

* [GTree]()
* [g_tree_new]()
* [g_tree_ref]()
* [g_tree_unref]()
* [g_tree_new_with_data]()
* [g_tree_new_full]()
* [g_tree_insert]()
* [g_tree_replace]()
* [g_tree_nnodes]()
* [g_tree_height]()
* [g_tree_lookup]()
* [g_tree_lookup_extended]()
* [g_tree_foreach]()
* [g_tree_traverse]()
* [GTraverseFunc]()
* [g_tree_search]()
* [g_tree_remove]()
* [g_tree_steal]()
* [g_tree_destroy]()
