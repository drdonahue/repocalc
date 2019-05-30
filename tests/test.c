#include <check.h>
#include "../stack.h"
#include "../corefuncs.h"

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

START_TEST (test_stack_free)
{
    stk_elem * stack = NULL;
    int i;

    for (i = 0; i < 10; ++i)
    {
        push(&stack, i);
    }
    stk_free(&stack);

    ck_assert_msg(stack == NULL, "stk_free failed to free all ements of the stack");
}
END_TEST

START_TEST (test_stack_size)
{
    stk_elem * stack = NULL;
    int retval;
    int i;

    for (i = 0; i < 10; ++i)
    {  
        retval = stk_size(stack);
        ck_assert_msg(retval == i, "stk_size returned %d for stack size %d!", retval, i);
        push(&stack, i);
    }

    stk_free(&stack);
    
}
END_TEST

START_TEST (test_stack_at)
{
    int i;
    double retval;
    stk_elem * stack = NULL;

    for (i = 0; i < 10; ++i)
    {
        /* 0.5 * i used to prevent a potential false pass */
        push(&stack, i * 0.5);
    }
    for (i = 0; i < 10; ++i)
    {
        retval = stk_at(stack, i);
        ck_assert_msg(retval == (9-i) * 0.5, "stk_at returned %g for locatoin %d instead of %g", retval, i, (9-i)*0.5);
    }

    stk_free(&stack);
    
}
END_TEST

START_TEST (test_stack_at_oob)
{
    double retval;
    stk_elem * stack = NULL;
    retval = stk_at(stack, 0);
    ck_assert_msg(retval != retval, "stk_at returned %g instead of NaN for an empty stack", retval);
    push(&stack, 1);
    retval = stk_at(stack, 1);
    ck_assert_msg(retval != retval, "stk_at returned %g instead of NaN for an OOB index", retval);
}
END_TEST

START_TEST (test_stack_roll)
{
    int i;
    stk_elem * stack = NULL;
    for(i = 0; i < 5; ++i)
    {
        push(&stack, i);
    }
    roll(&stack, 2);
    ck_assert_msg(stk_at(stack, 0) == 2, "Roll failed, %g at 0 instead of 2.0", stk_at(stack,0));
    ck_assert_msg(stk_at(stack, 1) == 4, "Roll failed, %g at 1 instead of 4.0", stk_at(stack,1));
    ck_assert_msg(stk_at(stack, 2) == 3, "Roll failed, %g at 2 instead of 3.0", stk_at(stack,0));
    
}
END_TEST

START_TEST (test_fn_add)
{
    stk_elem * stack = NULL;

    push(&stack, 9);
    push(&stack, 8);

    fn_add(&stack, NAN, 0);
    ck_assert_msg(pop(&stack) == 17, "Add failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_sub)
{
    stk_elem * stack = NULL;

    push(&stack, 9);
    push(&stack, 8);

    fn_sub(&stack, NAN, 0);
    ck_assert_msg(pop(&stack) == 1, "Subtract failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_mul)
{
    stk_elem * stack = NULL;

    push(&stack, 9);
    push(&stack, 8);

    fn_mul(&stack, NAN, 0);
    ck_assert_msg(pop(&stack) == 72, "Multiply failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_div)
{
    stk_elem * stack = NULL;

    push(&stack, 27);
    push(&stack, 3);

    fn_div(&stack, NAN, 0);
    ck_assert_msg(pop(&stack) == 9, "Divide failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_add_input)
{
    stk_elem * stack = NULL;

    push(&stack, 9);

    fn_add(&stack, 8, 0);
    ck_assert_msg(pop(&stack) == 17, "Add with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_sub_input)
{
    stk_elem * stack = NULL;

    push(&stack, 9);

    fn_sub(&stack, 8, 0);
    ck_assert_msg(pop(&stack) == 1, "Subtract with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_mul_input)
{
    stk_elem * stack = NULL;

    push(&stack, 9);

    fn_mul(&stack, 8, 0);
    ck_assert_msg(pop(&stack) == 72, "Multiply with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_div_input)
{
    stk_elem * stack = NULL;

    push(&stack, 27);

    fn_div(&stack, 3, 0);
    ck_assert_msg(pop(&stack) == 9, "Divide with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_negate)
{
    stk_elem * stack = NULL;
    
    push(&stack, 2);
    
    fn_negate(&stack, NAN, 0);
    ck_assert_msg(pop(&stack) == -2, "Negate failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_negate_input)
{
    stk_elem * stack = NULL;
    
    
    fn_negate(&stack, 2, 0);
    ck_assert_msg(pop(&stack) == -2, "Negate failed.");
    stk_free(&stack);
}
END_TEST




Suite * stack_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Stack");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_stack_push_pop_single);
    tcase_add_test(tc_core, test_stack_push_pop_multi);
    
    tcase_add_test(tc_core, test_stack_pop_empty_stack);
    
    tcase_add_test(tc_core, test_stack_size);

    tcase_add_test(tc_core, test_stack_free);
    tcase_add_test(tc_core, test_stack_at);

    tcase_add_test(tc_core, test_stack_at_oob);
    tcase_add_test(tc_core, test_stack_roll);

    suite_add_tcase(s, tc_core);
    return s;
}

Suite * math_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Core Math");

    tc_core = tcase_create("Core");


    tcase_add_test(tc_core, test_fn_add);
    tcase_add_test(tc_core, test_fn_sub);
    tcase_add_test(tc_core, test_fn_mul);
    tcase_add_test(tc_core, test_fn_div);

    tcase_add_test(tc_core, test_fn_add_input);
    tcase_add_test(tc_core, test_fn_sub_input);
    tcase_add_test(tc_core, test_fn_mul_input);
    tcase_add_test(tc_core, test_fn_div_input);

    tcase_add_test(tc_core, test_fn_negate);
    tcase_add_test(tc_core, test_fn_negate_input);

    suite_add_tcase(s, tc_core);
    return s;
}

int main (void)
{
    int number_failed;
    Suite *s_stack,*s_math;
    SRunner *sr_stack,*sr_math;
    s_stack = stack_suite();
    sr_stack = srunner_create(s_stack);
    s_math = math_suite();
    sr_math = srunner_create(s_math);


    srunner_run_all(sr_stack, CK_NORMAL);
    srunner_run_all(sr_math, CK_NORMAL);
    
    number_failed = srunner_ntests_failed(sr_stack) + srunner_ntests_failed(sr_math);
    srunner_free(sr_stack);
    srunner_free(sr_math);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
