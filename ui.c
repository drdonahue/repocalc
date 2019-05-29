/* see LICENSE for license details */
#include "ui.h"

void nc_init (void)
{
    initscr();
    cbreak();
    noecho();
    
    clear();
}

void nc_loop (void)
{
    int exit = 0;
    int c;
    while (!exit)
    {
        c = getch();
        exit = ( c == K_EXIT );
    }
}

void nc_exit (void)
{
    endwin();
}
