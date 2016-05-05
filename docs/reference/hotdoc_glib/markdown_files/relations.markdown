---
short-description: !!python/unicode 'tables of data which can be indexed on any                     number
  of fields'
symbols:
- GRelation
- g_relation_new
- g_relation_select
- g_relation_delete
- g_relation_print
- g_relation_destroy
- g_tuples_index
- GTuples
- g_relation_exists
- g_relation_index
- g_tuples_destroy
- g_relation_count
- g_relation_insert
title: !!python/unicode 'Relations and Tuples'
...

A [](GRelation) is a table of data which can be indexed on any number
of fields, rather like simple database tables. A [](GRelation) contains
a number of records, called tuples. Each record contains a number of
fields. Records are not ordered, so it is not possible to find the
record at a particular index.

Note that [](GRelation) tables are currently limited to 2 fields.

To create a GRelation, use [](g_relation_new).

To specify which fields should be indexed, use [](g_relation_index).
Note that this must be called before any tuples are added to the
[](GRelation).

To add records to a [](GRelation) use [](g_relation_insert).

To determine if a given record appears in a [](GRelation), use
[](g_relation_exists). Note that fields are compared directly, so
pointers must point to the exact same position (i.e. different
copies of the same string will not match.)

To count the number of records which have a particular value in a
given field, use [](g_relation_count).

To get all the records which have a particular value in a given
field, use [](g_relation_select). To access fields of the resulting
records, use [](g_tuples_index). To free the resulting records use
[](g_tuples_destroy).

To delete all records which have a particular value in a given
field, use [](g_relation_delete).

To destroy the [](GRelation), use [](g_relation_destroy).

To help debug [](GRelation) objects, use [](g_relation_print).

GRelation has been marked as deprecated, since this API has never
been fully implemented, is not very actively maintained and rarely
used.
