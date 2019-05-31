/* see LICENSE for license details */

#include "ui.h"
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{
    if (argc > 1)
    {
        if(!strcmp(argv[1], "-v"))
        {
            printf ("RepoCalc %s\n", VERSION);
        }
        else
        {
            printf ("Usage:\n\nrepocalc\nrepocalc [option]\n\nOptions:\n\n-v: Show version\n-h: Show this usage message\n");
        }
        return 0;
    }

    /* Start ncurses, run the main loop, then exit */
    nc_init();
    nc_loop();
    nc_exit();
    return 0;
}
