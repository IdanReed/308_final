#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "screen.h"

#define DELAY 30000

int main()
{
    Screen s;
    //WINDOW * win = newwin(10, 10, y0, x0);
    initscr();
    noecho();
    curs_set(FALSE);

    WINDOW * w = subwin(stdscr,5, 5,5,5);

    int max_y = 0, max_x = 0;
    getmaxyx(stdscr, max_y, max_x);

    for(int x = 0; x < max_y; x++){
        for(int y = 0; y < SCREEN_SIZE; y++){
            mvwprintw(stdscr, y, x, "*");
            refresh();
        }
    }
    
    /*
    fill_screen(s);
    Init();
    Display_map(s);
    sleep(10000);
    endwin();
    */

}
