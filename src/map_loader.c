#include <stdio.h>
#include <stdlib.h>

#include "map_loader.h"
#include "action_loader.h"
#include "game.h"

#define MAP_FILE "map.text"

void Load_map(Game * g){
  FILE * map_fp = fopen(MAP_FILE, "r");
  char buf[1000];

  for(int y = 0; y < ENT_HEIGHT; y++){
    fgets(buf, 1000, map_fp);
    for(int x = 0; x < ENT_WIDTH; x++){
      Entity e;
      Map_action(&e, buf[x]);
      e.display_char = buf[x];
      g->entity_board[y][x] = e;
    }
  }
}

void Generate_map(){
  FILE * map_fp = fopen(MAP_FILE, "w+");

  for(int y = 0; y < ENT_HEIGHT; y++){
    for(int x = 0; x < ENT_WIDTH; x++){

      int i = rand() % 1000;
      char c;

      if(i > 5){
        c = ' ';
      }else if(i > 2){
        c = 'C';
      }else{
        c = 'H';
      }

      fputc(c, map_fp);

    }
    fputc('\n', map_fp);
  }

  fclose(map_fp);
}
