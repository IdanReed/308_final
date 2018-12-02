#include <stdio.h>
#include <stdlib.h>

#include "map_loader.h"
#include "action_loader.h"
#include "game.h"
#include "ent_subtypes.h"
#include "ent_gens.h"

#define MAP_FILE "map.text"
#define CHAR_COUNT 128

static void (* ent_gen_map [CHAR_COUNT])(Entity *);

static void set_ent_gens(){
  for(int i = 0; i < CHAR_COUNT; i++){
    ent_gen_map[i] = 0;
  }

  ent_gen_map['H'] = &init_house;
}

void Load_map(Game * g){
  set_ent_gens();

  FILE * map_fp = fopen(MAP_FILE, "r");
  char buf[1000];

  for(int y = 0; y < ENT_HEIGHT; y++){
    fgets(buf, 1000, map_fp);
    for(int x = 0; x < ENT_WIDTH; x++){
      char read_char = buf[x];

      Entity e;
      Map_action(&e, read_char);
      e.display_char = read_char;
      g->entity_board[y][x] = e;
      if(ent_gen_map[read_char]){
        ent_gen_map[read_char](&e);
      }
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
