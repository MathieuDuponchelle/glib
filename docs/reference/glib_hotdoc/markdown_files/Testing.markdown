### Testing

a test framework

 GLib provides a framework for writing and maintaining unit tests
 in parallel to the code they are testing. The API is designed according
 to established concepts found in the other test frameworks (JUnit, NUnit,
 RUnit), which in turn is based on smalltalk unit testing concepts.

 - Test case: Tests (test methods) are grouped together with their
   fixture into test cases.

 - Fixture: A test fixture consists of fixture data and setup and
   teardown methods to establish the environment for the test
   functions. We use fresh fixtures, i.e. fixtures are newly set
   up and torn down around each test invocation to avoid dependencies
   between tests.

 - Test suite: Test cases can be grouped into test suites, to allow
   subsets of the available tests to be run. Test suites can be
   grouped into other test suites as well.

 The API is designed to handle creation and registration of test suites
 and test cases implicitly. A simple call like
 
```C
 
   g_test_add_func ("/misc/assertions", test_assertions);
 
```

 creates a test suite called "misc" with a single test case named
 "assertions", which consists of running the test_assertions function.

 In addition to the traditional [](g_assert), the test framework provides
 an extended set of assertions for string and numerical comparisons:
 [](g_assert_cmpfloat), [](g_assert_cmpint), [](g_assert_cmpuint),
 [](g_assert_cmphex), [](g_assert_cmpstr). The advantage of these variants
 over plain [](g_assert) is that the assertion messages can be more
 elaborate, and include the values of the compared entities.

 GLib ships with two utilities called [gtester][gtester] and
 [gtester-report][gtester-report] to facilitate running tests and producing
 nicely formatted test reports.

 A full example of creating a test suite with two tests using fixtures:
 
```C

 [](include) <glib.h>
 [](include) <locale.h>

 typedef struct {
   MyObject *obj;
   OtherObject *helper;
 } MyObjectFixture;

 static void
 my_object_fixture_set_up (MyObjectFixture *fixture,
                           gconstpointer user_data)
 {
   fixture->obj = [](my_object_new);
   my_object_set_prop1 (fixture->obj, "some-value");
   my_object_do_some_complex_setup (fixture->obj, user_data);

   fixture->helper = [](other_object_new);
 }

 static void
 my_object_fixture_tear_down (MyObjectFixture *fixture,
                              gconstpointer user_data)
 {
   g_clear_object (&fixture->helper);
   g_clear_object (&fixture->obj);
 }

 static void
 test_my_object_test1 (MyObjectFixture *fixture,
                       gconstpointer user_data)
 {
   g_assert_cmpstr (my_object_get_property (fixture->obj), ==, "initial-value");
 }

 static void
 test_my_object_test2 (MyObjectFixture *fixture,
                       gconstpointer user_data)
 {
   my_object_do_some_work_using_helper (fixture->obj, fixture->helper);
   g_assert_cmpstr (my_object_get_property (fixture->obj), ==, "updated-value");
 }

 int
 main (int argc, char *argv[])
 {
   setlocale (LC_ALL, "");

   g_test_init (&argc, &argv, NULL);
   g_test_bug_base ("http://bugzilla.gnome.org/show_bug.cgi?id=");

   // Define the tests.
   g_test_add ("/my-object/test1", MyObjectFixture, "some-user-data",
               my_object_fixture_set_up, test_my_object_test1,
               my_object_fixture_tear_down);
   g_test_add ("/my-object/test2", MyObjectFixture, "some-user-data",
               my_object_fixture_set_up, test_my_object_test2,
               my_object_fixture_tear_down);

   return [](g_test_run);
 }
 
```


* [g_test_minimized_result]()
* [g_test_maximized_result]()
* [g_test_init]()
* [g_test_initialized]()
* [g_test_quick]()
* [g_test_slow]()
* [g_test_thorough]()
* [g_test_perf]()
* [g_test_verbose]()
* [g_test_undefined]()
* [g_test_quiet]()
* [g_test_subprocess]()
* [g_test_run]()
* [GTestFunc]()
* [g_test_add_func]()
* [GTestDataFunc]()
* [g_test_add_data_func]()
* [g_test_add_data_func_full]()
* [g_test_add]()
* [GTestFileType]()
* [g_test_build_filename]()
* [g_test_get_filename]()
* [g_test_get_dir]()
* [g_test_fail]()
* [g_test_skip]()
* [g_test_incomplete]()
* [g_test_failed]()
* [g_test_message]()
* [g_test_bug_base]()
* [g_test_bug]()
* [GTestLogFatalFunc]()
* [g_test_log_set_fatal_handler]()
* [g_test_timer_start]()
* [g_test_timer_elapsed]()
* [g_test_timer_last]()
* [g_test_queue_free]()
* [g_test_queue_destroy]()
* [g_test_queue_unref]()
* [g_test_expect_message]()
* [g_test_assert_expected_messages]()
* [GTestTrapFlags]()
* [GTestSubprocessFlags]()
* [g_test_trap_subprocess]()
* [g_test_trap_has_passed]()
* [g_test_trap_reached_timeout]()
* [g_test_trap_assert_passed]()
* [g_test_trap_assert_failed]()
* [g_test_trap_assert_stdout]()
* [g_test_trap_assert_stdout_unmatched]()
* [g_test_trap_assert_stderr]()
* [g_test_trap_assert_stderr_unmatched]()
* [g_test_trap_fork]()
* [g_test_rand_bit]()
* [g_test_rand_int]()
* [g_test_rand_int_range]()
* [g_test_rand_double]()
* [g_test_rand_double_range]()
* [g_assert]()
* [g_assert_not_reached]()
* [g_assert_cmpstr]()
* [g_assert_cmpint]()
* [g_assert_cmpuint]()
* [g_assert_cmphex]()
* [g_assert_cmpfloat]()
* [g_assert_no_error]()
* [g_assert_error]()
* [g_assert_true]()
* [g_assert_false]()
* [g_assert_null]()
* [g_assert_nonnull]()
* [g_test_set_nonfatal_assertions]()
* [GTestCase]()
* [GTestSuite]()
* [GTestFixtureFunc]()
* [g_test_create_case]()
* [g_test_create_suite]()
* [g_test_get_root]()
* [g_test_suite_add]()
* [g_test_suite_add_suite]()
* [g_test_run_suite]()
* [g_test_trap_assertions]()
* [g_assertion_message]()
* [g_assertion_message_expr]()
* [g_assertion_message_cmpstr]()
* [g_assertion_message_cmpnum]()
* [g_assertion_message_error]()
* [g_test_assert_expected_messages_internal]()
* [g_test_config_vars]()
* [g_test_add_vtable]()
* [GTestConfig]()
* [GTestLogType]()
* [GTestLogMsg]()
* [GTestLogBuffer]()
* [g_test_log_type_name]()
* [g_test_log_buffer_new]()
* [g_test_log_buffer_free]()
* [g_test_log_buffer_push]()
* [g_test_log_buffer_pop]()
* [g_test_log_msg_free]()
