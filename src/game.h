#ifndef __GAME__
#define __GAME__

#include "display.h"

#define ENT_WIDTH       1000
#define ENT_HEIGHT      1000

typedef struct Game Game;
typedef struct Entity Entity;

typedef struct Entity{
  char display_char;
  void (* collision_action)(Game *, Entity *, char);

  void * sub_data;
} Entity;

typedef enum {
  moving,
  locked
} State;

typedef struct Player{
  int hp;
  int water;
  int food;
} Player;

typedef struct Game{
  Display * display;

  Entity entity_board[ENT_HEIGHT][ENT_WIDTH];

  int player_x;
  int player_y;

  Player player;
  State game_state;
} Game;

void Fill_map(Game *);

void Move(Game *, char);

int Update_game(Game *);

void Load_ents(Game *, char *);

void Gen_ents(Game *, char *);

Game * Start_game(Display *);


/* DEBUGGING PROTOTYPES BELOW */



#endif
