---
short-description: !!python/unicode 'parses a subset of XML'
symbols:
- GMarkupParser
- g_markup_escape_text
- g_markup_parse_context_free
- g_markup_vprintf_escaped
- GMarkupError
- g_markup_error_quark
- g_markup_parse_context_get_element
- GMarkupCollectType
- g_markup_parse_context_new
- g_markup_parse_context_end_parse
- GMarkupParseContext
- g_markup_collect_attributes
- g_markup_parse_context_get_position
- g_markup_printf_escaped
- g_markup_parse_context_get_element_stack
- GMarkupParseFlags
- g_markup_parse_context_pop
- g_markup_parse_context_parse
- g_markup_parse_context_unref
- g_markup_parse_context_get_user_data
- g_markup_parse_context_push
- G_MARKUP_ERROR
- g_markup_parse_context_ref
title: !!python/unicode 'Simple XML Subset Parser'
...

The "GMarkup" parser is intended to parse a simple markup format
that's a subset of XML. This is a small, efficient, easy-to-use
parser. It should not be used if you expect to interoperate with
other applications generating full-scale XML. However, it's very
useful for application data files, config files, etc. where you
know your application will be the only one writing the file.
Full-scale XML parsers should be able to parse the subset used by
GMarkup, so you can easily migrate to full-scale XML at a later
time if the need arises.

GMarkup is not guaranteed to signal an error on all invalid XML;
the parser may accept documents that an XML parser would not.
However, XML documents which are not well-formed (which is a
weaker condition than being valid. See the
[XML specification](http://www.w3.org/TR/REC-xml/)
for definitions of these terms.) are not considered valid GMarkup
documents.

Simplifications to XML include:

- Only UTF-8 encoding is allowed

- No user-defined entities

- Processing instructions, comments and the doctype declaration
are "passed through" but are not interpreted in any way

- No DTD or validation

The markup format does support:

- Elements

- Attributes

- 5 standard entities: &amp;amp; &amp;lt; &amp;gt; &amp;quot; &amp;apos;

- Character references

- Sections marked as CDATA
