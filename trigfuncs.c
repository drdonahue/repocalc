#include "trigfuncs.h"


void fn_sin (stk_elem ** stack, double input, unsigned int * cursorpos)
{
    if (input == input)
        push(stack, input);

    if (stk_size(*stack) < 1)
        return;
    

    push(stack, sin(pop(stack)));

}

