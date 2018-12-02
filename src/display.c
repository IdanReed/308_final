#include <ncurses.h>
#include <stdlib.h>
#include "display.h"
#include <string.h>
#include <string.h>

/* Try to only handle displaying to terminal, avoid game logic here */

#define HEADING_HEIGHT 5

void display_inventory(Display * d){
  //wborder(d->combat, '.', '.', '.', '.', '.', '.', '.', '.');

}

void display_map(Display * d){
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


void display_menu(Display * d){
  wborder(d->menu, '.', '.', '.', '.', '.', '.', '.', '.');
  for(int i = 0; i < MAX_MENU_OPS; i++){

    mvwaddstr(d->menu,(i * 3) + 1 , 5, d->menu_items[i]);

    if(strncmp( "", d->menu_items[i], 100)){
      mvwaddch(d->menu, (i * 3) + 1, 2, (i + 'A'));
      mvwaddch(d->menu, (i * 3) + 1, 3, ')');
    }
  }
}

void display_headings(Display * d ){
  wborder(d->headings, '.', '.', '.', '.', '.', '.', '.', '.');
}

void display_status(Display * d){
  wborder(d->status, '.', '.', '.', '.', '.', '.', '.', '.');

}

void clear_menu(Display * d){
  for(int i = 0; i < MAX_MENU_OPS; i++){
    d->menu_items[i] = "";
  }
}

void Update_display(Display * d){
  //clear();
  erase();

  display_map(d);
  display_headings(d);
  display_menu(d);
  display_status(d);

  refresh();
}

Display * Start_display(){
  initscr();
  noecho();
  nodelay(stdscr, TRUE);
  curs_set(FALSE);
  clear();

  Display * d = malloc(sizeof(Display));

  clear_menu(d);
  d->headings = subwin(stdscr, HEADING_HEIGHT, getmaxx(stdscr), 0, 0);

  /* |MAP|MENU|STATUS| */
  d->map =        subwin(stdscr, SUB_WIN_HEIGHT, SUB_WIN_WIDTH, HEADING_HEIGHT, 0);
  d->menu =       subwin(stdscr, SUB_WIN_HEIGHT, getmaxx(stdscr) - (SUB_WIN_WIDTH*2), HEADING_HEIGHT, SUB_WIN_WIDTH);
  d->status =     subwin(stdscr, SUB_WIN_HEIGHT, SUB_WIN_WIDTH, HEADING_HEIGHT, getmaxx(stdscr) - SUB_WIN_WIDTH);

  return d;
}
