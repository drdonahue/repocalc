/* see LICENSE for license details */
#ifndef __BANK_H
#define __BANK_H

#include "stack.h"
#include "structs.h"

void sto (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

void rcl (stk_elem ** stack, double *input, unsigned int * cursorpos, const Arg * arg);

#endif /*__BANK_H*/
