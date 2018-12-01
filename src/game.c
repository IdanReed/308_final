#include <ncurses.h>
#include <stdlib.h>
#include <stddef.h>

#include "display.h"
#include "types.h"
#include "game.h"
#include "input.h"
#include "map_loader.h"

void Act_Collision(Game * g){
  Entity * e = &(g->entity_board[g->player_y][g->player_x]);
  e->collision_action(g, e);
}

int Update_game(Game * g){
  Process_input(g);
  //Step_ents(g);
  Act_Collision(g);
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
