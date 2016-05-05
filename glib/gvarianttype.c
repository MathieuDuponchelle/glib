/*
 * Copyright © 2007, 2008 Ryan Lortie
 * Copyright © 2009, 2010 Codethink Limited
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the licence, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Ryan Lortie <desrt@desrt.ca>
 */

#include "config.h"

#include "gvarianttype.h"

#include <glib/gtestutils.h>
#include <glib/gstrfuncs.h>

#include <string.h>





static gboolean
g_variant_type_check (const GVariantType *type)
{
  if (type == NULL)
    return FALSE;

#if 0
  return g_variant_type_string_scan ((const gchar *) type, NULL, NULL);
#else
  return TRUE;
#endif
}

/**
 * g_variant_type_string_scan:
 * @string: a pointer to any string
 * @limit: (allow-none): the end of @string, or %NULL
 * @endptr: (out) (allow-none): location to store the end pointer, or %NULL
 *
 * Scan for a single complete and valid GVariant type string in @string.
 * The memory pointed to by @limit (or bytes beyond it) is never
 * accessed.
 *
 * If a valid type string is found, @endptr is updated to point to the
 * first character past the end of the string that was found and %TRUE
 * is returned.
 *
 * If there is no valid type string starting at @string, or if the type
 * string does not end before @limit then %FALSE is returned.
 *
 * For the simple case of checking if a string is a valid type string,
 * see g_variant_type_string_is_valid().
 *
 * Returns: %TRUE if a valid type string was found
 *
 * Since: 2.24
 **/
gboolean
g_variant_type_string_scan (const gchar  *string,
                            const gchar  *limit,
                            const gchar **endptr)
{
  g_return_val_if_fail (string != NULL, FALSE);

  if (string == limit || *string == '\0')
    return FALSE;

  switch (*string++)
    {
    case '(':
      while (string == limit || *string != ')')
        if (!g_variant_type_string_scan (string, limit, &string))
          return FALSE;

      string++;
      break;

    case '{':
      if (string == limit || *string == '\0' ||                    /* { */
          !strchr ("bynqihuxtdsog?", *string++) ||                 /* key */
          !g_variant_type_string_scan (string, limit, &string) ||  /* value */
          string == limit || *string++ != '}')                     /* } */
        return FALSE;

      break;

    case 'm': case 'a':
      return g_variant_type_string_scan (string, limit, endptr);

    case 'b': case 'y': case 'n': case 'q': case 'i': case 'u':
    case 'x': case 't': case 'd': case 's': case 'o': case 'g':
    case 'v': case 'r': case '*': case '?': case 'h':
      break;

    default:
      return FALSE;
    }

  if (endptr != NULL)
    *endptr = string;

  return TRUE;
}

/**
 * g_variant_type_string_is_valid:
 * @type_string: a pointer to any string
 *
 * Checks if @type_string is a valid GVariant type string.  This call is
 * equivalent to calling g_variant_type_string_scan() and confirming
 * that the following character is a nul terminator.
 *
 * Returns: %TRUE if @type_string is exactly one valid type string
 *
 * Since 2.24
 **/
gboolean
g_variant_type_string_is_valid (const gchar *type_string)
{
  const gchar *endptr;

  g_return_val_if_fail (type_string != NULL, FALSE);

  if (!g_variant_type_string_scan (type_string, NULL, &endptr))
    return FALSE;

  return *endptr == '\0';
}

/**
 * g_variant_type_free:
 * @type: (allow-none): a #GVariantType, or %NULL
 *
 * Frees a #GVariantType that was allocated with
 * g_variant_type_copy(), g_variant_type_new() or one of the container
 * type constructor functions.
 *
 * In the case that @type is %NULL, this function does nothing.
 *
 * Since 2.24
 **/
void
g_variant_type_free (GVariantType *type)
{
  g_return_if_fail (type == NULL || g_variant_type_check (type));

  g_free (type);
}

