#include <ncurses.h>
#include <stdlib.h>
#include "display.h"

/* Only handle displaying to terminal, avoid game logic */

void Display_inventory(Display * d){

}

void Display_map(Display * d){
    wborder(d->map, '.', '.', '.', '.', '.', '.', '.', '.');

    for(int y = 1; y < MAP_HEIGHT-1; y++){
        for(int x = 1; x < MAP_WIDTH-1; x++){
            wmove(d->map, y, x);
            waddch(d->map, d->screen_chars[y][x]);
        }
    }

    wmove(d->map, (MAP_HEIGHT/2), (MAP_WIDTH/2));
    waddch(d->map, PLAYER_CHAR);

}

void Update_display(Display * d){
    erase();

    switch(d->screen_state){
        case inv:
            break;
        case combat:
            break;
        case map:

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
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    clear();

    Display * d = malloc(sizeof(Display));

    d->map = subwin(stdscr, MAP_HEIGHT, MAP_WIDTH,
      (getmaxy(stdscr) - MAP_HEIGHT) / 2,
      (getmaxx(stdscr) - MAP_WIDTH) / 2);

    d->inv = subwin(stdscr, MAP_HEIGHT, MAP_WIDTH, 20, 20);
    d->combat = subwin(stdscr, MAP_HEIGHT, MAP_WIDTH, 20, 20);

    d->screen_state = map;

    return d;
}
