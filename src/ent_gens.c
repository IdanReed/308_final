#include <stdlib.h>

#include "game.h"
#include "ent_subtypes.h"

void init_house(Entity * e){
  Ent_house * house = malloc(sizeof(Ent_house));
  house->entry_message = "yo";

  e->sub_data = (void *) house;
}
