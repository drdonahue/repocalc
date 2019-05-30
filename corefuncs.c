#include "corefuncs.h"


void fn_push (stk_elem ** stack, double input, unsigned int cursorpos)
{
    if(input != NAN)
        push(stack, input);
}

void fn_drop (stk_elem ** stack, double input, unsigned int cursorpos)
{
    pop(stack);
}

void fn_add (stk_elem ** stack, double input, unsigned int cursorpos)
{
    if(input == input) /* fails on NAN */
        push(stack, input);

    if (stk_size(*stack) < 2)
        return;
    push(stack, pop(stack) + pop(stack));
}

void fn_sub (stk_elem ** stack, double input, unsigned int cursorpos)
{
    double a,b;
    if(input == input) /* fails on NAN */
        push(stack, input);

    if (stk_size(*stack) < 2)
        return;
    b = pop(stack);
    a = pop(stack);
    push(stack, a-b);

}

void fn_mul (stk_elem ** stack, double input, unsigned int cursorpos)
{
    if(input == input) /* fails on NAN */
        push(stack, input);

    if (stk_size(*stack) < 2)
        return;
    push(stack, pop(stack) * pop(stack));
}

void fn_div (stk_elem ** stack, double input, unsigned int cursorpos)
{
    double a,b;
    
    if(input == input) /* fails on NAN */
        push(stack, input);

    if (stk_size(*stack) < 2)
        return;
    b = pop(stack);
    a = pop(stack);
    push(stack, a/b);
}