/**
 * g_variant_type_copy:
 * @type: a #GVariantType
 *
 * Makes a copy of a #GVariantType.  It is appropriate to call
 * g_variant_type_free() on the return value.  @type may not be %NULL.
 *
 * Returns: (transfer full): a new #GVariantType
 *
 * Since 2.24
 **/
GVariantType *
g_variant_type_copy (const GVariantType *type)
{
  gsize length;
  gchar *new;

  g_return_val_if_fail (g_variant_type_check (type), NULL);

  length = g_variant_type_get_string_length (type);
  new = g_malloc (length + 1);

  memcpy (new, type, length);
  new[length] = '\0';

  return (GVariantType *) new;
}

/**
 * g_variant_type_new:
 * @type_string: a valid GVariant type string
 *
 * Creates a new #GVariantType corresponding to the type string given
 * by @type_string.  It is appropriate to call g_variant_type_free() on
 * the return value.
 *
 * It is a programmer error to call this function with an invalid type
 * string.  Use g_variant_type_string_is_valid() if you are unsure.
 *
 * Returns: (transfer full): a new #GVariantType
 *
 * Since: 2.24
 */
GVariantType *
g_variant_type_new (const gchar *type_string)
{
  g_return_val_if_fail (type_string != NULL, NULL);

  return g_variant_type_copy (G_VARIANT_TYPE (type_string));
}

/**
 * g_variant_type_get_string_length:
 * @type: a #GVariantType
 *
 * Returns the length of the type string corresponding to the given
 * @type.  This function must be used to determine the valid extent of
 * the memory region returned by g_variant_type_peek_string().
 *
 * Returns: the length of the corresponding type string
 *
 * Since 2.24
 **/
gsize
g_variant_type_get_string_length (const GVariantType *type)
{
  const gchar *type_string = (const gchar *) type;
  gint brackets = 0;
  gsize index = 0;

  g_return_val_if_fail (g_variant_type_check (type), 0);

  do
    {
      while (type_string[index] == 'a' || type_string[index] == 'm')
        index++;

      if (type_string[index] == '(' || type_string[index] == '{')
        brackets++;

      else if (type_string[index] == ')' || type_string[index] == '}')
        brackets--;

      index++;
    }
  while (brackets);

  return index;
}

/*
  This function is not introspectable, it returns something that
  is not an array and neither a string
*/
/**
 * g_variant_type_peek_string: (skip)
 * @type: a #GVariantType
 *
 * Returns the type string corresponding to the given @type.  The
 * result is not nul-terminated; in order to determine its length you
 * must call g_variant_type_get_string_length().
 *
 * To get a nul-terminated string, see g_variant_type_dup_string().
 *
 * Returns: the corresponding type string (not nul-terminated)
 *
 * Since 2.24
 **/
const gchar *
g_variant_type_peek_string (const GVariantType *type)
{
  g_return_val_if_fail (g_variant_type_check (type), NULL);

  return (const gchar *) type;
}

/**
 * g_variant_type_dup_string:
 * @type: a #GVariantType
 *
 * Returns a newly-allocated copy of the type string corresponding to
 * @type.  The returned string is nul-terminated.  It is appropriate to
 * call g_free() on the return value.
 *
 * Returns: (transfer full): the corresponding type string
 *
 * Since 2.24
 **/
gchar *
g_variant_type_dup_string (const GVariantType *type)
{
  g_return_val_if_fail (g_variant_type_check (type), NULL);

  return g_strndup (g_variant_type_peek_string (type),
                    g_variant_type_get_string_length (type));
}

/**
 * g_variant_type_is_definite:
 * @type: a #GVariantType
 *
 * Determines if the given @type is definite (ie: not indefinite).
 *
 * A type is definite if its type string does not contain any indefinite
 * type characters ('*', '?', or 'r').
 *
 * A #GVariant instance may not have an indefinite type, so calling
 * this function on the result of g_variant_get_type() will always
 * result in %TRUE being returned.  Calling this function on an
 * indefinite type like %G_VARIANT_TYPE_ARRAY, however, will result in
 * %FALSE being returned.
 *
 * Returns: %TRUE if @type is definite
 *
 * Since 2.24
 **/
