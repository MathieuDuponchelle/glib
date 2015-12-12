### Key-value_file_parser

parses .ini-like config files

 [](GKeyFile) lets you parse, edit or create files containing groups of
 key-value pairs, which we call "key files" for lack of a better name.
 Several freedesktop.org specifications use key files now, e.g the
 [Desktop Entry Specification](http://freedesktop.org/Standards/desktop-entry-spec)
 and the
 [Icon Theme Specification](http://freedesktop.org/Standards/icon-theme-spec).

 The syntax of key files is described in detail in the
 [Desktop Entry Specification](http://freedesktop.org/Standards/desktop-entry-spec),
 here is a quick summary: Key files
 consists of groups of key-value pairs, interspersed with comments.

 
```

 # this is just an example
 # there can be comments before the first group

 [First Group]

 Name=Key File Example\tthis value shows\nescaping

 # localized strings are stored in multiple key-value pairs
 Welcome=Hello
 Welcome[de]=Hallo
 Welcome[fr_FR]=Bonjour
 Welcome[it]=Ciao
 Welcome[be@latin]=Hello

 [Another Group]

 Numbers=2;20;-200;0

 Booleans=true;false;true;true
 
```


 Lines beginning with a '#' and blank lines are considered comments.

 Groups are started by a header line containing the group name enclosed
 in '[' and ']', and ended implicitly by the start of the next group or
 the end of the file. Each key-value pair must be contained in a group.

 Key-value pairs generally have the form `key=value`, with the
 exception of localized strings, which have the form
 `key[locale]=value`, with a locale identifier of the
 form `lang_COUNTRY_MODIFIER_` where `COUNTRY` and `MODIFIER`
 are optional.
 Space before and after the '=' character are ignored. Newline, tab,
 carriage return and backslash characters in value are escaped as \n,
 \t, \r, and \\, respectively. To preserve leading spaces in values,
 these can also be escaped as \s.

 Key files can store strings (possibly with localized variants), integers,
 booleans and lists of these. Lists are separated by a separator character,
 typically ';' or ','. To use the list separator character in a value in
 a list, it has to be escaped by prefixing it with a backslash.

 This syntax is obviously inspired by the .ini files commonly met
 on Windows, but there are some important differences:

 - .ini files use the ';' character to begin comments,
   key files use the '#' character.

 - Key files do not allow for ungrouped keys meaning only
   comments can precede the first group.

 - Key files are always encoded in UTF-8.

 - Key and Group names are case-sensitive. For example, a group called
   [GROUP] is a different from [group].

 - .ini files don't have a strongly typed boolean entry type,
    they only have [](GetProfileInt). In key files, only
    true and false (in lower case) are allowed.

 Note that in contrast to the
 [Desktop Entry Specification](http://freedesktop.org/Standards/desktop-entry-spec),
 groups in key files may contain the same
 key multiple times; the last entry wins. Key files may also contain
 multiple groups with the same name; they are merged together.
 Another difference is that keys and group names in key files are not
 restricted to ASCII characters.

* [GKeyFile]()
* [G_KEY_FILE_ERROR]()
* [GKeyFileError]()
* [GKeyFileFlags]()
* [g_key_file_new]()
* [g_key_file_free]()
* [g_key_file_ref]()
* [g_key_file_unref]()
* [g_key_file_set_list_separator]()
* [g_key_file_load_from_file]()
* [g_key_file_load_from_data]()
* [g_key_file_load_from_data_dirs]()
* [g_key_file_load_from_dirs]()
* [g_key_file_to_data]()
* [g_key_file_save_to_file]()
* [g_key_file_get_start_group]()
* [g_key_file_get_groups]()
* [g_key_file_get_keys]()
* [g_key_file_has_group]()
* [g_key_file_has_key]()
* [g_key_file_get_value]()
* [g_key_file_get_string]()
* [g_key_file_get_locale_string]()
* [g_key_file_get_boolean]()
* [g_key_file_get_integer]()
* [g_key_file_get_int64]()
* [g_key_file_get_uint64]()
* [g_key_file_get_double]()
* [g_key_file_get_string_list]()
* [g_key_file_get_locale_string_list]()
* [g_key_file_get_boolean_list]()
* [g_key_file_get_integer_list]()
* [g_key_file_get_double_list]()
* [g_key_file_get_comment]()
* [g_key_file_set_value]()
* [g_key_file_set_string]()
* [g_key_file_set_locale_string]()
* [g_key_file_set_boolean]()
* [g_key_file_set_integer]()
* [g_key_file_set_int64]()
* [g_key_file_set_uint64]()
* [g_key_file_set_double]()
* [g_key_file_set_string_list]()
* [g_key_file_set_locale_string_list]()
* [g_key_file_set_boolean_list]()
* [g_key_file_set_integer_list]()
* [g_key_file_set_double_list]()
* [g_key_file_set_comment]()
* [g_key_file_remove_group]()
* [g_key_file_remove_key]()
* [g_key_file_remove_comment]()
* [G_KEY_FILE_DESKTOP_GROUP]()
* [G_KEY_FILE_DESKTOP_KEY_TYPE]()
* [G_KEY_FILE_DESKTOP_KEY_VERSION]()
* [G_KEY_FILE_DESKTOP_KEY_NAME]()
* [G_KEY_FILE_DESKTOP_KEY_GENERIC_NAME]()
* [G_KEY_FILE_DESKTOP_KEY_NO_DISPLAY]()
* [G_KEY_FILE_DESKTOP_KEY_COMMENT]()
* [G_KEY_FILE_DESKTOP_KEY_ICON]()
* [G_KEY_FILE_DESKTOP_KEY_HIDDEN]()
* [G_KEY_FILE_DESKTOP_KEY_ONLY_SHOW_IN]()
* [G_KEY_FILE_DESKTOP_KEY_NOT_SHOW_IN]()
* [G_KEY_FILE_DESKTOP_KEY_TRY_EXEC]()
* [G_KEY_FILE_DESKTOP_KEY_EXEC]()
* [G_KEY_FILE_DESKTOP_KEY_PATH]()
* [G_KEY_FILE_DESKTOP_KEY_TERMINAL]()
* [G_KEY_FILE_DESKTOP_KEY_MIME_TYPE]()
* [G_KEY_FILE_DESKTOP_KEY_CATEGORIES]()
* [G_KEY_FILE_DESKTOP_KEY_STARTUP_NOTIFY]()
* [G_KEY_FILE_DESKTOP_KEY_STARTUP_WM_CLASS]()
* [G_KEY_FILE_DESKTOP_KEY_URL]()
* [G_KEY_FILE_DESKTOP_KEY_ACTIONS]()
* [G_KEY_FILE_DESKTOP_KEY_DBUS_ACTIVATABLE]()
* [G_KEY_FILE_DESKTOP_TYPE_APPLICATION]()
* [G_KEY_FILE_DESKTOP_TYPE_LINK]()
* [G_KEY_FILE_DESKTOP_TYPE_DIRECTORY]()
* [g_key_file_error_quark]()
* [g_key_file_get_type]()
