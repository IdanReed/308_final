#ifndef __GAME__
#define __GAME__

#include "display.h"

#define ENT_WIDTH       1000
#define ENT_HEIGHT      1000

typedef struct Game Game;
typedef struct Entity Entity;

typedef struct Entity{
  char display_char;
  void (* collision_action)(Game *, Entity *);
} Entity;

typedef struct Game{
  Entity entity_board[ENT_HEIGHT][ENT_WIDTH];
  int player_x;
  int player_y;
  Display * display;
} Game;

void Fill_display(Game *);

int Update_game(Game *);

void Load_ents(Game *, char *);

void Gen_ents(Game *, char *);

Game * Start_game(Display *);


/* DEBUGGING PROTOTYPES BELOW */



#endif
