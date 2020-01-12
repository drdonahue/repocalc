/* see LICENSE for license details. */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <ncurses.h>
#include "structs.h"

/* Constants */
#define INPUT_BUFFER_SIZE 50
#define NUM_BANKS 4 /*Number of banks for storing values*/

/* function header files */

#include "corefuncs.h"
#include "trigfuncs.h"
#include "customfuncs.h"
#include "bank.h"

/* Macros */
#define LENGTH(X)   (sizeof X / sizeof X[0])

/* Option Macros */

/*Default display format for numbers on the stack*/
/* .m options are NRM (automatic), SCI (scientific), and ENG (engineering) */
/* .p sets the number of digits to display. */
#define DEFAULT_DISPLAY_OPTS {.m = NRM, .p = 7}

/* Special keybindings */

#define K_EXIT KEY_F(10)
#define K_DELETE KEY_BACKSPACE
#define K_HELP '?'

/* keys for precision and display format */
#define K_PRECISION KEY_F(5)
#define K_NRM KEY_F(6)
#define K_SCI KEY_F(7)
#define K_ENG KEY_F(8)


/* Function keybindings */

/* x is the top of the stack or input line, and y is the next element of the stack */
/* Available functions:
 * fn_push          push the input line to the stack
 * fn_drop          drop x
 * fn_roll          roll the stack about the cursor position.
 *                  Optional argument: {.c="sel"} -- Include input line in roll
 * fn_swap          swap x and y on the stack
 *                  Optional argument: {.c="toInput"} -- Swap ToS and input line
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
 * fn_log           log(x)
 * fn_logn          log_x(y)
 * fn_inv           1 / x
 * fn_push_pi       Push pi to the stack
 * fn_sin           sin(x)
 * fn_cos           cos(x)
 * fn_tan           tan(x)
 * fn_asin          asin(x)
 * fn_acos          acos(x)
 * fn_atan          atan(x)
 * sto              store x to a bank   Argument:{.bankno=<bank number to use>}
 */

static const Keybind keys[] = {
    /* NCurses Keycode   function   Arguments */
    {  '\n',             fn_push,      {0}           },
    {  'd',              fn_drop,      {0}           },
    {  '+',              fn_add,       {0}           },
    {  '-',              fn_sub,       {0}           },
    {  '*',              fn_mul,       {0}           },
    {  '/',              fn_div,       {0}           },
    {  'n',              fn_negate,    {0}           },
    {  'k',              cursor_up,    {0}           },
    {  KEY_UP,           cursor_up,    {0}           },
    {  'j',              cursor_down,  {0}           },
    {  KEY_DOWN,         cursor_down,  {0}           },
    {  'r',              fn_roll,      {0}           },
    {  'y',              fn_roll,      {.c="sel"}    },
    {  'w',              fn_swap,      {0}           },
    {  '\t',             fn_swap,      {.c="toInput"}},
    {  '^',              fn_y_to_x,    {0}           },
    {  'q',              fn_sqrt,      {0}           },
    {  'Q',              fn_square,    {0}           },
    {  'u',              fn_dup,       {0}           },
    {  'E',              fn_exp,       {0}           },
    {  'l',              fn_ln,        {0}           },
    {  'L',              fn_log,       {0}           },
    {  'b',              fn_logn,      {0}           },
    {  'i',              fn_inv,       {0}           },
    {  's',              fn_sin,       {0}           },
    {  'c',              fn_cos,       {0}           },
    {  't',              fn_tan,       {0}           },
    {  'S',              fn_asin,      {0}           },
    {  'C',              fn_acos,      {0}           },
    {  'T',              fn_atan,      {0}           },
    {  'p',              fn_push_pi,   {0}           },
    {  KEY_F(1),         rcl,          {.bankno=0}   },
    {  KEY_F(13),        sto,          {.bankno=0}   },
    {  KEY_F(2),         rcl,          {.bankno=1}   },
    {  KEY_F(14),        sto,          {.bankno=1}   },
    {  KEY_F(3),         rcl,          {.bankno=2}   },
    {  KEY_F(15),        sto,          {.bankno=2}   },
    {  KEY_F(4),         rcl,          {.bankno=3}   },
    {  KEY_F(16),        sto,          {.bankno=3}   },
};


#endif /* __CONFIG_H */
