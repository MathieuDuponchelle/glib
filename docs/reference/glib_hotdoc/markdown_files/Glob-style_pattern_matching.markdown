### Glob-style_pattern_matching

matches strings against patterns containing '*'
                     (wildcard) and '?' (joker)

 The g_pattern_match* functions match a string
 against a pattern containing '*' and '?' wildcards with similar
 semantics as the standard [](glob) function: '*' matches an arbitrary,
 possibly empty, string, '?' matches an arbitrary character.

 Note that in contrast to [](glob), the '/' character can be matched by
 the wildcards, there are no '[...]' character ranges and '*' and '?'
 can not be escaped to include them literally in a pattern.

 When multiple strings must be matched against the same pattern, it
 is better to compile the pattern to a [](GPatternSpec) using
 [](g_pattern_spec_new) and use [](g_pattern_match_string) instead of
 [](g_pattern_match_simple). This avoids the overhead of repeated
 pattern compilation.

* [GPatternSpec]()
* [g_pattern_spec_new]()
* [g_pattern_spec_free]()
* [g_pattern_spec_equal]()
* [g_pattern_match]()
* [g_pattern_match_string]()
* [g_pattern_match_simple]()