gboolean
g_variant_type_is_definite (const GVariantType *type)
{
  const gchar *type_string;
  gsize type_length;
  gsize i;

  g_return_val_if_fail (g_variant_type_check (type), FALSE);

  type_length = g_variant_type_get_string_length (type);
  type_string = g_variant_type_peek_string (type);

  for (i = 0; i < type_length; i++)
    if (type_string[i] == '*' ||
        type_string[i] == '?' ||
        type_string[i] == 'r')
      return FALSE;

  return TRUE;
}

/**
 * g_variant_type_is_container:
 * @type: a #GVariantType
 *
 * Determines if the given @type is a container type.
 *
 * Container types are any array, maybe, tuple, or dictionary
 * entry types plus the variant type.
 *
 * This function returns %TRUE for any indefinite type for which every
 * definite subtype is a container -- %G_VARIANT_TYPE_ARRAY, for
 * example.
 *
 * Returns: %TRUE if @type is a container type
 *
 * Since 2.24
 **/
gboolean
g_variant_type_is_container (const GVariantType *type)
{
  gchar first_char;

  g_return_val_if_fail (g_variant_type_check (type), FALSE);

  first_char = g_variant_type_peek_string (type)[0];
  switch (first_char)
  {
    case 'a':
    case 'm':
    case 'r':
    case '(':
    case '{':
    case 'v':
      return TRUE;

    default:
      return FALSE;
  }
}

/**
 * g_variant_type_is_basic:
 * @type: a #GVariantType
 *
 * Determines if the given @type is a basic type.
 *
 * Basic types are booleans, bytes, integers, doubles, strings, object
 * paths and signatures.
 *
 * Only a basic type may be used as the key of a dictionary entry.
 *
 * This function returns %FALSE for all indefinite types except
 * %G_VARIANT_TYPE_BASIC.
 *
 * Returns: %TRUE if @type is a basic type
 *
 * Since 2.24
 **/
gboolean
g_variant_type_is_basic (const GVariantType *type)
{
  gchar first_char;

  g_return_val_if_fail (g_variant_type_check (type), FALSE);

  first_char = g_variant_type_peek_string (type)[0];
  switch (first_char)
  {
    case 'b':
    case 'y':
    case 'n':
    case 'q':
    case 'i':
    case 'h':
    case 'u':
    case 't':
    case 'x':
    case 'd':
    case 's':
    case 'o':
    case 'g':
    case '?':
      return TRUE;

    default:
      return FALSE;
  }
}

/**
 * g_variant_type_is_maybe:
 * @type: a #GVariantType
 *
 * Determines if the given @type is a maybe type.  This is true if the
 * type string for @type starts with an 'm'.
 *
 * This function returns %TRUE for any indefinite type for which every
 * definite subtype is a maybe type -- %G_VARIANT_TYPE_MAYBE, for
 * example.
 *
 * Returns: %TRUE if @type is a maybe type
 *
 * Since 2.24
 **/
gboolean
g_variant_type_is_maybe (const GVariantType *type)
{
  g_return_val_if_fail (g_variant_type_check (type), FALSE);

  return g_variant_type_peek_string (type)[0] == 'm';
}

/**
 * g_variant_type_is_array:
 * @type: a #GVariantType
 *
 * Determines if the given @type is an array type.  This is true if the
 * type string for @type starts with an 'a'.
 *
 * This function returns %TRUE for any indefinite type for which every
 * definite subtype is an array type -- %G_VARIANT_TYPE_ARRAY, for
 * example.
 *
 * Returns: %TRUE if @type is an array type
 *
 * Since 2.24
 **/
gboolean
g_variant_type_is_array (const GVariantType *type)
{
  g_return_val_if_fail (g_variant_type_check (type), FALSE);

  return g_variant_type_peek_string (type)[0] == 'a';
}

