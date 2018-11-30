#include <ncurses.h>
#include <stdlib.h>
#include <stddef.h>

#include "display.h"
#include "types.h"
#include "game.h"
#include "input.h"

void test_act(Game * g, Entity * e){
  e->display_char++;
}

void test_fill_ents(Game * g){
  for(int y = 0; y < ENT_HEIGHT; y++){
    for(int x = 0; x < ENT_WIDTH; x++){
      Entity e;
      e.act = NULL;

      if(!(x%5)){
        e.act = &test_act;
        e.display_char = '|';
      }else if(y%2){
        e.display_char = 'a';
      }else{

        e.display_char = 'b';
      }

      g->entity_board[y][x] = e;
    }
  }
}

void Step_ents(Game * g){
  for(int y = 0; y < ENT_HEIGHT; y++){
    for(int x = 0; x < ENT_WIDTH; x++){
      Entity * e = &(g->entity_board[y][x]);
      if(e->act){
        (*e->act)(g, e);
      }
    }
  }
}

int Update_game(Game * g){
  Process_input(g);
  Step_ents(g);
  Fill_display(g);
  Update_display(g->display);
  refresh();
  return 1;
}

Game * Start_game(Display * d){
  Game * g = malloc(sizeof(Game));
  g->display = d;
  g->player_x = 500;
  g->player_y = 500;
  test_fill_ents(g);
  return g;
}

void Fill_display(Game * g){
  for(int y = 0; y < MAP_HEIGHT - 1; y++){
    for(int x = 0; x < MAP_WIDTH - 1; x++){
      g->display->screen_chars[y][x] =
        g->entity_board[y + g->player_y - (MAP_HEIGHT/2)][x + g->player_x - (MAP_WIDTH/2)].display_char;
    }
  }
}
