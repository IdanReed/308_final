#include "game.h"

void test_act(Game * g, Entity * e){
  e->display_char++;
}

void Map_action(Entity * e, char c){
  if(c != ' '){
    e->collision_action = &test_act;
  }else{
    e->collision_action = 0;
  }
}
