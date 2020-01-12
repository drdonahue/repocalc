#ifndef __CUSTOMFUNCS_H
#define __CUSTOMFUNCS_H
#include "stack.h"
#include <math.h>
#include "structs.h"

/* Place the prototypes for any custom functions in this file
 * Custom functions must be void and accept 3 arguments:
 * stk_elem **      stack       The stack. See stack.h for stack functions
 * double *         input       The number on the input line. Check if it is NAN before using
 * unsigned int *   cursorpos   Pointer to the current postision of the cursor. 
 * const Arg *      arg         struct that allows for a special argument to be passed. Set in config.h, add the argument to the struct.
 */

/*Example custom function: sinh*/
/*void fn_sinh (stk_elem ** stack, double * input, unsigned int * cursorpos, const Arg * arg);*/


#endif
