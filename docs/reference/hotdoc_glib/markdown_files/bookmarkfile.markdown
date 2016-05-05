---
short-description: !!python/unicode 'parses files containing bookmarks'
symbols:
- g_bookmark_file_free
- g_bookmark_file_get_added
- g_bookmark_file_to_data
- g_bookmark_file_load_from_data_dirs
- g_bookmark_file_set_icon
- g_bookmark_file_set_description
- g_bookmark_file_remove_item
- g_bookmark_file_get_applications
- g_bookmark_file_load_from_data
- g_bookmark_file_has_group
- g_bookmark_file_has_item
- g_bookmark_file_get_is_private
- g_bookmark_file_remove_group
- g_bookmark_file_get_groups
- g_bookmark_file_set_app_info
- g_bookmark_file_get_mime_type
- g_bookmark_file_set_visited
- GBookmarkFileError
- GBookmarkFile
- g_bookmark_file_add_application
- G_BOOKMARK_FILE_ERROR
- g_bookmark_file_set_modified
- g_bookmark_file_set_is_private
- g_bookmark_file_set_groups
- g_bookmark_file_add_group
- g_bookmark_file_remove_application
- g_bookmark_file_to_file
- g_bookmark_file_get_title
- g_bookmark_file_get_icon
- g_bookmark_file_set_mime_type
- g_bookmark_file_get_description
- g_bookmark_file_set_title
- g_bookmark_file_error_quark
- g_bookmark_file_move_item
- g_bookmark_file_get_size
- g_bookmark_file_new
- g_bookmark_file_set_added
- g_bookmark_file_has_application
- g_bookmark_file_get_app_info
- g_bookmark_file_get_modified
- g_bookmark_file_get_visited
- g_bookmark_file_load_from_file
title: !!python/unicode 'Bookmark file parser'
...

GBookmarkFile lets you parse, edit or create files containing bookmarks
to URI, along with some meta-data about the resource pointed by the URI
like its MIME type, the application that is registering the bookmark and
the icon that should be used to represent the bookmark. The data is stored
using the
[Desktop Bookmark Specification](http://www.gnome.org/~ebassi/bookmark-spec).

The syntax of the bookmark files is described in detail inside the
Desktop Bookmark Specification, here is a quick summary: bookmark
files use a sub-class of the XML Bookmark Exchange Language
specification, consisting of valid UTF-8 encoded XML, under the
&lt;xbel&gt; root element; each bookmark is stored inside a
&lt;bookmark&gt; element, using its URI: no relative paths can
be used inside a bookmark file. The bookmark may have a user defined
title and description, to be used instead of the URI. Under the
&lt;metadata&gt; element, with its owner attribute set to
`http://freedesktop.org`, is stored the meta-data about a resource
pointed by its URI. The meta-data consists of the resource's MIME
type; the applications that have registered a bookmark; the groups
to which a bookmark belongs to; a visibility flag, used to set the
bookmark as "private" to the applications and groups that has it
registered; the URI and MIME type of an icon, to be used when
displaying the bookmark inside a GUI.

Here is an example of a bookmark file:
[bookmarks.xbel](https://git.gnome.org/browse/glib/tree/glib/tests/bookmarks.xbel)

A bookmark file might contain more than one bookmark; each bookmark
is accessed through its URI.

The important caveat of bookmark files is that when you add a new
bookmark you must also add the application that is registering it, using
[](g_bookmark_file_add_application) or [](g_bookmark_file_set_app_info).
If a bookmark has no applications then it won't be dumped when creating
the on disk representation, using [](g_bookmark_file_to_data) or
[](g_bookmark_file_to_file).

The [](GBookmarkFile) parser was added in GLib 2.12.
