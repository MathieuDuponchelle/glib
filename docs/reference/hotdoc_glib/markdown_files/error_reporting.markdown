---
short-description: !!python/unicode 'a system for reporting errors'
symbols:
- g_error_new
- g_error_new_literal
- g_error_free
- g_propagate_error
- g_set_error
- g_propagate_prefixed_error
- GError
- g_clear_error
- g_error_copy
- g_prefix_error
- g_error_matches
- g_set_error_literal
- g_error_new_valist
title: !!python/unicode 'Error Reporting'
...

GLib provides a standard method of reporting errors from a called
function to the calling code. (This is the same problem solved by
exceptions in other languages.) It's important to understand that
this method is both a data type (the [](GError) struct) and a [set of
rules][gerror-rules]. If you use [](GError) incorrectly, then your code will not
properly interoperate with other code that uses [](GError), and users
of your API will probably get confused. In most cases, [using [](GError) is
preferred over numeric error codes][gerror-comparison], but there are
situations where numeric error codes are useful for performance.

First and foremost: [](GError) should only be used to report recoverable
runtime errors, never to report programming errors. If the programmer
has screwed up, then you should use [](g_warning), [](g_return_if_fail),
[](g_assert), [](g_error), or some similar facility. (Incidentally,
remember that the [](g_error) function should only be used for
programming errors, it should not be used to print any error
reportable via [](GError).)

Examples of recoverable runtime errors are "file not found" or
"failed to parse input." Examples of programming errors are "NULL
passed to [](strcmp)" or "attempted to free the same pointer twice."
These two kinds of errors are fundamentally different: runtime errors
should be handled or reported to the user, programming errors should
be eliminated by fixing the bug in the program. This is why most
functions in GLib and GTK+ do not use the [](GError) facility.

Functions that can fail take a return location for a [](GError) as their
last argument. On error, a new [](GError) instance will be allocated and
returned to the caller via this argument. For example:

```
&lt;!-- language="C" --&gt;
gboolean g_file_get_contents (const gchar  *filename,
gchar       **contents,
gsize        *length,
GError      **error);

```

If you pass a non-[](NULL) value for the `error` argument, it should
point to a location where an error can be placed. For example:

```
&lt;!-- language="C" --&gt;
gchar *contents;
GError *err = NULL;

g_file_get_contents ("foo.txt", &amp;contents, NULL, &amp;err);
g_assert ((contents == NULL &amp;&amp; err != NULL) || (contents != NULL &amp;&amp; err == NULL));
if (err != NULL)
{
// Report error to user, and free error
g_assert (contents == NULL);
fprintf (stderr, "Unable to read file: %s\n", err-&gt;message);
g_error_free (err);
}
else
{
// Use file contents
g_assert (contents != NULL);
}

```

Note that `err != NULL` in this example is a reliable indicator
of whether [](g_file_get_contents) failed. Additionally,
[](g_file_get_contents) returns a boolean which
indicates whether it was successful.

Because [](g_file_get_contents) returns [](FALSE) on failure, if you
are only interested in whether it failed and don't need to display
an error message, you can pass [](NULL) for the _error_ argument:

```
&lt;!-- language="C" --&gt;
if (g_file_get_contents ("foo.txt", &amp;contents, NULL, NULL)) // ignore errors
// no error occurred
;
else
// error
;

```


The [](GError) object contains three fields: _domain_ indicates the module
the error-reporting function is located in, _code_ indicates the specific
error that occurred, and _message_ is a user-readable error message with
as many details as possible. Several functions are provided to deal
with an error received from a called function: [](g_error_matches)
returns [](TRUE) if the error matches a given domain and code,
[](g_propagate_error) copies an error into an error location (so the
calling function will receive it), and [](g_clear_error) clears an
error location by freeing the error and resetting the location to
[](NULL). To display an error to the user, simply display the _message_,
perhaps along with additional context known only to the calling
function (the file being opened, or whatever - though in the
[](g_file_get_contents) case, the _message_ already contains a filename).

When implementing a function that can report errors, the basic
tool is [](g_set_error). Typically, if a fatal error occurs you
want to [](g_set_error), then return immediately. [](g_set_error)
does nothing if the error location passed to it is [](NULL).
Here's an example:

