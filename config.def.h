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
    int modifier;
    int code;
    void (*func)(stk_elem **, double, unsigned int*);
}Keybind;


static const Keybind keys[] = {
    /* Modifier     NCurses Keycode      function */
    { 0,            '\n',             fn_push     },
    { 0,            'd',              fn_drop     },
    { 0,            '+',              fn_add      },
    { 0,            '-',              fn_sub      },
    { 0,            '*',              fn_mul      },
    { 0,            '/',              fn_div      },
    { 0,            'n',              fn_negate   },
    { 0,            'k',              cursor_up   },
    { 0,            KEY_UP,           cursor_up   },
    { 0,            'j',              cursor_down },
    { 0,            KEY_DOWN,         cursor_down },
    { 0,            'r',              fn_roll     },
    { 0,            '\t',             fn_swap     },
    { 0,            '^',              fn_y_to_x   },
    { 0,            'q',              fn_sqrt     },
};


#endif
