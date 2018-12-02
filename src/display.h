#ifndef __DISPLAY__
#define __DISPLAY__

#include <ncurses.h>

#define SUB_WIN_WIDTH     50
#define SUB_WIN_HEIGHT    50

#define MAP_WIDTH         50
#define MAP_HEIGHT        50

#define MAX_MENU_OPS      10

#define PLAYER_CHAR    '@'

typedef struct{
  char screen_chars [MAP_HEIGHT][MAP_WIDTH];
  char * menu_title;
  char * menu_items[MAX_MENU_OPS];

  WINDOW * map;
  WINDOW * status;
  WINDOW * menu;
  WINDOW * headings;
} Display;

void Update_display(Display *);
Display * Start_display();


#endif
