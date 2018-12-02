#include <ncurses.h>
#include <stdlib.h>
#include <stddef.h>

#include "display.h"
#include "types.h"
#include "game.h"
#include "input.h"
#include "map_loader.h"

void Move(Game * g, char c){
  switch(c){
      case 'a':
          g->player_x--;
          break;
      case 'd':
          g->player_x++;
          break;
      case 'w':
          g->player_y--;
          break;
      case 's':
          g->player_y++;
          break;
      default:
          break;
  }
}

void Act_Collision(Game * g){
  Entity * e = &(g->entity_board[g->player_y][g->player_x]);
  if(e->collision_action){
    //e->collision_action(g, e);
    g->game_state = fighting;
    
  }
}

void Fill_map(Game * g){
  for(int y = 0; y < MAP_HEIGHT - 1; y++){
    for(int x = 0; x < MAP_WIDTH - 1; x++){
      g->display->screen_chars[y][x] =
        g->entity_board[y + g->player_y - (MAP_HEIGHT/2)][x + g->player_x - (MAP_WIDTH/2)].display_char;
    }
  }
}

int Update_game(Game * g){
  Direct_input(g);
  Act_Collision(g);
  Fill_map(g);
  Update_display(g->display);
  refresh();
  return 1;
}

Game * Start_game(Display * d){
  Game * g = malloc(sizeof(Game));

  g->game_state = moving;
  g->display = d;
  g->player_x = 500;
  g->player_y = 500;
  return g;
}
