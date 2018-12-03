#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "display.h"
#include "ent_subtypes.h"

#define CHAR_COUNT 128

static void (* action_map [CHAR_COUNT])(Game *, Entity *, char);

/*---Helper/standard action handlers---------------------------*/

static void standard_atk(int atk, int * hp){
  int dmg_done = rand() % atk;
  *hp -= dmg_done;
}


typedef enum { /* Keep track of who's turn it is */
  player_turn,
  ent_turn
} Turn;

/*---Ent action handlers---------------------------------------*/
void test_act(Game * g, Entity * e, char c){
  e->display_char++;
}

void ca_house(Game * g, Entity * e, char c){
  static Turn turn = ent_turn;
  Add_player_stats(g->display, g->player);

  Fill_menu(g->display, e->options, e->collision_message);
  Ent_house * house = (Ent_house *) e->sub_data;

  if(turn == ent_turn){
    //standard_atk(house->atk, &g->player->hp);
  }

  e->display_char = 'X';

  //collision_over(g, e);
}


/*---Action setup---------------------------------------------*/

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