/**
 * g_variant_type_is_tuple:
 * @type: a #GVariantType
 *
 * Determines if the given @type is a tuple type.  This is true if the
 * type string for @type starts with a '(' or if @type is
 * %G_VARIANT_TYPE_TUPLE.
 *
 * This function returns %TRUE for any indefinite type for which every
 * definite subtype is a tuple type -- %G_VARIANT_TYPE_TUPLE, for
 * example.
 *
 * Returns: %TRUE if @type is a tuple type
 *
 * Since 2.24
 **/
gboolean
g_variant_type_is_tuple (const GVariantType *type)
{
  gchar type_char;

  g_return_val_if_fail (g_variant_type_check (type), FALSE);

  type_char = g_variant_type_peek_string (type)[0];
  return type_char == 'r' || type_char == '(';
}

/**
 * g_variant_type_is_dict_entry:
 * @type: a #GVariantType
 *
 * Determines if the given @type is a dictionary entry type.  This is
 * true if the type string for @type starts with a '{'.
 *
 * This function returns %TRUE for any indefinite type for which every
 * definite subtype is a dictionary entry type --
 * %G_VARIANT_TYPE_DICT_ENTRY, for example.
 *
 * Returns: %TRUE if @type is a dictionary entry type
 *
 * Since 2.24
 **/
gboolean
g_variant_type_is_dict_entry (const GVariantType *type)
{
  g_return_val_if_fail (g_variant_type_check (type), FALSE);

  return g_variant_type_peek_string (type)[0] == '{';
}

/**
 * g_variant_type_is_variant:
 * @type: a #GVariantType
 *
 * Determines if the given @type is the variant type.
 *
 * Returns: %TRUE if @type is the variant type
 *
 * Since 2.24
 **/
gboolean
g_variant_type_is_variant (const GVariantType *type)
{
  g_return_val_if_fail (g_variant_type_check (type), FALSE);

  return g_variant_type_peek_string (type)[0] == 'v';
}

/**
 * g_variant_type_hash:
 * @type: (type GVariantType): a #GVariantType
 *
 * Hashes @type.
 *
 * The argument type of @type is only #gconstpointer to allow use with
 * #GHashTable without function pointer casting.  A valid
 * #GVariantType must be provided.
 *
 * Returns: the hash value
 *
 * Since 2.24
 **/
guint
g_variant_type_hash (gconstpointer type)
{
  const gchar *type_string;
  guint value = 0;
  gsize length;
  gsize i;

  g_return_val_if_fail (g_variant_type_check (type), 0);

  type_string = g_variant_type_peek_string (type);
  length = g_variant_type_get_string_length (type);

  for (i = 0; i < length; i++)
    value = (value << 5) - value + type_string[i];

  return value;
}

/**
 * g_variant_type_equal:
 * @type1: (type GVariantType): a #GVariantType
 * @type2: (type GVariantType): a #GVariantType
 *
 * Compares @type1 and @type2 for equality.
 *
 * Only returns %TRUE if the types are exactly equal.  Even if one type
 * is an indefinite type and the other is a subtype of it, %FALSE will
 * be returned if they are not exactly equal.  If you want to check for
 * subtypes, use g_variant_type_is_subtype_of().
 *
 * The argument types of @type1 and @type2 are only #gconstpointer to
 * allow use with #GHashTable without function pointer casting.  For
 * both arguments, a valid #GVariantType must be provided.
 *
 * Returns: %TRUE if @type1 and @type2 are exactly equal
 *
 * Since 2.24
 **/
gboolean
g_variant_type_equal (gconstpointer type1,
                      gconstpointer type2)
{
  const gchar *string1, *string2;
  gsize size1, size2;

  g_return_val_if_fail (g_variant_type_check (type1), FALSE);
  g_return_val_if_fail (g_variant_type_check (type2), FALSE);

  if (type1 == type2)
    return TRUE;

  size1 = g_variant_type_get_string_length (type1);
  size2 = g_variant_type_get_string_length (type2);

  if (size1 != size2)
    return FALSE;

  string1 = g_variant_type_peek_string (type1);
  string2 = g_variant_type_peek_string (type2);

  return memcmp (string1, string2, size1) == 0;
}

