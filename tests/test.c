#include <check.h>
#include "../stack.h"

START_TEST (test_stack_push_pop_single)
{
    stk_elem * stack = NULL;

    push(&stack, 2.5);
    ck_assert_msg(stack->val == 2.5, "push failed\n");
    
    ck_assert_msg(pop(&stack) == 2.5, "pop did not return correct value");

    ck_assert_msg(stack == NULL, "pop did not remove the top emement");
}
END_TEST

START_TEST (test_stack_push_pop_multi)
{
    stk_elem * stack = NULL;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    ck_assert_msg(pop(&stack) == 3, "pop did not return correct value");

    ck_assert_msg(pop(&stack) == 2, "pop did not return correct value");

    ck_assert_msg(pop(&stack) == 1, "pop did not return correct value");
}
END_TEST

START_TEST (test_stack_pop_empty_stack)
{
    stk_elem * stack = NULL;
    double tval;
    tval = pop(&stack);

    /* Comparisons with NaN are always false, so x != x evals to true iff x = NaN */
    ck_assert_msg(tval != tval, "pop returned non-NAN on an empty stack: got %g", tval);
}
END_TEST

START_TEST (test_stack_size)
{
    stk_elem * stack = NULL;
    int retval;
    int i;

    for (i = 0; i < 10; ++i)
    {  
        retval = stk_size(&stack);
        ck_assert_msg(retval == i, "stk_size returned %d for stack size %d!", retval, i);
        push(&stack, i);
    }

    for (i = 0; i < 10; ++i)
    {
        pop(&stack);
    }
    
}
END_TEST

Suite * test_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Stack");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_stack_push_pop_single);
    tcase_add_test(tc_core, test_stack_push_pop_multi);
    
    tcase_add_test(tc_core, test_stack_pop_empty_stack);
    
    tcase_add_test(tc_core, test_stack_size);

    suite_add_tcase(s, tc_core);
    return s;
}

int main (void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;
    s = test_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
