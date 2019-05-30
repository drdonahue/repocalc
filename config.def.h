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
    void (*func)(stk_elem **, double, unsigned int);
}Keybind;


static Keybind keys[] = {
    /* Modifier     NCurses Keycode      function */
    { 0,            '\n',             fn_push },
};


#endif
