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
    case locked:{
        Entity * e = &(g->entity_board[g->player_y][g->player_x]);
        e->collision_action(g, e, c);
        //collision_action()
      }
      break;
    default:

      break;
  }
  flushinp();

}
