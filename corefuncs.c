#include "corefuncs.h"


void fn_push (stk_elem ** stack, double input, unsigned int cursorpos)
{
    /*mark as unused*/
    (void)cursorpos;

    if(input != NAN)
        push(stack, input);
}
