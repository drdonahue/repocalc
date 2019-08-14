/* see LICENSE for license details */
#ifndef __COREFUNCS_H
#define __COREFUNCS_H
#include "stack.h"
#include <math.h>
#include "structs.h"

void fn_push (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_drop (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_roll (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_swap (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void cursor_up (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void cursor_down (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_add (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_sub (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_mul (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_div (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_negate (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_y_to_x (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_sqrt (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_square (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_dup (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_exp (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_ln (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_log (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_logn (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void fn_inv (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

#endif /* __COREFUNCS_H */
