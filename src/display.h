#include <ncurses.h>

#ifndef display_h
#define display_h

#define MAP_WIDTH       50
#define MAP_HEIGHT      50

#define PLAYER_CHARC    '@'

typedef enum {
    map,
    combat,
    inv,
} State;

typedef struct{
    char screen_chars [MAP_HEIGHT][MAP_WIDTH];
    State screen_state;

    int player_y;
    int player_x;

    WINDOW * map;
    WINDOW * inv;
    WINDOW * combat;

} Display;

void Update_display(Display *);
void Display_map(Display * d);
Display * Start_display();


#endif