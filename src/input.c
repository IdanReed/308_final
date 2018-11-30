#include <stdlib.h>

#include "game.h"
#include "types.h"

void Process_input(Game * g){
  char c = getch();
  if(c != ERR){
    switch(c){
        case 27:
            endwin();
            exit(0);
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
}
