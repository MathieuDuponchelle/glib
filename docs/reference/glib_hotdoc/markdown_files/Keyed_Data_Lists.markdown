### Keyed_Data_Lists

lists of data elements which are accessible by a
                     string or GQuark identifier

 Keyed data lists provide lists of arbitrary data elements which can
 be accessed either with a string or with a [](GQuark) corresponding to
 the string.

 The [](GQuark) methods are quicker, since the strings have to be
 converted to [](GQuarks) anyway.

 Data lists are used for associating arbitrary data with [](GObjects),
 using [](g_object_set_data) and related functions.

 To create a datalist, use [](g_datalist_init).

 To add data elements to a datalist use [](g_datalist_id_set_data),
 [](g_datalist_id_set_data_full), [](g_datalist_set_data) and
 [](g_datalist_set_data_full).

 To get data elements from a datalist use [](g_datalist_id_get_data)
 and [](g_datalist_get_data).

 To iterate over all data elements in a datalist use
 [](g_datalist_foreach) (not thread-safe).

 To remove data elements from a datalist use
 [](g_datalist_id_remove_data) and [](g_datalist_remove_data).

 To remove all data elements from a datalist, use [](g_datalist_clear).

* [GData]()
* [g_datalist_init]()
* [g_datalist_id_set_data]()
* [g_datalist_id_set_data_full]()
* [g_datalist_id_get_data]()
* [g_datalist_id_remove_data]()
* [g_datalist_id_remove_no_notify]()
* [GDuplicateFunc]()
* [g_datalist_id_dup_data]()
* [g_datalist_id_replace_data]()
* [g_datalist_set_data]()
* [g_datalist_set_data_full]()
* [g_datalist_get_data]()
* [g_datalist_remove_data]()
* [g_datalist_remove_no_notify]()
* [g_datalist_foreach]()
* [g_datalist_clear]()
* [g_datalist_set_flags]()
* [g_datalist_unset_flags]()
* [g_datalist_get_flags]()
* [G_DATALIST_FLAGS_MASK]()
