/* see LICENSE for license details */
#ifndef __STRUCTS_H
#define __STRUCTS_H

typedef struct stk_elem stk_elem;
struct stk_elem
{
    double val;
    stk_elem * nxt;
};


/* structure for special, constant arguements to certian functions */
typedef struct {
    unsigned int bankno;
}Arg;


typedef struct {
    int code;
    void (*func)(stk_elem **, double *, unsigned int *, const Arg *);
    const Arg arg;
}Keybind;

#endif
