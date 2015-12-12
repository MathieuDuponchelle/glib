### Date_and_Time_Functions

calendrical calculations and miscellaneous time stuff

 The [](GDate) data structure represents a day between January 1, Year 1,
 and sometime a few thousand years in the future (right now it will go
 to the year 65535 or so, but [](g_date_set_parse) only parses up to the
 year 8000 or so - just count on "a few thousand"). [](GDate) is meant to
 represent everyday dates, not astronomical dates or historical dates
 or ISO timestamps or the like. It extrapolates the current Gregorian
 calendar forward and backward in time; there is no attempt to change
 the calendar to match time periods or locations. [](GDate) does not store
 time information; it represents a day.

 The [](GDate) implementation has several nice features; it is only a
 64-bit struct, so storing large numbers of dates is very efficient. It
 can keep both a Julian and day-month-year representation of the date,
 since some calculations are much easier with one representation or the
 other. A Julian representation is simply a count of days since some
 fixed day in the past; for [](GDate) the fixed day is January 1, 1 AD.
 ("Julian" dates in the [](GDate) API aren't really Julian dates in the
 technical sense; technically, Julian dates count from the start of the
 Julian period, Jan 1, 4713 BC).

 [](GDate) is simple to use. First you need a "blank" date; you can get a
 dynamically allocated date from [](g_date_new), or you can declare an
 automatic variable or array and initialize it to a sane state by
 calling [](g_date_clear). A cleared date is sane; it's safe to call
 [](g_date_set_dmy) and the other mutator functions to initialize the
 value of a cleared date. However, a cleared date is initially
 invalid, meaning that it doesn't represent a day that exists.
 It is undefined to call any of the date calculation routines on an
 invalid date. If you obtain a date from a user or other
 unpredictable source, you should check its validity with the
 [](g_date_valid) predicate. [](g_date_valid) is also used to check for
 errors with [](g_date_set_parse) and other functions that can
 fail. Dates can be invalidated by calling [](g_date_clear) again.

 It is very important to use the API to access the [](GDate)
 struct. Often only the day-month-year or only the Julian
 representation is valid. Sometimes neither is valid. Use the API.

 GLib also features [](GDateTime) which represents a precise time.

* [G_USEC_PER_SEC]()
* [GTimeVal]()
* [g_get_current_time]()
* [g_usleep]()
* [g_time_val_add]()
* [g_time_val_from_iso8601]()
* [g_time_val_to_iso8601]()
* [g_get_monotonic_time]()
* [g_get_real_time]()
* [GDate]()
* [GTime]()
* [GDateDMY]()
* [GDateDay]()
* [GDateMonth]()
* [GDateYear]()
* [GDateWeekday]()
* [G_DATE_BAD_DAY]()
* [G_DATE_BAD_JULIAN]()
* [G_DATE_BAD_YEAR]()
* [g_date_new]()
* [g_date_new_dmy]()
* [g_date_new_julian]()
* [g_date_clear]()
* [g_date_free]()
* [g_date_set_day]()
* [g_date_set_month]()
* [g_date_set_year]()
* [g_date_set_dmy]()
* [g_date_set_julian]()
* [g_date_set_time]()
* [g_date_set_time_t]()
* [g_date_set_time_val]()
* [g_date_set_parse]()
* [g_date_add_days]()
* [g_date_subtract_days]()
* [g_date_add_months]()
* [g_date_subtract_months]()
* [g_date_add_years]()
* [g_date_subtract_years]()
* [g_date_days_between]()
* [g_date_compare]()
* [g_date_clamp]()
* [g_date_order]()
* [g_date_get_day]()
* [g_date_get_month]()
* [g_date_get_year]()
* [g_date_get_julian]()
* [g_date_get_weekday]()
* [g_date_get_day_of_year]()
* [g_date_get_days_in_month]()
* [g_date_is_first_of_month]()
* [g_date_is_last_of_month]()
* [g_date_is_leap_year]()
* [g_date_get_monday_week_of_year]()
* [g_date_get_monday_weeks_in_year]()
* [g_date_get_sunday_week_of_year]()
* [g_date_get_sunday_weeks_in_year]()
* [g_date_get_iso8601_week_of_year]()
* [g_date_strftime]()
* [g_date_to_struct_tm]()
* [g_date_valid]()
* [g_date_valid_day]()
* [g_date_valid_month]()
* [g_date_valid_year]()
* [g_date_valid_dmy]()
* [g_date_valid_julian]()
* [g_date_valid_weekday]()
* [g_date_weekday]()
* [g_date_month]()
* [g_date_year]()
* [g_date_day]()
* [g_date_julian]()
* [g_date_day_of_year]()
* [g_date_monday_week_of_year]()
* [g_date_sunday_week_of_year]()
* [g_date_days_in_month]()
* [g_date_monday_weeks_in_year]()
* [g_date_sunday_weeks_in_year]()
