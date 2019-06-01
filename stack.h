/* see LICENSE for license details */
#ifndef __STACK_H
#define __STACK_H
#include <stdlib.h>
#include "structs.h"

void push (stk_elem ** top, double val);
double pop (stk_elem ** top);
void roll (stk_elem ** top, int pos);
int stk_size(const stk_elem * top);
double stk_at(const stk_elem * top, unsigned int n);
void stk_free(stk_elem ** top);

#endif
