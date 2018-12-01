#ifndef __DISPLAY__
#define __DISPLAY__

#include <ncurses.h>

#define MAP_WIDTH       100
#define MAP_HEIGHT      50

#define PLAYER_CHAR    '@'

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

void Update_display(Display *);
void Display_map(Display * d);
Display * Start_display();


#endif
