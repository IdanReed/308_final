#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#include "display.h"
#include "game.h"
#include "types.h"
#include "map_loader.h"
#include "action_loader.h"

/* Everything is y,x because thats how ncurses functions are! */

int main(){
  Generate_map();
  Start_action_loader();

  Game * g = Start_game(Start_display());
  Load_map(g);

  while(Update_game(g));

}
