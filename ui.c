/* see LICENSE for license details */
#include "ui.h"

void nc_init (void)
{
    initscr();
    cbreak();
    noecho();
    savetty();
    keypad(stdscr, TRUE);
    
    clear();
}

void nc_loop (void)
{
    int exit = 0;
    int c;
    unsigned int cursor_pos = 0;
    stk_elem * stack = NULL;
    char iline[INPUT_BUFFER_SIZE] = "";
    
    nc_draw_screen();
    nc_draw_cursor(cursor_pos);
    while (!exit)
    {
        c = getch();
        exit = ( c == K_EXIT );
        /* Redraw the screen if the terminal is resized */
        if (c == KEY_RESIZE)
        {
            nc_draw_screen();
            nc_draw_stack(stack);
        }
        
        parse(&stack, c, &cursor_pos, iline); 
        nc_draw_screen();
        nc_draw_stack(stack);
        nc_draw_cursor(cursor_pos);
        nc_draw_input(iline);
    }
    stk_free(&stack);

}

void nc_draw_screen (void)
{
    int h,w,i;
    char * blankline;

    /* Get the screen dimensions from NC */
    getmaxyx(stdscr, h, w);

    /* create a blank line for the last 3 lines of the screen */
    blankline = (char *) malloc(sizeof(char) * w+1);

    for (i = 0; i < w-1; ++i)
    {
        blankline[i] = ' ';
    }
    blankline[w-1] = '\n';
    blankline[w] = 0;

    /* Go to 0,0 on the screen */
    move(0,0);
   
    /* Draw the stack lines */
    for (i = h-4; i >= 0; --i)
    {
        wprintw(stdscr, "%2d | \n", i);
    }
    for (i = 0; i < 3; ++i)
    {
        wprintw(stdscr, blankline);
    }

    /* Go to the bottom left for input */
    move(h-2, 5);

    /* Display to the screen */
    wrefresh(stdscr);

    free(blankline);

}
void nc_draw_stack (const stk_elem * stack)
{
    int h,w,i,stack_size;
    char * blankline;

    getmaxyx(stdscr, h, w);

    /* create a blank line for empty stack elements */
    blankline = (char *) malloc(sizeof(char) * w-5);

    for (i = 0; i < w-6; ++i)
    {
        blankline[i] = ' ';
    }
    blankline[w-6] = 0;

    stack_size = stk_size(stack);

    for (i = 0; i < h-4; ++i)
    {
        move(h-(4+i), 5);
        wprintw(stdscr, blankline);
        move(h-(4+i), 5);
        if (i < stack_size)
            wprintw(stdscr, "%lg", stk_at(stack, i));
    }
    


    free(blankline);
}
void nc_draw_input (char * iline)
{
    int h,w;
    char blankline[INPUT_BUFFER_SIZE];
    int i;

    for (i = 0; i < INPUT_BUFFER_SIZE; ++i)
        blankline[i] = ' ';
    blankline[INPUT_BUFFER_SIZE - 1] = 0;

    getmaxyx(stdscr,h,w);
    (void)w;
    move(h-2, 5);
    wprintw(stdscr, blankline);
    move(h-2, 5);
    wprintw(stdscr, iline);
}

void nc_exit (void)
{
    endwin();
}
void nc_draw_cursor (unsigned int cpos)
{
    int h,w;
    getmaxyx(stdscr,h,w);
    (void)w;
    if (cpos > 0)
        cpos++;
    move(h-cpos-2, 0);
    wprintw(stdscr, ">>");
    move(h-2, 5);
}
