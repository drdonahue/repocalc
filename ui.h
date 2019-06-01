/* see LICENSE for license details. */
#ifndef __UI_H
#define __UI_H
#include <curses.h>
#include <stdlib.h>
#include "config.h"
#include "stack.h"
#include "parse.h"

typedef enum { SCI, ENG, NRM } mode;

typedef struct {
    mode m;
    unsigned int p;
}display_opts;


void nc_init (void);
void nc_loop (void);
void nc_draw_screen(void);
void nc_draw_stack (const stk_elem * stack, display_opts disp);
void nc_draw_input (char * iline);
void nc_draw_cursor (unsigned int cpos);
void nc_exit (void);
void nc_draw_help (void);
const char * keyname_h (char * ret, int c);


#endif /* __UI_H */
