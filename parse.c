/* see LICENSE for license details */

#include "parse.h"


void parse (stk_elem ** stack, int keycode, unsigned int * cursor_pos, char * iline)
{
    double input;
    int i;
    
    /* process the user-defined keypresses */
    for (i = 0; i < LENGTH(keys); ++i)
    {
        if (keycode == keys[i].code &&
            keys[i].func)
        {
            /* convert the input line (if not empty) to double NaN denotes no input. */
            if (strlen(iline))
                sscanf (iline, "%lg", &input);
            else
                input = NAN;

            /* run the function that the keypress corresponds to */
            keys[i].func(stack, input, cursor_pos);
            
            /* clear the input line */
            iline[0] = 0;
        }
    }

    /* numeric input, little e reserved for to denote 10^ */
    if ((keycode >= '0' && keycode <= '9') || keycode == '.' || keycode == 'e')
    {
        i = strlen(iline);
        if ( i < INPUT_BUFFER_SIZE - 1)
        {
            iline[i] = keycode;
            iline[i+1] = 0;
        }
    }
    
    /* Delete the last character of input on K_DELETE (default backspace) */
    if (keycode == K_DELETE && strlen(iline) > 0) 
    {
        iline[strlen(iline) - 1] = 0;
    }
}


