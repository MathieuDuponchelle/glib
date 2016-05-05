---
short-description: !!python/unicode 'associate groups of data elements with                     particular
  memory locations'
symbols:
- g_dataset_destroy
- GDataForeachFunc
- GDestroyNotify
- g_dataset_foreach
- g_dataset_id_remove_no_notify
- g_dataset_id_set_data_full
- g_dataset_id_get_data
title: !!python/unicode 'Datasets'
...

Datasets associate groups of data elements with particular memory
locations. These are useful if you need to associate data with a
structure returned from an external library. Since you cannot modify
the structure, you use its location in memory as the key into a
dataset, where you can associate any number of data elements with it.

There are two forms of most of the dataset functions. The first form
uses strings to identify the data elements associated with a
location. The second form uses [](GQuark) identifiers, which are
created with a call to [](g_quark_from_string) or
[](g_quark_from_static_string). The second form is quicker, since it
does not require looking up the string in the hash table of [](GQuark)
identifiers.

There is no function to create a dataset. It is automatically
created as soon as you add elements to it.

To add data elements to a dataset use [](g_dataset_id_set_data),
[](g_dataset_id_set_data_full), [](g_dataset_set_data) and
[](g_dataset_set_data_full).

To get data elements from a dataset use [](g_dataset_id_get_data) and
[](g_dataset_get_data).

To iterate over all data elements in a dataset use
[](g_dataset_foreach) (not thread-safe).

To remove data elements from a dataset use
[](g_dataset_id_remove_data) and [](g_dataset_remove_data).

To destroy a dataset, use [](g_dataset_destroy).
