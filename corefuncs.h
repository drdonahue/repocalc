/* see LICENSE for license details */
#ifndef __COREFUNCS_H
#define __COFEFUNCS_H
#include "stack.h"
#include <math.h>

void fn_push (stk_elem ** stack, double input, unsigned int cursorpos);

void fn_drop (stk_elem ** stack, double input, unsigned int cursorpos);

void fn_add (stk_elem ** stack, double input, unsigned int cursorpos);

void fn_sub (stk_elem ** stack, double input, unsigned int cursorpos);

void fn_mul (stk_elem ** stack, double input, unsigned int cursorpos);

void fn_div (stk_elem ** stack, double input, unsigned int cursorpos);

void fn_negate (stk_elem ** stack, double input, unsigned int cursorpos);

#endif