```
&lt;!-- language="C" --&gt;
gint
foo_open_file (GError **error)
{
gint fd;

fd = open ("file.txt", O_RDONLY);

if (fd &lt; 0)
{
g_set_error (error,
FOO_ERROR,                 // error domain
FOO_ERROR_BLAH,            // error code
"Failed to open file: %s", // error message format string
g_strerror (errno));
return -1;
}
else
return fd;
}

```


Things are somewhat more complicated if you yourself call another
function that can report a [](GError). If the sub-function indicates
fatal errors in some way other than reporting a [](GError), such as
by returning [](TRUE) on success, you can simply do the following:

```
&lt;!-- language="C" --&gt;
gboolean
my_function_that_can_fail (GError **err)
{
g_return_val_if_fail (err == NULL || *err == NULL, FALSE);

if (!sub_function_that_can_fail (err))
{
// assert that error was set by the sub-function
g_assert (err == NULL || *err != NULL);
return FALSE;
}

// otherwise continue, no error occurred
g_assert (err == NULL || *err == NULL);
}

```


If the sub-function does not indicate errors other than by
reporting a [](GError) (or if its return value does not reliably indicate
errors) you need to create a temporary [](GError)
since the passed-in one may be [](NULL). [](g_propagate_error) is
intended for use in this case.

```
&lt;!-- language="C" --&gt;
gboolean
my_function_that_can_fail (GError **err)
{
GError *tmp_error;

g_return_val_if_fail (err == NULL || *err == NULL, FALSE);

tmp_error = NULL;
sub_function_that_can_fail (&amp;tmp_error);

if (tmp_error != NULL)
{
// store tmp_error in err, if err != NULL,
// otherwise call g_error_free() on tmp_error
g_propagate_error (err, tmp_error);
return FALSE;
}

// otherwise continue, no error occurred
}

```


Error pileups are always a bug. For example, this code is incorrect:

```
&lt;!-- language="C" --&gt;
gboolean
my_function_that_can_fail (GError **err)
{
GError *tmp_error;

g_return_val_if_fail (err == NULL || *err == NULL, FALSE);

tmp_error = NULL;
sub_function_that_can_fail (&amp;tmp_error);
other_function_that_can_fail (&amp;tmp_error);

if (tmp_error != NULL)
{
g_propagate_error (err, tmp_error);
return FALSE;
}
}

```

_tmp_error_ should be checked immediately after [](sub_function_that_can_fail),
and either cleared or propagated upward. The rule is: after each error,
you must either handle the error, or return it to the calling function.

Note that passing [](NULL) for the error location is the equivalent
of handling an error by always doing nothing about it. So the
following code is fine, assuming errors in [](sub_function_that_can_fail)
are not fatal to [](my_function_that_can_fail):

```
&lt;!-- language="C" --&gt;
gboolean
my_function_that_can_fail (GError **err)
{
GError *tmp_error;

g_return_val_if_fail (err == NULL || *err == NULL, FALSE);

sub_function_that_can_fail (NULL); // ignore errors

tmp_error = NULL;
other_function_that_can_fail (&amp;tmp_error);

if (tmp_error != NULL)
{
g_propagate_error (err, tmp_error);
return FALSE;
}
}

```


Note that passing [](NULL) for the error location ignores errors;
it's equivalent to
`try { [](sub_function_that_can_fail); } catch (...) {}`
in C++. It does not mean to leave errors unhandled; it means
to handle them by doing nothing.

Error domains and codes are conventionally named as follows:

- The error domain is called &lt;NAMESPACE&gt;_&lt;MODULE&gt;_ERROR,
for example [](G_SPAWN_ERROR) or [](G_THREAD_ERROR):

```
&lt;!-- language="C" --&gt;
#define G_SPAWN_ERROR g_spawn_error_quark ()

GQuark
g_spawn_error_quark (void)
{
return g_quark_from_static_string ("g-spawn-error-quark");
}

```


- The quark function for the error domain is called
&lt;namespace&gt;_&lt;module&gt;_error_quark,
for example [](g_spawn_error_quark) or [](g_thread_error_quark).

- The error codes are in an enumeration called
&lt;Namespace&gt;&lt;Module&gt;Error;
for example, [](GThreadError) or [](GSpawnError).

