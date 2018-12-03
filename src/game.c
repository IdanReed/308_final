#include <ncurses.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "display.h"
#include "types.h"
#include "game.h"
#include "input.h"
#include "map_loader.h"

/*---Helper/standard action handlers---------------------------*/
void Add_player_stats(Display * d, Player * p){
  for(int i = 0; i < MAX_STATUS_CNT; i++){
    Stat s = p->stats[i];
    char * buff = malloc(sizeof(char)*50);
    strcpy(buff, s.name);


    char num[10];
    sprintf(num, "%d", s.value);

    strcpy(&buff[strlen(s.name)], num);
    d->status_items[i] = buff;
  }
}

static void collision_over(Game * g, Entity * e){
  g->game_state = moving;
  e->collision_action = 0;
  Clear_collision(g->display);
}

/*---Standard game actions-------------------------------------*/
void Move(Game * g, char c){
  Add_player_stats(g->display, g->player);

  switch(c){
      case 'a':
          g->player_x--;
          break;
      case 'd':
          g->player_x++;
          break;
      case 'w':
          g->player_y--;
          break;
      case 's':
          g->player_y++;
          break;
      default:
          break;
  }
}

void Act_Collision(Game * g){
  Entity * e = &(g->entity_board[g->player_y][g->player_x]);
  if(e->collision_action){
    g->game_state = locked;
  }
}

/* Kind of werid to have this here, but it needs entity and I don't want that in display */
void Fill_map(Game * g){
  for(int y = 0; y < MAP_HEIGHT - 1; y++){
    for(int x = 0; x < MAP_WIDTH - 1; x++){
      g->display->screen_chars[y][x] =
        g->entity_board[y + g->player_y - (MAP_HEIGHT/2)][x + g->player_x - (MAP_WIDTH/2)].display_char;
    }
  }
}

int Update_game(Game * g){
  Act_Collision(g);
  Direct_input(g);

  Fill_map(g);
  Update_display(g->display);
  refresh();
  return 1;
}

Player * init_player(){
  Player * p = malloc(sizeof(Player));

  for(int i = 0; i < MAX_STATUS_CNT; i++){
    p->stats[i].name = "STAT: ";
  }
  return p;
}

Game * Start_game(Display * d){
  Game * g = malloc(sizeof(Game));
  g->player = init_player();

  g->game_state = moving;
  g->display = d;
  g->player_x = 500;
  g->player_y = 500;
  return g;
}
