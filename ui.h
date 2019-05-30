/* see LICENSE for license details. */
#ifndef __UI_H
#define __UI_H
#include <curses.h>
#include <stdlib.h>
#include "config.h"
#include "stack.h"
#include "parse.h"

void nc_init (void);
void nc_loop (void);
void nc_draw_screen(void);
void nc_draw_stack (const stk_elem * stack);
void nc_draw_input (char * iline);
void nc_exit (void);

#endif
