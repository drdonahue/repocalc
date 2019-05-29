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
    nc_draw_screen();
    while (!exit)
    {
        c = getch();
        exit = ( c == K_EXIT );
    }
}

void nc_draw_screen (void)
{
    int h,w,y;

    /* Get the screen dimensions from NC */
    getmaxyx(stdscr, h, w);

    /* Go to 0,0 on the screen */
    move(0,0);
    
    for (y = h-4; y >= 0; --y)
    {
        wprintw(stdscr, "%2d > \n", y);
    }
    move(h-1, 0);
    wrefresh(stdscr);

}

void nc_exit (void)
{
    endwin();
}
