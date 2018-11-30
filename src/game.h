#include "display.h"

#define ENT_WIDTH       1000
#define ENT_HEIGHT      1000

typedef struct Game Game;
typedef struct Entity Entity;

typedef struct Entity{
  char display_char;
  void (* act)(Game *, Entity *);
  
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
void test_fill_ents(Game *);
