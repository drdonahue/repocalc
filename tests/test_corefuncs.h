START_TEST (test_fn_add)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;

    push(&stack, 9);
    push(&stack, 8);

    fn_add(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 17, "Add failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_sub)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;

    push(&stack, 9);
    push(&stack, 8);

    fn_sub(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 1, "Subtract failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_mul)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;

    push(&stack, 9);
    push(&stack, 8);

    fn_mul(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 72, "Multiply failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_div)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;

    push(&stack, 27);
    push(&stack, 3);

    fn_div(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 9, "Divide failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_add_input)
{
    stk_elem * stack = NULL;
    double input = 8;
    unsigned int cursorpos = 0;

    push(&stack, 9);

    fn_add(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 17, "Add with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_sub_input)
{
    stk_elem * stack = NULL;
    double input = 8;
    unsigned int cursorpos = 0;

    push(&stack, 9);

    fn_sub(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 1, "Subtract with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_mul_input)
{
    stk_elem * stack = NULL;
    double input = 8;
    unsigned int cursorpos = 0;

    push(&stack, 9);

    fn_mul(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 72, "Multiply with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_div_input)
{
    stk_elem * stack = NULL;
    double input = 3;
    unsigned int cursorpos = 0;

    push(&stack, 27);

    fn_div(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 9, "Divide with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_negate)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    
    push(&stack, 2);
    
    fn_negate(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == -2, "Negate failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_negate_input)
{
    stk_elem * stack = NULL;
    double input = 2;
    unsigned int cursorpos = 0;
    
    
    fn_negate(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(input == -2, "Negate with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_y_to_x)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    
    push(&stack, 2);
    push(&stack, 3);
    
    fn_y_to_x(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 8, "y^x failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_y_to_x_input)
{
    stk_elem * stack = NULL;
    double input = 3;
    unsigned int cursorpos = 0;
    
    push(&stack, 2);
    
    fn_y_to_x(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 8, "y^x with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_sqrt)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    
    push(&stack, 9);
    
    fn_sqrt(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 3, "Square root failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_sqrt_input)
{
    stk_elem * stack = NULL;
    double input = 9;
    unsigned int cursorpos = 0;
    
    fn_sqrt(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 3, "Square root with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_square)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;
    
    push(&stack, 3);
    
    fn_square(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 9, "Square failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_square_input)
{
    stk_elem * stack = NULL;
    double input = 3;
    unsigned int cursorpos = 0;
    
    fn_square(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 9, "Square with input failed.");
    stk_free(&stack);
}
END_TEST

START_TEST (test_fn_exp)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;

    push(&stack, 0);
    
    fn_exp(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 1, "exp(x) failed.");
    stk_free(&stack);

}
END_TEST

START_TEST (test_fn_exp_input)
{
    stk_elem * stack = NULL;
    double input = 0;
    unsigned int cursorpos = 0;

    fn_exp(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 1, "exp(x) with input failed.");
    stk_free(&stack);

}
END_TEST

START_TEST (test_fn_ln)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;

    push(&stack, 1);
    
    fn_ln(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 0, "ln(x) failed.");
    stk_free(&stack);

}
END_TEST

START_TEST (test_fn_ln_input)
{
    stk_elem * stack = NULL;
    double input = 1;
    unsigned int cursorpos = 0;

    fn_ln(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 0, "ln(x) with input failed.");
    stk_free(&stack);

}
END_TEST

START_TEST (test_fn_log)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;

    push(&stack, 100);
    
    fn_log(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 2, "log(x) failed.");
    stk_free(&stack);

}
END_TEST

START_TEST (test_fn_log_input)
{
    stk_elem * stack = NULL;
    double input = 100;
    unsigned int cursorpos = 0;

    fn_log(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 2, "log(x) with input failed.");
    stk_free(&stack);

}
END_TEST

START_TEST (test_fn_logn)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;

    push(&stack, 16);
    push(&stack, 2);
    
    fn_logn(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 4, "log_x(y) failed.");
    stk_free(&stack);

}
END_TEST

START_TEST (test_fn_logn_input)
{
    stk_elem * stack = NULL;
    double input = 2;
    unsigned int cursorpos = 0;

    push(&stack, 16);

    fn_logn(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 4, "log_x(y) with input failed.");
    stk_free(&stack);

}
END_TEST

START_TEST (test_fn_inv)
{
    stk_elem * stack = NULL;
    double input = NAN;
    unsigned int cursorpos = 0;

    push(&stack, 2);
    
    fn_inv(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 0.5, "1/x failed.");
    stk_free(&stack);

}
END_TEST

START_TEST (test_fn_inv_input)
{
    stk_elem * stack = NULL;
    double input = 2;
    unsigned int cursorpos = 0;

    fn_inv(&stack, &input, &cursorpos, NULL);
    ck_assert_msg(pop(&stack) == 0.5, "1/x with input failed.");
    stk_free(&stack);

}
END_TEST

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
    tcase_add_test(tc_core, test_fn_y_to_x);
    tcase_add_test(tc_core, test_fn_y_to_x_input);
    tcase_add_test(tc_core, test_fn_sqrt);
    tcase_add_test(tc_core, test_fn_sqrt_input);
    tcase_add_test(tc_core, test_fn_square);
    tcase_add_test(tc_core, test_fn_square_input);

    tcase_add_test(tc_core, test_fn_exp);
    tcase_add_test(tc_core, test_fn_exp_input);

    tcase_add_test(tc_core, test_fn_ln);
    tcase_add_test(tc_core, test_fn_ln_input);
    tcase_add_test(tc_core, test_fn_log);
    tcase_add_test(tc_core, test_fn_log_input);
    tcase_add_test(tc_core, test_fn_logn);
    tcase_add_test(tc_core, test_fn_logn_input);

    tcase_add_test(tc_core, test_fn_inv);
    tcase_add_test(tc_core, test_fn_inv_input);

    suite_add_tcase(s, tc_core);
    return s;
}
