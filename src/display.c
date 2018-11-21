#include <ncurses.h>
#include <stdlib.h>
#include "display.h"

void display_map(WINDOW * map_win){
    wborder(map_win, '.', '.', '.', '.', '.', '.', '.', '.');
   
    /*
    int x_max;
    int y_max;
    getmaxyx(map_win, y_max, x_max);

    for(int y = 0; y < y_max; y++){
        for(int x = 0; x < x_max; x++){
            wmove(map_win, y, x);
            //waddch(m, d->screen_chars[y][x]);
            waddch(map_win, 'i');
        }
    }
    */
    
}

void display_inventory(Display * d){

}

void player_event(Display * d){

}

void test_fill_map(Display * d){

}

void Update(Display * d){
    clear();
    
    switch(d->screen_state){
        case inv:
            
            break;
        case combat:
            break;
        default:
            //display_map(d->map);
            break;
    }
    refresh();
}

Display * Start_display(){
    initscr();
    noecho();
    curs_set(FALSE);
    clear();

    Display * d = malloc(sizeof(Display));
    d->map = subwin(stdscr, MAP_WIDTH, MAP_HEIGHT, 0, 0);
    //d->screen_state = map;

    return d;
}