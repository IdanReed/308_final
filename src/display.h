#ifndef __DISPLAY__
#define __DISPLAY__

#include <ncurses.h>

#define SUB_WIN_WIDTH     50
#define SUB_WIN_HEIGHT    50

#define MAP_WIDTH         50
#define MAP_HEIGHT        50

#define MAX_MENU_OPS      10
#define MAX_STATUS_CNT    10

#define PLAYER_CHAR    '@'

/*
This is to keep window stuff out of game
and game stuff out of display. The collision handlers
fill data in display which then gets put to the
correct window.
*/

typedef struct{
  /* map */
  char screen_chars [MAP_HEIGHT][MAP_WIDTH];

  /* menu */
  char * menu_title;
  char * menu_items[MAX_MENU_OPS];

  /* status */
  char * status_items[MAX_STATUS_CNT];

  /* windows */
  WINDOW * map;
  WINDOW * status;
  WINDOW * menu;
  WINDOW * headings;
} Display;

void Update_display(Display *);
Display * Start_display();
void Fill_menu(Display * d, char * options[], char * collision_message);
void Clear_collision(Display * d);


#endif
