#include <ncurses.h>
#include <stdlib.h>
#include "display.h"

/* Only handle displaying to terminal, avoid game logic */

void test_fill_map(Display * d){
    int x_max;
    int y_max;
    getmaxyx(d->map, y_max, x_max);

    for(int y = 1; y < y_max-1; y++){
        for(int x = 1; x < x_max-1; x++){
            d->screen_chars[y][x] = '/';
        }
    }
}

void Display_inventory(Display * d){

}

void Display_map(Display * d){
    wborder(d->map, '.', '.', '.', '.', '.', '.', '.', '.');
    
    int x_max;
    int y_max;
    getmaxyx(d->map, y_max, x_max);

    for(int y = 1; y < y_max-1; y++){
        for(int x = 1; x < x_max-1; x++){
            wmove(d->map, y, x);
            waddch(d->map, d->screen_chars[y][x]);
        }
    }
    
}

void Update_display(Display * d){
    clear();
    
    switch(d->screen_state){
        case inv:
            break;
        case combat:
            break;
        case map:
            test_fill_map(d);
            Display_map(d);
            break;
        default:
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
    d->map = subwin(stdscr, MAP_HEIGHT, MAP_WIDTH, 20, 20);
    d->screen_state = map;

    d->inv = subwin(stdscr, MAP_HEIGHT, MAP_WIDTH, 20, 20);   
    d->combat = subwin(stdscr, MAP_HEIGHT, MAP_WIDTH, 20, 20);   

    return d;
}