#include <ncurses.h>

#include "screen.h"

void Init(){
    initscr();
    noecho();
    curs_set(FALSE);

}
void fill_screen(Screen s){
    for(int x = 0; x < SCREEN_SIZE; x++){
        for(int y = 0; y < SCREEN_SIZE; y++){
            s.screenText[x][y] = 'X';
        }
    }
}
void Display_map(Screen s){
    if(s.state != map){
        clear();
    }
    for(int x = 0; x < SCREEN_SIZE; x++){
        for(int y = 0; y < SCREEN_SIZE; y++){
            beep();
            mvprintw(y, x, "o");
            refresh();
        }
    }

}

//void Init_screen(struct screen)

/*
   clear();
    mvprintw(y, x, "o");
    refresh();

    usleep(DELAY);

    next_x = x + direction;

    if (next_x >= max_x || next_x < 0) {
        direction*= -1;
    } else {
        x+= direction;
    }
*/