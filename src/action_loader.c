#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "game.h"
#include "display.h"
#include "ent_subtypes.h"

#define CHAR_COUNT 128

static void (* action_map [CHAR_COUNT])(Game *, Entity *, char);

/*---Helper/standard action handlers---------------------------*/
static void standard_eat(Game * g){
  int healing_amt = rand() % 20;
  g->player->stats[food].value--;
  g->player->stats[health].value += healing_amt;

  char * str = malloc(sizeof(char) * 200);
  snprintf(str, sizeof(char) * 200, "%s%d", "You eat: +", healing_amt);
  Add_to_log(g->display, str);
}
static void standard_atk(Game * g, int atk, int * hp, bool is_player){
  int dmg_done = rand() % atk;
  *hp -= dmg_done;

  char * str = malloc(sizeof(char) * 200);

  if(is_player){
    snprintf(str, sizeof(char) * 200, "%s%d", "You attack dealing: ", dmg_done);
  }else{
    snprintf(str, sizeof(char) * 200, "%s%d", "Occupant attacks dealing:", dmg_done);
  }

  Add_to_log(g->display, str);
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
    sleep(1);
    standard_atk(g, house->atk, &g->player->stats[health].value, 0);
    turn = player_turn;
  }else{
    switch(c){
      case 'a':{
        standard_atk(g, g->player->stats[atk].value, &house->hp, 1);
        turn = ent_turn;
        break;
      }
      case 'b':{
        standard_eat(g);
        turn = ent_turn;
        break;
      }

      case ERR:
        break;
      default:
        turn = ent_turn;
        break;
    }
  }


  if(house->hp <= 0){
    Add_to_log(g->display, "Victory");
    Collision_over(g, e);
  }else if (g->player->stats[health].value <= 0){
    endwin();
    exit(0);
  }

  e->display_char = 'X';
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
