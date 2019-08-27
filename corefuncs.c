/* see LICENSE for license details */
#include "corefuncs.h"

/* Push input to the stack */
void fn_push (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);
    
    *input = NAN;
}

/* Drop the top element of the stack */
void fn_drop (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input) /* Delete the input line rather than dropping from the stack */
        return;

    pop(stack);

    *input = NAN;
}

/* Roll the stack about cursorpos. This puts the element under the cursor on top of the stack. */
void fn_roll (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (!*cursorpos)
        return;
    
    if (arg->c && !strncmp(arg->c, "sel", 3))
    {
        if (*input == *input)
        {
            push(stack, *input);
        }
        roll (stack, *cursorpos);    
        *input = pop(stack);
    }
    else if (*cursorpos > 1)
    {
        roll(stack, *cursorpos - 1);
    }

}

/* Swap the first 2 elemnts on the stack */
void fn_swap (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (arg->c && !strncmp(arg->c, "toX", 3))
    {
        if (*input == *input)
        {
            push(stack, *input);
            roll(stack, 1);
        }
        
        *input = pop(stack);    
    }
    else
    {
        if (*input == *input)
            push(stack, *input);
    
        roll(stack, 1);
        *input = NAN;
    }
}

/* Duplicate the top element of the stack */
void fn_dup (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (!stk_size(*stack))
        return;

    /* push the value of the top element */
    push(stack, stk_at(*stack,0));

    *input = NAN;
}

/* Move the cursor up one line */
void cursor_up (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    (*cursorpos)++;
}

/* Move the cursor down one line */
void cursor_down (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if(*cursorpos)
        (*cursorpos)--;
}

/* Add the top 2 elements of the stack */
void fn_add (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if(*input == *input) /* fails on NAN */
        push(stack, *input);

    if (stk_size(*stack) < 2)
        return;
    push(stack, pop(stack) + pop(stack));

    *input = NAN;
}

/* Subtract the top 2 elements of the stack */
void fn_sub (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    double a,b;
    if(*input == *input) /* fails on NAN */
        push(stack, *input);

    if (stk_size(*stack) < 2)
        return;
    b = pop(stack);
    a = pop(stack);
    push(stack, a-b);


    *input = NAN;
}

/* Multiply the top 2 elements of the stack */
void fn_mul (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if(*input == *input) /* fails on NAN */
        push(stack, *input);

    if (stk_size(*stack) < 2)
        return;
    push(stack, pop(stack) * pop(stack));

    *input = NAN;
}

/* Divide the top 2 elements of the stack */
void fn_div (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    double a,b;
    
    if(*input == *input) /* fails on NAN */
        push(stack, *input);

    if (stk_size(*stack) < 2)
        return;
    b = pop(stack);
    a = pop(stack);
    push(stack, a/b);

    *input = NAN;
}

/* Negate the top element of the stack */
void fn_negate (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;
    push(stack,-pop(stack));

    *input = NAN;
}

/* Calculate the 2nd to the 1st element of the stack */
void fn_y_to_x (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    double a,b;
    
    if(*input == *input) /* fails on NAN */
        push(stack, *input);

    if (stk_size(*stack) < 2)
        return;
    b = pop(stack);
    a = pop(stack);
    push(stack, pow(a,b));


    *input = NAN;
}

/* Take the square root of the top element of the stack */
void fn_sqrt (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;
    push(stack,sqrt(pop(stack)));

    *input = NAN;
}

/* Square the top element of the stack */
void fn_square (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    double x;
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;

    x = pop(stack);
    push(stack,x*x);

    *input = NAN;
}

/* Calculate exp(x) */
void fn_exp (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;

    push(stack,exp(pop(stack)));

    *input = NAN;
}

/* Calculate ln(x) */
void fn_ln (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;

    push(stack,log(pop(stack)));

    *input = NAN;
}

/* Calculate log(x) */
void fn_log (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;

    push(stack,log10(pop(stack)));

    *input = NAN;
}

/* Calculate log_x(y) */
void fn_logn (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    double x,y;
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 2)
        return;
    
    x = pop(stack);
    y = pop(stack);

    push(stack,log(y) / log(x));

    *input = NAN;
}

/* Calculate 1/x */
void fn_inv (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    if (*input == *input)
        push(stack, *input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, 1.0/pop(stack));

    *input = NAN;
}
