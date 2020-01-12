#include "customfuncs.h"

/* Define your custom functions here. sinh is given as an example.
 * generally, you will want to put input (if any) on the stack before
 * perfoming your operation. if (input == input) will fail on NaN,
 * so by pushing only if it passes we ensure that only valid input
 * is pushed.
 * 
 * This is an RPN calculator, so your arguments will come from the stack
 * and the results will be pushed onto the stack.
 *
 * Once your function is defined, it can be mapped to a button by adding
 * an item to the keys[] initializer list in config.h.
 *
 */ 

/*
void fn_sinh (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg )
{
    double x;
    
    //check if *input exists. If it does not, this check will fail because *input will be NAN
    if (*input==*input)
        push(stack, *input);

    //If there is nothing on the stack, return
    if (stk_size(*stack) < 1)
        return;
    
    //Compute sinh(x) on the ToS and push the result
    x = pop(stack);
    push(stack, sinh(x));
}
*/
