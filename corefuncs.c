/* see LICENSE for license details */
#include "corefuncs.h"

/* Push input to the stack */
void fn_push (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);
}

/* Drop the top element of the stack */
void fn_drop (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    pop(stack);
}

/* Roll the stack about cursorpos. This puts the element under the cursor on top of the stack. */
void fn_roll (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (*cursorpos > 1)
        roll(stack, *cursorpos - 1);
}

/* Swap the first 2 elemnts on the stack */
void fn_swap (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    roll(stack, 1);
}

/* Duplicate the top element of the stack */
void fn_dup (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (!stk_size(*stack))
        return;

    /* push the value of the top element */
    push(stack, stk_at(*stack,0));
}

/* Move the cursor up one line */
void cursor_up (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    (*cursorpos)++;
}

/* Move the cursor down one line */
void cursor_down (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if(*cursorpos)
        (*cursorpos)--;
}

/* Add the top 2 elements of the stack */
void fn_add (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if(input == input) /* fails on NAN */
        push(stack, input);

    if (stk_size(*stack) < 2)
        return;
    push(stack, pop(stack) + pop(stack));
}

/* Subtract the top 2 elements of the stack */
void fn_sub (stk_elem ** stack, double input, unsigned int * cursorpos)
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

/* Multiply the top 2 elements of the stack */
void fn_mul (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if(input == input) /* fails on NAN */
        push(stack, input);

    if (stk_size(*stack) < 2)
        return;
    push(stack, pop(stack) * pop(stack));
}

/* Divide the top 2 elements of the stack */
void fn_div (stk_elem ** stack, double input, unsigned int * cursorpos)
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

/* Negate the top element of the stack */
void fn_negate (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;
    push(stack,-pop(stack));
}

/* Calculate the 2nd to the 1st element of the stack */
void fn_y_to_x (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    double a,b;
    
    if(input == input) /* fails on NAN */
        push(stack, input);

    if (stk_size(*stack) < 2)
        return;
    b = pop(stack);
    a = pop(stack);
    push(stack, pow(a,b));

}

/* Take the square root of the top element of the stack */
void fn_sqrt (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;
    push(stack,sqrt(pop(stack)));
}

/* Square the top element of the stack */
void fn_square (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    double x;
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;

    x = pop(stack);
    push(stack,x*x);
}

/* Calculate exp(x) */
void fn_exp (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;

    push(stack,exp(pop(stack)));
}

/* Calculate ln(x) */
void fn_ln (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;

    push(stack,log(pop(stack)));
}
