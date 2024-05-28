#include "ncutil.h"

int main(void)
{
    //Init ncurses standard window and set some configuration
    init_std_scr();
    
    //Get Screen size
    scrdim scr = get_scr_size(stdscr);
    printw("[INFO] Screen size is: {x: %d, y: %d}\n", scr.x, scr.y);
    refresh();

    attron(A_REVERSE | A_UNDERLINE); //attrset turns off all other attributes
    char *str = "Hello how are you my friend ?";
    refresh();
    while(*str)
    {
	addch(*str);
	str++;
	refresh();
	napms(100);
    }

    refresh();
    
    //Move cursor:
    move_cursor(stdscr, 10, 10);
    refresh();
    
    /* getch(); */
    
    finish(); //endwin call
    return 0;
}
