START_TEST (test_fn_sin)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    push(&stack, M_PI / 2.0);
    fn_sin (&stack, &input, &cursorpos, NULL);
    ck_assert (pop(&stack) == 1);
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_cos)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    push(&stack, M_PI);
    fn_cos (&stack, &input, &cursorpos, NULL);
    ck_assert (pop(&stack) == -1);
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_tan)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    push(&stack, M_PI/2);
    fn_tan (&stack, &input, &cursorpos, NULL);
    ck_assert (abs(pop(&stack) - 1) < 0.000001);
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_asin)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    push(&stack, 0);
    fn_asin (&stack, &input, &cursorpos, NULL);
    ck_assert (pop(&stack) == 0);
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_acos)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    push(&stack, 1);
    fn_acos (&stack, &input, &cursorpos, NULL);
    ck_assert (pop(&stack) == 0);
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_atan)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    push(&stack, 1);
    fn_atan (&stack, &input, &cursorpos, NULL);
    ck_assert (abs(pop(&stack) - M_PI/2) < 0.000001);
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
    
    tcase_add_test(tc_core, test_fn_cos);

    tcase_add_test(tc_core, test_fn_tan);

    tcase_add_test(tc_core, test_fn_asin);
    
    tcase_add_test(tc_core, test_fn_acos);

    tcase_add_test(tc_core, test_fn_atan);
    
    suite_add_tcase(s, tc_core);
    return s;
}
