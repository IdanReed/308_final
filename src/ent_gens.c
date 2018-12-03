#include <stdlib.h>
#include "col_msgs.h"
#include "game.h"
#include "ent_subtypes.h"

void clear_options(char * options []){
  for(int i = 1; i < 10; i ++){
    options[i] = "";
  }
}

void init_house(Entity * e){
  clear_options(e->options);
  e->options[0] = "attack";
  
  e->collision_message = messages[rand()%10];

  Ent_house * house = malloc(sizeof(Ent_house));
  e->sub_data = (void *) house;
  house->hp = 100;
  house->atk = 10;
}
