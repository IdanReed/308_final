#include "game.h"

#define CHAR_COUNT 128

void (* action_map [CHAR_COUNT])(Game *, Entity *, char);

void test_act(Game * g, Entity * e, char c){
  e->display_char++;
}

void ca_house(Game * g, Entity * e, char c){
  //write_menu();
}

void Start_action_loader(){
  for(int i = 0; i < CHAR_COUNT; i++){
    action_map[i] = 0;
  }

  action_map['A'] = &test_act;
  action_map['H'] = &ca_house;
}

void Map_action(Entity * e, char c){
  e->collision_action = action_map[c];
}
