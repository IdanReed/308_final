#include <ncurses.h>
#include <stdlib.h>

#include "display.h"
#include "types.h"
#include "game.h"


int Update_game(Game * g){
  return 1;
}

Game * Start_game(Display * d){
  Game * g = malloc(sizeof(Game));
  return g;
}
