/* see LICENSE for license details */
#ifndef __STACK_H
#define __STAKC_H
#include <stdlib.h>

typedef struct stk_elem stk_elem;
struct stk_elem
{
    double val;
    stk_elem * nxt;
};

void push (stk_elem ** top, double val);
double pop (stk_elem ** top);

#endif