- Members of the error code enumeration are called
&lt;NAMESPACE&gt;_&lt;MODULE&gt;_ERROR_&lt;CODE&gt;,
for example [](G_SPAWN_ERROR_FORK) or [](G_THREAD_ERROR_AGAIN).

- If there's a "generic" or "unknown" error code for unrecoverable
errors it doesn't make sense to distinguish with specific codes,
it should be called &lt;NAMESPACE&gt;_&lt;MODULE&gt;_ERROR_FAILED,
for example [](G_SPAWN_ERROR_FAILED). In the case of error code
enumerations that may be extended in future releases, you should
generally not handle this error code explicitly, but should
instead treat any unrecognized error code as equivalent to
FAILED.

## Comparison of [](GError) and traditional error handling # {[](gerror)-comparison}

[](GError) has several advantages over traditional numeric error codes:
importantly, tools like
[gobject-introspection](https://developer.gnome.org/gi/stable/) understand
[](GErrors) and convert them to exceptions in bindings; the message includes
more information than just a code; and use of a domain helps prevent
misinterpretation of error codes.

[](GError) has disadvantages though: it requires a memory allocation, and
formatting the error message string has a performance overhead. This makes it
unsuitable for use in retry loops where errors are a common case, rather than
being unusual. For example, using [](G_IO_ERROR_WOULD_BLOCK) means hitting these
overheads in the normal control flow. String formatting overhead can be
eliminated by using [](g_set_error_literal) in some cases.

These performance issues can be compounded if a function wraps the [](GErrors)
returned by the functions it calls: this multiplies the number of allocations
and string formatting operations. This can be partially mitigated by using
[](g_prefix_error).

## Rules for use of [](GError) # {[](gerror)-rules}

Summary of rules for use of [](GError):

- Do not report programming errors via [](GError).

- The last argument of a function that returns an error should
be a location where a [](GError) can be placed (i.e. "[](GError)** error").
If [](GError) is used with varargs, the [](GError)** should be the last
argument before the "...".

- The caller may pass [](NULL) for the [](GError)** if they are not interested
in details of the exact error that occurred.

- If [](NULL) is passed for the [](GError)** argument, then errors should
not be returned to the caller, but your function should still
abort and return if an error occurs. That is, control flow should
not be affected by whether the caller wants to get a [](GError).

- If a [](GError) is reported, then your function by definition had a
fatal failure and did not complete whatever it was supposed to do.
If the failure was not fatal, then you handled it and you should not
report it. If it was fatal, then you must report it and discontinue
whatever you were doing immediately.

- If a [](GError) is reported, out parameters are not guaranteed to
be set to any defined value.

- A [](GError)* must be initialized to [](NULL) before passing its address
to a function that can report errors.

- "Piling up" errors is always a bug. That is, if you assign a
new [](GError) to a [](GError)* that is non-[](NULL), thus overwriting
the previous error, it indicates that you should have aborted
the operation instead of continuing. If you were able to continue,
you should have cleared the previous error with [](g_clear_error).
[](g_set_error) will complain if you pile up errors.

- By convention, if you return a boolean value indicating success
then [](TRUE) means success and [](FALSE) means failure. Avoid creating
functions which have a boolean return value and a GError parameter,
but where the boolean does something other than signal whether the
GError is set.  Among other problems, it requires C callers to allocate
a temporary error.  Instead, provide a "gboolean *" out parameter.
There are functions in GLib itself such as [](g_key_file_has_key) that
are deprecated because of this. If [](FALSE) is returned, the error must
be set to a non-[](NULL) value.  One exception to this is that in situations
that are already considered to be undefined behaviour (such as when a
[](g_return_val_if_fail) check fails), the error need not be set.
Instead of checking separately whether the error is set, callers
should ensure that they do not provoke undefined behaviour, then
assume that the error will be set on failure.

- A [](NULL) return value is also frequently used to mean that an error
occurred. You should make clear in your documentation whether [](NULL)
is a valid return value in non-error cases; if [](NULL) is a valid value,
then users must check whether an error was returned to see if the
function succeeded.

- When implementing a function that can report errors, you may want
to add a check at the top of your function that the error return
location is either [](NULL) or contains a [](NULL) error (e.g.
`g_return_if_fail (error == NULL || *error == NULL);`).