/**
 * g_variant_type_is_subtype_of:
 * @type: a #GVariantType
 * @supertype: a #GVariantType
 *
 * Checks if @type is a subtype of @supertype.
 *
 * This function returns %TRUE if @type is a subtype of @supertype.  All
 * types are considered to be subtypes of themselves.  Aside from that,
 * only indefinite types can have subtypes.
 *
 * Returns: %TRUE if @type is a subtype of @supertype
 *
 * Since 2.24
 **/
gboolean
g_variant_type_is_subtype_of (const GVariantType *type,
                              const GVariantType *supertype)
{
  const gchar *supertype_string;
  const gchar *supertype_end;
  const gchar *type_string;

  g_return_val_if_fail (g_variant_type_check (type), FALSE);
  g_return_val_if_fail (g_variant_type_check (supertype), FALSE);

  supertype_string = g_variant_type_peek_string (supertype);
  type_string = g_variant_type_peek_string (type);

  supertype_end = supertype_string +
                  g_variant_type_get_string_length (supertype);

  /* we know that type and supertype are both well-formed, so it's
   * safe to treat this merely as a text processing problem.
   */
  while (supertype_string < supertype_end)
    {
      char supertype_char = *supertype_string++;

      if (supertype_char == *type_string)
        type_string++;

      else if (*type_string == ')')
        return FALSE;

      else
        {
          const GVariantType *target_type = (GVariantType *) type_string;

          switch (supertype_char)
            {
            case 'r':
              if (!g_variant_type_is_tuple (target_type))
                return FALSE;
              break;

            case '*':
              break;

            case '?':
              if (!g_variant_type_is_basic (target_type))
                return FALSE;
              break;

            default:
              return FALSE;
            }

          type_string += g_variant_type_get_string_length (target_type);
        }
    }

  return TRUE;
}

/**
 * g_variant_type_element:
 * @type: an array or maybe #GVariantType
 *
 * Determines the element type of an array or maybe type.
 *
 * This function may only be used with array or maybe types.
 *
 * Returns: (transfer none): the element type of @type
 *
 * Since 2.24
 **/
const GVariantType *
g_variant_type_element (const GVariantType *type)
{
  const gchar *type_string;

  g_return_val_if_fail (g_variant_type_check (type), NULL);

  type_string = g_variant_type_peek_string (type);

  g_assert (type_string[0] == 'a' || type_string[0] == 'm');

  return (const GVariantType *) &type_string[1];
}

/**
 * g_variant_type_first:
 * @type: a tuple or dictionary entry #GVariantType
 *
 * Determines the first item type of a tuple or dictionary entry
 * type.
 *
 * This function may only be used with tuple or dictionary entry types,
 * but must not be used with the generic tuple type
 * %G_VARIANT_TYPE_TUPLE.
 *
 * In the case of a dictionary entry type, this returns the type of
 * the key.
 *
 * %NULL is returned in case of @type being %G_VARIANT_TYPE_UNIT.
 *
 * This call, together with g_variant_type_next() provides an iterator
 * interface over tuple and dictionary entry types.
 *
 * Returns: (transfer none): the first item type of @type, or %NULL
 *
 * Since 2.24
 **/
const GVariantType *
g_variant_type_first (const GVariantType *type)
{
  const gchar *type_string;

  g_return_val_if_fail (g_variant_type_check (type), NULL);

  type_string = g_variant_type_peek_string (type);
  g_assert (type_string[0] == '(' || type_string[0] == '{');

  if (type_string[1] == ')')
    return NULL;

  return (const GVariantType *) &type_string[1];
}

