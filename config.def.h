/* see LICENSE for license details. */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <ncurses.h>

/* function header files */

#include "corefuncs.h"

/* Macros */
#define LENGTH(X)   (sizeof X / sizeof X[0])

/* Constants */
#define INPUT_BUFFER_SIZE 50

/* keybindings */

#define K_EXIT KEY_F(10)
#define K_DELETE KEY_BACKSPACE

typedef struct {
    int code;
    void (*func)(stk_elem **, double, unsigned int*);
}Keybind;


static const Keybind keys[] = {
    /* NCurses Keycode   function   */
    {  '\n',             fn_push     },
    {  'd',              fn_drop     },
    {  '+',              fn_add      },
    {  '-',              fn_sub      },
    {  '*',              fn_mul      },
    {  '/',              fn_div      },
    {  'n',              fn_negate   },
    {  'k',              cursor_up   },
    {  KEY_UP,           cursor_up   },
    {  'j',              cursor_down },
    {  KEY_DOWN,         cursor_down },
    {  'r',              fn_roll     },
    {  '\t',             fn_swap     },
    {  '^',              fn_y_to_x   },
    {  'q',              fn_sqrt     },
    {  'Q',              fn_square   },
    {  'u',              fn_dup      },
};


#endif
