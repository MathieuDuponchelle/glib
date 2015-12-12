### N-ary_Trees

trees of data with any number of branches

 The [](GNode) struct and its associated functions provide a N-ary tree
 data structure, where nodes in the tree can contain arbitrary data.

 To create a new tree use [](g_node_new).

 To insert a node into a tree use [](g_node_insert),
 [](g_node_insert_before), [](g_node_append) and [](g_node_prepend).

 To create a new node and insert it into a tree use
 [](g_node_insert_data), [](g_node_insert_data_after),
 [](g_node_insert_data_before), [](g_node_append_data)
 and [](g_node_prepend_data).

 To reverse the children of a node use [](g_node_reverse_children).

 To find a node use [](g_node_get_root), [](g_node_find),
 [](g_node_find_child), [](g_node_child_index), [](g_node_child_position),
 [](g_node_first_child), [](g_node_last_child), [](g_node_nth_child),
 [](g_node_first_sibling), [](g_node_prev_sibling), [](g_node_next_sibling)
 or [](g_node_last_sibling).

 To get information about a node or tree use [](G_NODE_IS_LEAF),
 [](G_NODE_IS_ROOT), [](g_node_depth), [](g_node_n_nodes),
 [](g_node_n_children), [](g_node_is_ancestor) or [](g_node_max_height).

 To traverse a tree, calling a function for each node visited in the
 traversal, use [](g_node_traverse) or [](g_node_children_foreach).

 To remove a node or subtree from a tree use [](g_node_unlink) or
 [](g_node_destroy).

* [GNode]()
* [g_node_new]()
* [g_node_copy]()
* [GCopyFunc]()
* [g_node_copy_deep]()
* [g_node_insert]()
* [g_node_insert_before]()
* [g_node_insert_after]()
* [g_node_append]()
* [g_node_prepend]()
* [g_node_insert_data]()
* [g_node_insert_data_after]()
* [g_node_insert_data_before]()
* [g_node_append_data]()
* [g_node_prepend_data]()
* [g_node_reverse_children]()
* [g_node_traverse]()
* [GTraverseType]()
* [GTraverseFlags]()
* [GNodeTraverseFunc]()
* [g_node_children_foreach]()
* [GNodeForeachFunc]()
* [g_node_get_root]()
* [g_node_find]()
* [g_node_find_child]()
* [g_node_child_index]()
* [g_node_child_position]()
* [g_node_first_child]()
* [g_node_last_child]()
* [g_node_nth_child]()
* [g_node_first_sibling]()
* [g_node_next_sibling]()
* [g_node_prev_sibling]()
* [g_node_last_sibling]()
* [G_NODE_IS_LEAF]()
* [G_NODE_IS_ROOT]()
* [g_node_depth]()
* [g_node_n_nodes]()
* [g_node_n_children]()
* [g_node_is_ancestor]()
* [g_node_max_height]()
* [g_node_unlink]()
* [g_node_destroy]()
