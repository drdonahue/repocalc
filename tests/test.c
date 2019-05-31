#include <check.h>
#include "../stack.h"
#include "../corefuncs.h"
#include "../trigfuncs.h"
#include "test_stack.h"
#include "test_corefuncs.h"
#include "test_trigfuncs.h"








int main (void)
{
    int number_failed;
    Suite *s_stack,*s_math, *s_trig;
    SRunner *sr_stack,*sr_math, *sr_trig;
    s_stack = stack_suite();
    sr_stack = srunner_create(s_stack);
    s_math = math_suite();
    sr_math = srunner_create(s_math);
    s_trig = trig_suite();
    sr_trig = srunner_create(s_trig);


    srunner_run_all(sr_stack, CK_NORMAL);
    srunner_run_all(sr_math, CK_NORMAL);
    srunner_run_all(sr_trig, CK_NORMAL);
    
    number_failed = srunner_ntests_failed(sr_stack) + srunner_ntests_failed(sr_math) + srunner_ntests_failed(sr_trig);
    srunner_free(sr_stack);
    srunner_free(sr_math);
    srunner_free(sr_trig);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
