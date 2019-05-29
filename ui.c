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
        if (c == KEY_RESIZE)
        {
            nc_draw_screen();
        }
    }
}

void nc_draw_screen (void)
{
    int h,w,i;
    char * blankline;

    /* Get the screen dimensions from NC */
    getmaxyx(stdscr, h, w);

    /* create a blank line for the last 3 lines of the screen */
    blankline = (char *) malloc(sizeof(char) * w);

    for (i = 0; i < w-1; ++i)
    {
        blankline[i] = ' ';
    }
    blankline[w-1] = '\n';

    /* Go to 0,0 on the screen */
    move(0,0);
   
    /* Draw the stack lines */
    for (i = h-4; i >= 0; --i)
    {
        wprintw(stdscr, "%2d > \n", i);
    }
    for (i = 0; i < 3; ++i)
    {
        wprintw(stdscr, blankline);
    }

    /* Go to the bottom right */
    move(h-1, w-1);

    /* Display to the screen */
    wrefresh(stdscr);

    free(blankline);

}

void nc_exit (void)
{
    endwin();
}
