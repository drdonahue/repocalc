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

/* Move the element at pos to the top of the stack */
void roll (stk_elem **top, int pos)
{
    stk_elem * tmp,*cur = *top;
    int i;

    if (stk_size(*top) < pos + 1)
        return;

    /* stop 1 short, we need to modify the one before pos*/

    for (i = 0; i < pos-1; ++i)
        cur = cur->nxt;
    
    /* keep track of element at pos */
    tmp = cur->nxt;

    /* remove it from the stack */
    cur->nxt = tmp->nxt; 
    
    /* put it on top of the stack */
    tmp -> nxt = *top;

    *top = tmp;

}

int stk_size (const stk_elem * top)
{
    int count = 0;
    const stk_elem * tmp = top;
    while (tmp != NULL)
    {
        ++count;
        tmp = tmp->nxt;
    }
    return count;
}

/* Return the value at a given index of the stack, with 0 being the top. NaN is retunred if the index is invalid */
double stk_at(const stk_elem * top, unsigned int n)
{
    int i;
    
    /* Check for empty stack */
    if (top == NULL)
        return NAN;

    const stk_elem *tmp = top;
    for (i = 0; i < n; ++i)
    {
        /* Check each step before we move to it. */
        if (tmp->nxt == NULL)
        {
            return NAN;
        }
        
        tmp = tmp -> nxt;
    }
    return tmp->val;
}

/* Delete the stack and free its memory */
void stk_free(stk_elem ** top)
{
    stk_elem *tmp;
    while (*top != NULL)
    {
        tmp = *top;
        *top = tmp->nxt;
        free(tmp);
    }
}
