#include <stdlib.h>

#include "game.h"
#include "types.h"



void Direct_input(Game * g){
  char c = getch();

  if((c > 'z' || c < 'a') && !(c == ERR)){
    endwin();
    exit(0);
  }

  switch(g->game_state){
    case moving:
      Move(g, c);
      break;
    case fighting:
      //g->entity_board[player_y][player_x].collision_action()

      break;
    default:

      break;
  }
  flushinp();

}
