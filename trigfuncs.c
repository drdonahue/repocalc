#include "trigfuncs.h"


void fn_sin (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, sin(pop(stack)));


    *input = NAN;
}


void fn_cos (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, cos(pop(stack)));


    *input = NAN;
}

void fn_tan (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, tan(pop(stack)));


    *input = NAN;
}

void fn_asin (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, asin(pop(stack)));


    *input = NAN;
}


void fn_acos (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, acos(pop(stack)));


    *input = NAN;
}

void fn_atan (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, atan(pop(stack)));


    *input = NAN;
}

void fn_push_pi (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    push(stack, M_PI);


    *input = NAN;
}
