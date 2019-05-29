/* see LISENCE for license details */
#include "stack.h"
#include <math.h>
void push (stk_elem ** top, const double val)
{
    stk_elem * tmp = (stk_elem *)malloc(sizeof(stk_elem));
    tmp->val = val;
    tmp->nxt = *top;
    *top = tmp;
}

double pop (stk_elem ** top)
{
    stk_elem * tmp;
    double ret;

    if (*top == NULL)
        return NAN;
    
    tmp = *top;
    *top = tmp->nxt;
    
    ret = tmp->val;

    free(tmp);

    return ret;
}

int stk_size (stk_elem ** top)
{
    int count = 0;
    stk_elem * tmp = *top;
    while (tmp != NULL)
    {
        ++count;
        tmp = tmp->nxt;
    }
    return count;
}
