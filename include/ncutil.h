#ifndef NCUTIL_H
#define NCUTIL_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ncurses.h>

// Needed to return window dimensions
typedef struct screendimensions
{
    int x;
    int y;
} scrdim;

// Extern API functions declarations
extern void bomb(char* msg); //exit function to handle errors 
extern void init_std_scr(); //Initialize stdscr
extern void finish(void); //wrapper around endwin()
extern void move_cursor(WINDOW* win, int y, int x); //Move cursor at (y,x) in the window win
extern scrdim get_scr_size(WINDOW*); //Return {x, y} given window dimensions.
extern void init_ncolors(void); //Check if terminal supports colors, if yes it enables them.
extern void addstr_center(WINDOW*, int row, char *title); //write title at the center of given row in the given window.



// Exit function to handle errors.
void bomb(char* msg)
{
    endwin();
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
    return;
}

//Initialize stdscr with some options like cbreak, noecho, keypad, intrflush
void init_std_scr()
{
    fprintf(stderr, "[LOG] Initializing stdscr\n");
    if(initscr() == NULL)
    {
	bomb("[ERROR] Cannot initialize standard screen! Exiting...\n");
    }

    fprintf(stderr, "[LOG] Configuring stdscr options\n");
    //Disable line buffering by TTY driver
    assert(cbreak() == OK);
    //Disable echo of typed chars
    assert(noecho() == OK);
    //Enable special keys (like ALT_LEFT)
    assert(keypad(stdscr, TRUE) == OK);
    //Disable flushing when interrupt key is pressed
    assert(intrflush(stdscr, FALSE) == OK);

    return;
    
}

//Wrapper around endwin() function call to check for ERR
// This function should ALWAYS be called at the end of the app entry point
void finish(void)
{
    if(endwin() == ERR)
    {
	bomb("[ERROR] Call to endwin function failed! Exiting...\n");
    }
    
    fprintf(stderr, "[LOG] Call to endwin was successfull\n");
    return;
}


//This function moves the cursor in the given window to the given position
// If ncurses function fails, the program stops
void move_cursor(WINDOW* win, int y, int x)
{
    if(wmove(win,y,x) == ERR)
    {
	bomb("[ERROR] Could not move cursor to given position! Exiting...\n");
    }
    return;
}

//Returns the size of the given window as the struct scrsize {x, y}

scrdim get_scr_size(WINDOW* win)
{
    scrdim size;
    size.x = getmaxx(win);
    size.y = getmaxy(win);
    return size;
}

void init_ncolors(void)
{
    if(has_colors() != TRUE)
    {
      	bomb("[LOG] terminal does not support colors. Skipping colors.\n");
    }

    if(start_color() != OK)
    {
	bomb("[ERROR] terminal colors could not be initialized. Exiting.\n");
    }
    
    fprintf(stderr, "[LOG] successfully enabled terminal colors.\n");
    fprintf(stderr, "[LOG] terminal supports %d colors and %d colors pairs", COLORS, COLOR_PAIRS);
    return;
}

/* //Print argument in the center of the given window and row */
/* void addstr_center(WINDOW* win, int row, char *title) */
/* { */
/*     return; */
/* } */

#endif