/**
 * g_variant_type_next:
 * @type: a #GVariantType from a previous call
 *
 * Determines the next item type of a tuple or dictionary entry
 * type.
 *
 * @type must be the result of a previous call to
 * g_variant_type_first() or g_variant_type_next().
 *
 * If called on the key type of a dictionary entry then this call
 * returns the value type.  If called on the value type of a dictionary
 * entry then this call returns %NULL.
 *
 * For tuples, %NULL is returned when @type is the last item in a tuple.
 *
 * Returns: (transfer none): the next #GVariantType after @type, or %NULL
 *
 * Since 2.24
 **/
const GVariantType *
g_variant_type_next (const GVariantType *type)
{
  const gchar *type_string;

  g_return_val_if_fail (g_variant_type_check (type), NULL);

  type_string = g_variant_type_peek_string (type);
  type_string += g_variant_type_get_string_length (type);

  if (*type_string == ')' || *type_string == '}')
    return NULL;

  return (const GVariantType *) type_string;
}

/**
 * g_variant_type_n_items:
 * @type: a tuple or dictionary entry #GVariantType
 *
 * Determines the number of items contained in a tuple or
 * dictionary entry type.
 *
 * This function may only be used with tuple or dictionary entry types,
 * but must not be used with the generic tuple type
 * %G_VARIANT_TYPE_TUPLE.
 *
 * In the case of a dictionary entry type, this function will always
 * return 2.
 *
 * Returns: the number of items in @type
 *
 * Since 2.24
 **/
gsize
g_variant_type_n_items (const GVariantType *type)
{
  gsize count = 0;

  g_return_val_if_fail (g_variant_type_check (type), 0);

  for (type = g_variant_type_first (type);
       type;
       type = g_variant_type_next (type))
    count++;

  return count;
}

/**
 * g_variant_type_key:
 * @type: a dictionary entry #GVariantType
 *
 * Determines the key type of a dictionary entry type.
 *
 * This function may only be used with a dictionary entry type.  Other
 * than the additional restriction, this call is equivalent to
 * g_variant_type_first().
 *
 * Returns: (transfer none): the key type of the dictionary entry
 *
 * Since 2.24
 **/
const GVariantType *
g_variant_type_key (const GVariantType *type)
{
  const gchar *type_string;

  g_return_val_if_fail (g_variant_type_check (type), NULL);

  type_string = g_variant_type_peek_string (type);
  g_assert (type_string[0] == '{');

  return (const GVariantType *) &type_string[1];
}

/**
 * g_variant_type_value:
 * @type: a dictionary entry #GVariantType
 *
 * Determines the value type of a dictionary entry type.
 *
 * This function may only be used with a dictionary entry type.
 *
 * Returns: (transfer none): the value type of the dictionary entry
 *
 * Since 2.24
 **/
const GVariantType *
g_variant_type_value (const GVariantType *type)
{
  const gchar *type_string;

  g_return_val_if_fail (g_variant_type_check (type), NULL);

  type_string = g_variant_type_peek_string (type);
  g_assert (type_string[0] == '{');

  return g_variant_type_next (g_variant_type_key (type));
}

/**
 * g_variant_type_new_tuple:
 * @items: (array length=length): an array of #GVariantTypes, one for each item
 * @length: the length of @items, or -1
 *
 * Constructs a new tuple type, from @items.
 *
 * @length is the number of items in @items, or -1 to indicate that
 * @items is %NULL-terminated.
 *
 * It is appropriate to call g_variant_type_free() on the return value.
 *
 * Returns: (transfer full): a new tuple #GVariantType
 *
 * Since 2.24
 **/
static GVariantType *
g_variant_type_new_tuple_slow (const GVariantType * const *items,
                               gint                        length)
{
  /* the "slow" version is needed in case the static buffer of 1024
   * bytes is exceeded when running the normal version.  this will
   * happen only in truly insane code, so it can be slow.
   */
  GString *string;
  gsize i;

  string = g_string_new ("(");
  for (i = 0; i < length; i++)
    {
      const GVariantType *type;
      gsize size;

      g_return_val_if_fail (g_variant_type_check (items[i]), NULL);

      type = items[i];
      size = g_variant_type_get_string_length (type);
      g_string_append_len (string, (const gchar *) type, size);
    }
  g_string_append_c (string, ')');

  return (GVariantType *) g_string_free (string, FALSE);
}

