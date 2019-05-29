/* see LICENSE for license details. */
#ifndef __UI_H
#define __UI_H
#include <curses.h>
#include <stdlib.h>
#include "config.h"

void nc_init (void);
void nc_loop (void);
void nc_draw_screen(void);
void nc_exit (void);

#endif
