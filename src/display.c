#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "display.h"

/* Try to only handle displaying to terminal, avoid game logic here */

#define HEADING_HEIGHT 5

void display_log(Display * d){
  for(int i = 0; i < 5; i++){
    int y_offset = i + (getmaxy(d->status) / 2) + 3;
    char * stat = d->log[i];
    mvwaddstr(d->status, y_offset, 3, stat);
  }
}

void Add_to_log(Display * d, char * str){

  for(int i = 5; i > 0; i--){
    d->log[i] = d->log[i - 1];
  }
  d->log[0] = str;

}

void display_status(Display * d){
  wborder(d->status, '.', '.', '.', '.', '.', '.', '.', '.');
  wmove(d->status, getmaxy(d->status) / 2, 0);
  whline(d->status, '.', getmaxx(d->status));

  for(int i = 0; i < MAX_STATUS_CNT; i++){
    mvwaddstr(d->status, i + 2, 3, d->status_items[i]);
  }
}

void display_map(Display * d){  /* Write display characters to map window */
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

  /* Write multiline menu title to menu window */
  int line_length = getmaxx(d->menu) - 5;
  int index_in_title = 0;
  int total_title_len = strlen(d->menu_title);
  char buff[line_length + 1];

  while(index_in_title + line_length < total_title_len){
    memcpy(buff, &(d->menu_title[index_in_title]), line_length);
    mvwaddstr(d->menu, floor(index_in_title / line_length) + 2, 3, buff);
    index_in_title += line_length;
  }

  mvwaddstr(d->menu,floor(index_in_title / line_length) + 2, 3, &d->menu_title[index_in_title]);

  /* Write action list */
  #define y_offset 10

  for(int i = 0; i < MAX_MENU_OPS; i++){
    mvwaddstr(d->menu,(i * 3) + y_offset, 5, d->menu_items[i]);

    if(strncmp( "", d->menu_items[i], 100)){
      mvwaddch(d->menu, (i * 3) + y_offset, 2, (i + 'A'));
      mvwaddch(d->menu, (i * 3) + y_offset, 3, ')');
    }
  }
}


void display_headings(Display * d ){                         /* TODO */
  wborder(d->headings, '.', '.', '.', '.', '.', '.', '.', '.');
}

void clear_log(Display * d){

  for(int i = 0; i < 5; i++){
    d->log[i] = "";
  }
}

void clear_status(Display * d){
  for(int i = 0; i < MAX_MENU_OPS; i++){
    d->menu_items[i] = "";
  }
}

void clear_menu(Display * d){
  d->menu_title = "";
  for(int i = 0; i < MAX_MENU_OPS; i++){
    d->menu_items[i] = "";
  }
}

void Fill_menu(Display * d, char * options[], char * collision_message){
  d->menu_title = collision_message;
  for(int i = 0; i < MAX_MENU_OPS; i++){
    d->menu_items[i] = options[i];
  }
}
void Clear_collision(Display * d){
  clear_menu(d);
  clear_status(d);
}
void Update_display(Display * d){
  //clear();
  erase();

  display_map(d);
  display_headings(d);
  display_menu(d);
  display_status(d);
  display_log(d);

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
  clear_status(d);
  clear_log(d);
  d->headings = subwin(stdscr, HEADING_HEIGHT, getmaxx(stdscr), 0, 0);
  d->menu_title = "";

  /* |MAP|MENU|STATUS| */
  d->map =        subwin(stdscr, SUB_WIN_HEIGHT, SUB_WIN_WIDTH, HEADING_HEIGHT, 0);
  d->menu =       subwin(stdscr, SUB_WIN_HEIGHT, getmaxx(stdscr) - (SUB_WIN_WIDTH*2), HEADING_HEIGHT, SUB_WIN_WIDTH);
  d->status =     subwin(stdscr, SUB_WIN_HEIGHT, SUB_WIN_WIDTH, HEADING_HEIGHT, getmaxx(stdscr) - SUB_WIN_WIDTH);

  return d;
}
