/* see LICENSE for license details */
#ifndef __TRIGFUNCS_H
#define __TRIGFUNCS_H
#include <math.h>
#include "stack.h"
#include "structs.h"

void fn_sin (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_cos (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_tan (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_asin (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_acos (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_atan (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_push_pi (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);



#endif /*__TRIGFUNCS_H*/
