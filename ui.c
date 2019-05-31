/* see LICENSE for license details */
#include "ui.h"

void nc_init (void)
{
    /* start ncurses window */
    initscr();
    
    /* do not buffer characters until newline */
    cbreak();

    /* do not echo input to the console */
    noecho();

    /* save the tty settings so they can be restored */
    savetty();

    /* disable multibyte characters, eg ^[[21~ for F10, in favor of KEY_* bindings */
    keypad(stdscr, TRUE);
    
    /* clear the screen */
    clear();
}

void nc_loop (void)
{
    int exit = 0;
    int c;
    unsigned int cursor_pos = 0;
    stk_elem * stack = NULL;
    char iline[INPUT_BUFFER_SIZE] = "";
    double tmp;

    display_opts disp = DEFAULT_DISPLAY_OPTS;
    
    while (!exit)
    {
        /* Draw everything */
        nc_draw_screen();
        nc_draw_stack(stack, disp);
        nc_draw_cursor(cursor_pos);
        nc_draw_input(iline);

        /* wait for and get a character */
        c = getch();
        
        /* end the program on K_EXIT */
        exit = ( c == K_EXIT );

        
        if ( c == K_NRM)
            disp.m = NRM;
        else if (c == K_ENG)
            disp.m = ENG;
        else if (c == K_SCI)
            disp.m = SCI;
        else if (c == K_PRECISION)
        {
            if (strlen(iline))
            { 
                sscanf(iline,"%lf", &tmp);
                push(&stack, tmp);
                iline[0] = 0;
            }
            tmp = pop(&stack);
            if(tmp && tmp > 0)
                disp.p = (unsigned int) tmp;
        }
        /* Pass the character off to parse to be handled. */
        parse(&stack, c, &cursor_pos, iline); 
    }

    /* free the stack before it goes out of scope */
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

    /* print bottom bar */
    move(h-1,0);
    wprintw(stdscr, "Set Precision: %s  AUTO: %s  SCI: %s  ENG: %s  ", keyname_h(K_PRECISION), keyname_h(K_NRM), keyname_h(K_SCI), keyname_h(K_ENG));
    wprintw(stdscr, "Exit: %s  ", keyname_h (K_EXIT));

    /* Go to the bottom left for input */
    move(h-2, 5);

    /* Display to the screen */
    wrefresh(stdscr);

    free(blankline);

}
void nc_draw_stack (const stk_elem * stack, display_opts disp)
{
    int h,w,i,stack_size;
    char * blankline;
    char fmt[5] = "";
    int eng_pwr;
    double eng_dec;

    getmaxyx(stdscr, h, w);

    /* create a blank line for empty stack elements */
    blankline = (char *) malloc(sizeof(char) * w-5);

    if( disp.m == NRM )
    {
        strcpy(fmt, "%.*g");
    }
    else if (disp.m == SCI)
    {
        strcpy(fmt, "%.*e");
    }

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
        {
            /* manually display engineering format, as there is no printf format for it */
            if (disp.m == ENG)
            {
                eng_pwr = (int) log10 (stk_at(stack,i));
                if (eng_pwr > 0)
                {
                    eng_pwr = (eng_pwr / 3)*3;
                }
                else
                {
                    eng_pwr = (-eng_pwr + 3)/3 * -3;
                }
                eng_dec = stk_at(stack, i) * pow(10, -eng_pwr);

                if(eng_dec >= 1000)
                {
                    eng_pwr += 3;
                    eng_dec /= 1000.0;
                }

                wprintw(stdscr, "%.*lfe+%02d", disp.p, eng_dec, eng_pwr);   
            }
            else
            {
                wprintw(stdscr, fmt, disp.p, stk_at(stack, i));
            }
        }
    }
    


    free(blankline);
}
void nc_draw_input (char * iline)
{
    int h,i;
    char blankline[INPUT_BUFFER_SIZE];

    /* create a blank line for the input space */
    for (i = 0; i < INPUT_BUFFER_SIZE; ++i)
        blankline[i] = ' ';
    blankline[INPUT_BUFFER_SIZE - 1] = 0;

    h = getmaxy(stdscr);
    move(h-2, 5);

    /* blank the input line */
    wprintw(stdscr, blankline);

    move(h-2, 5);

    /* draw the input line */
    wprintw(stdscr, iline);
}

void nc_exit (void)
{
    endwin();
}

void nc_draw_cursor (unsigned int cpos)
{
    int h;
    h = getmaxy(stdscr);

    /* Account for the blank line between the input and stack */
    if (cpos > 0)
        cpos++;

    /* Draw the cursor and return to the input line */
    move(h-cpos-2, 0);
    wprintw(stdscr, ">>");
    move(h-2, 5);
}

const char * keyname_h (int c)
{
    const char *str,*tmp;

    str = keyname(c);

    tmp = strstr(str, "KEY_");
    if (tmp == NULL )
    {
        return str; /* Regular character, no KEY_ prefix */
    }

    str += 4; /* Toss out the KEY_ prefix for special keys */
    return str;
}
