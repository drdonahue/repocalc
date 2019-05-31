START_TEST (test_fn_sin)
{
    stk_elem * stack = NULL;
    push(&stack, M_PI / 2.0);
    fn_sin (&stack, NAN, 0);
    ck_assert (pop(&stack) == 1);
    stk_free(&stack);
}
END_TEST

Suite * trig_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Trig Functions");

    tc_core = tcase_create("Core");


    tcase_add_test(tc_core, test_fn_sin);
    
    suite_add_tcase(s, tc_core);
    return s;
}
