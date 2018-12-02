#include "game.h"
#include "ent_subtypes.h"

#define CHAR_COUNT 128

static void (* action_map [CHAR_COUNT])(Game *, Entity *, char);

void test_act(Game * g, Entity * e, char c){
  e->display_char++;
}

void ca_house(Game * g, Entity * e, char c){
  Ent_house * house = (Ent_house *) e->sub_data;
  g->display->menu_items[0] = house->entry_message;

  e->display_char++;
  e->collision_action = 0;
  g->game_state = moving;

}

void Start_action_loader(){
  for(int i = 0; i < CHAR_COUNT; i++){
    action_map[i] = 0;
  }

  /* Set what each character on the map means */
  action_map['A'] = &test_act;
  action_map['H'] = &ca_house;
}

void Map_action(Entity * e, char c){
  e->collision_action = action_map[c];
}