GVariantType *
g_variant_type_new_tuple (const GVariantType * const *items,
                          gint                        length)
{
  char buffer[1024];
  gsize offset;
  gsize i;

  g_return_val_if_fail (length == 0 || items != NULL, NULL);

  if (length < 0)
    for (length = 0; items[length] != NULL; length++);

  offset = 0;
  buffer[offset++] = '(';

  for (i = 0; i < length; i++)
    {
      const GVariantType *type;
      gsize size;

      g_return_val_if_fail (g_variant_type_check (items[i]), NULL);

      type = items[i];
      size = g_variant_type_get_string_length (type);

      if (offset + size >= sizeof buffer) /* leave room for ')' */
        return g_variant_type_new_tuple_slow (items, length);

      memcpy (&buffer[offset], type, size);
      offset += size;
    }

  g_assert (offset < sizeof buffer);
  buffer[offset++] = ')';

  return (GVariantType *) g_memdup (buffer, offset);
}

/**
 * g_variant_type_new_array: (constructor)
 * @element: a #GVariantType
 *
 * Constructs the type corresponding to an array of elements of the
 * type @type.
 *
 * It is appropriate to call g_variant_type_free() on the return value.
 *
 * Returns: (transfer full): a new array #GVariantType
 *
 * Since 2.24
 **/
GVariantType *
g_variant_type_new_array (const GVariantType *element)
{
  gsize size;
  gchar *new;

  g_return_val_if_fail (g_variant_type_check (element), NULL);

  size = g_variant_type_get_string_length (element);
  new = g_malloc (size + 1);

  new[0] = 'a';
  memcpy (new + 1, element, size);

  return (GVariantType *) new;
}

/**
 * g_variant_type_new_maybe: (constructor)
 * @element: a #GVariantType
 *
 * Constructs the type corresponding to a maybe instance containing
 * type @type or Nothing.
 *
 * It is appropriate to call g_variant_type_free() on the return value.
 *
 * Returns: (transfer full): a new maybe #GVariantType
 *
 * Since 2.24
 **/
GVariantType *
g_variant_type_new_maybe (const GVariantType *element)
{
  gsize size;
  gchar *new;

  g_return_val_if_fail (g_variant_type_check (element), NULL);

  size = g_variant_type_get_string_length (element);
  new = g_malloc (size + 1);

  new[0] = 'm';
  memcpy (new + 1, element, size);

  return (GVariantType *) new;
}

/**
 * g_variant_type_new_dict_entry: (constructor)
 * @key: a basic #GVariantType
 * @value: a #GVariantType
 *
 * Constructs the type corresponding to a dictionary entry with a key
 * of type @key and a value of type @value.
 *
 * It is appropriate to call g_variant_type_free() on the return value.
 *
 * Returns: (transfer full): a new dictionary entry #GVariantType
 *
 * Since 2.24
 **/
GVariantType *
g_variant_type_new_dict_entry (const GVariantType *key,
                               const GVariantType *value)
{
  gsize keysize, valsize;
  gchar *new;

  g_return_val_if_fail (g_variant_type_check (key), NULL);
  g_return_val_if_fail (g_variant_type_check (value), NULL);

  keysize = g_variant_type_get_string_length (key);
  valsize = g_variant_type_get_string_length (value);

  new = g_malloc (1 + keysize + valsize + 1);

  new[0] = '{';
  memcpy (new + 1, key, keysize);
  memcpy (new + 1 + keysize, value, valsize);
  new[1 + keysize + valsize] = '}';

  return (GVariantType *) new;
}

/* private */
const GVariantType *
g_variant_type_checked_ (const gchar *type_string)
{
  g_return_val_if_fail (g_variant_type_string_is_valid (type_string), NULL);
  return (const GVariantType *) type_string;
}
