#include "config.h"

double bank[NUM_BANKS];

void sto (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg)
{

    if (*cursorpos && stk_at(*stack, *cursorpos - 1) == stk_at(*stack, *cursorpos - 1))
    {
        bank[arg->bankno] = stk_at(*stack, *cursorpos - 1);
        *cursorpos = 0;
        return;
    }
    else if (*cursorpos)
    {
        return;
    }
    
    if (*input == *input)
    {
        push(stack, *input);
    }
    bank[arg->bankno] = stk_at(*stack, 0); 

    *input = NAN;
}

void rcl (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg)
{
    if (*input == *input)
        push(stack, *input);

    push(stack, bank[arg->bankno]);

    *input = NAN;
}
