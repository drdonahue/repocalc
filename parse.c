/* see LICENSE for license details */

#include "parse.h"


void parse (stk_elem ** stack, int keycode, unsigned int * cursor_pos, char * iline)
{
    static int modifier = 0;
    double input;
    int i;

    for (i = 0; i < LENGTH(keys); ++i)
    {
        if (keycode == keys[i].code &&
            modifier == keys[i].modifier &&
            keys[i].func)
        {
            sscanf (iline, "%lg", &input);
            keys[i].func(stack, input, *cursor_pos);
        }
    }
    if ((keycode >= '0' && keycode <= '9') || keycode == '.' || keycode == 'e')
    {
        i = strlen(iline);
        if ( i < INPUT_BUFFER_SIZE - 1)
        {
            iline[i] = keycode;
            iline[i+1] = 0;
        }
    }
    if (keycode == '-') /* This will need handled separately */
    {}
    if (keycode == K_DELETE && strlen(iline) > 0) /* Delete the last character of input */
    {
        iline[strlen(iline) - 1] = 0;
    }
}


