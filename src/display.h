#include <ncurses.h>

#ifndef display_h
#define display_h

#define MAP_WIDTH       25
#define MAP_HEIGHT      25

typedef enum {
    map,
    combat,
    inv,
} State;

typedef struct{
    char screen_chars [MAP_HEIGHT][MAP_WIDTH];
    State screen_state;

    WINDOW * map;
    WINDOW * inv;
    WINDOW * combat;

} Display;

void Update(Display *);
void Display_map(WINDOW *);
Display * Start_display();

#endif