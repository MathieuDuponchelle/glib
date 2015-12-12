### File_Utilities

various file-related functions

 There is a group of functions which wrap the common POSIX functions
 dealing with filenames ([](g_open), [](g_rename), [](g_mkdir), [](g_stat),
 [](g_unlink), [](g_remove), [](g_fopen), [](g_freopen)). The point of these
 wrappers is to make it possible to handle file names with any Unicode
 characters in them on Windows without having to use ifdefs and the
 wide character API in the application code.

 The pathname argument should be in the GLib file name encoding.
 On POSIX this is the actual on-disk encoding which might correspond
 to the locale settings of the process (or the `G_FILENAME_ENCODING`
 environment variable), or not.

 On Windows the GLib file name encoding is UTF-8. Note that the
 Microsoft C library does not use UTF-8, but has separate APIs for
 current system code page and wide characters (UTF-16). The GLib
 wrappers call the wide character API if present (on modern Windows
 systems), otherwise convert to/from the system code page.

 Another group of functions allows to open and read directories
 in the GLib file name encoding. These are [](g_dir_open),
 [](g_dir_read_name), [](g_dir_rewind), [](g_dir_close).

* [GFileError]()
* [G_FILE_ERROR]()
* [GFileTest]()
* [g_file_error_from_errno]()
* [g_file_get_contents]()
* [g_file_set_contents]()
* [g_file_test]()
* [g_mkstemp]()
* [g_mkstemp_full]()
* [g_file_open_tmp]()
* [g_file_read_link]()
* [g_mkdir_with_parents]()
* [g_mkdtemp]()
* [g_mkdtemp_full]()
* [g_dir_make_tmp]()
* [GDir]()
* [g_dir_open]()
* [g_dir_read_name]()
* [g_dir_rewind]()
* [g_dir_close]()
* [GMappedFile]()
* [g_mapped_file_new]()
* [g_mapped_file_new_from_fd]()
* [g_mapped_file_ref]()
* [g_mapped_file_unref]()
* [g_mapped_file_free]()
* [g_mapped_file_get_length]()
* [g_mapped_file_get_contents]()
* [g_mapped_file_get_bytes]()
* [g_open]()
* [g_rename]()
* [g_mkdir]()
* [GStatBuf]()
* [g_stat]()
* [g_lstat]()
* [g_unlink]()
* [g_remove]()
* [g_rmdir]()
* [g_fopen]()
* [g_freopen]()
* [g_chmod]()
* [g_access]()
* [g_creat]()
* [g_chdir]()
* [g_utime]()
* [g_close]()
* [g_file_error_quark]()
* [utimbuf]()
