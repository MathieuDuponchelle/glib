### date-time

a structure representing Date and Time

 [](GDateTime) is a structure that combines a Gregorian date and time
 into a single structure.  It provides many conversion and methods to
 manipulate dates and times.  Time precision is provided down to
 microseconds and the time can range (proleptically) from 0001-01-01
 00:00:00 to 9999-12-31 23:59:59.999999.  [](GDateTime) follows POSIX
 time in the sense that it is oblivious to leap seconds.

 [](GDateTime) is an immutable object; once it has been created it cannot
 be modified further.  All modifiers will create a new [](GDateTime).
 Nearly all such functions can fail due to the date or time going out
 of range, in which case [](NULL) will be returned.

 [](GDateTime) is reference counted: the reference count is increased by calling
 [](g_date_time_ref) and decreased by calling [](g_date_time_unref). When the
 reference count drops to 0, the resources allocated by the [](GDateTime)
 structure are released.

 Many parts of the API may produce non-obvious results.  As an
 example, adding two months to January 31st will yield March 31st
 whereas adding one month and then one month again will yield either
 March 28th or March 29th.  Also note that adding 24 hours is not
 always the same as adding one day (since days containing daylight
 savings time transitions are either 23 or 25 hours in length).

 [](GDateTime) is available since GLib 2.26.

* [GTimeSpan]()
* [G_TIME_SPAN_DAY]()
* [G_TIME_SPAN_HOUR]()
* [G_TIME_SPAN_MINUTE]()
* [G_TIME_SPAN_SECOND]()
* [G_TIME_SPAN_MILLISECOND]()
* [GDateTime]()
* [g_date_time_unref]()
* [g_date_time_ref]()
* [g_date_time_new_now]()
* [g_date_time_new_now_local]()
* [g_date_time_new_now_utc]()
* [g_date_time_new_from_unix_local]()
* [g_date_time_new_from_unix_utc]()
* [g_date_time_new_from_timeval_local]()
* [g_date_time_new_from_timeval_utc]()
* [g_date_time_new]()
* [g_date_time_new_local]()
* [g_date_time_new_utc]()
* [g_date_time_add]()
* [g_date_time_add_years]()
* [g_date_time_add_months]()
* [g_date_time_add_weeks]()
* [g_date_time_add_days]()
* [g_date_time_add_hours]()
* [g_date_time_add_minutes]()
* [g_date_time_add_seconds]()
* [g_date_time_add_full]()
* [g_date_time_compare]()
* [g_date_time_difference]()
* [g_date_time_hash]()
* [g_date_time_equal]()
* [g_date_time_get_ymd]()
* [g_date_time_get_year]()
* [g_date_time_get_month]()
* [g_date_time_get_day_of_month]()
* [g_date_time_get_week_numbering_year]()
* [g_date_time_get_week_of_year]()
* [g_date_time_get_day_of_week]()
* [g_date_time_get_day_of_year]()
* [g_date_time_get_hour]()
* [g_date_time_get_minute]()
* [g_date_time_get_second]()
* [g_date_time_get_microsecond]()
* [g_date_time_get_seconds]()
* [g_date_time_to_unix]()
* [g_date_time_to_timeval]()
* [g_date_time_get_utc_offset]()
* [g_date_time_get_timezone_abbreviation]()
* [g_date_time_is_daylight_savings]()
* [g_date_time_to_timezone]()
* [g_date_time_to_local]()
* [g_date_time_to_utc]()
* [g_date_time_format]()
