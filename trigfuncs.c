#include "trigfuncs.h"


void fn_sin (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, sin(pop(stack)));

}


void fn_cos (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, cos(pop(stack)));

}

void fn_tan (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, tan(pop(stack)));

}

void fn_asin (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, asin(pop(stack)));

}


void fn_acos (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, acos(pop(stack)));

}

void fn_atan (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, atan(pop(stack)));

}

void fn_push_pi (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    push(stack, M_PI);

}
