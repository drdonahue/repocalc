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

/* Special keybindings */

#define K_EXIT KEY_F(10)
#define K_DELETE KEY_BACKSPACE

typedef struct {
    int code;
    void (*func)(stk_elem **, double, unsigned int*);
}Keybind;


/* Function keybindings */

/* x is the top of the stack or input line, and y is the next element of the stack */
/* Available functions:
 * fn_push          push the input line to the stack
 * fn_drop          drop x
 * fn_roll          roll the stack about the cursor position
 * fn_swap          swap x and y on the stack
 * fn_dup           duplicate x on the stack
 * cursor_up        move the cursor up 1 line
 * cursor_down      move the cursor down 1 line
 * fn_add           y + x
 * fn_sub           y - x
 * fn_mul           y * x
 * fn_div           y / x
 * fn_negate        -1 * x
 * fn_y_to_x        y ^ x
 * fn_sqrt          take the square root of x
 * fn_square        x ^ 2
 * fn_exp           e ^ x
 * fn_ln            ln(x)
 */

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
    {  'E',              fn_exp      },
    {  'l',              fn_ln       },
};


#endif /* __CONFIG_H */
