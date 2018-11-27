#include "display.h"

#define ENT_WIDTH       1000
#define ENT_HEIGHT      1000

typedef struct{
    int entity_board[ENT_HEIGHT][ENT_WIDTH];
    int x;
    int y;
    Display * d;
} Game;


void Fill_display(Game *);

int Update_game(Game *);

void Load_ents(Game *, char *);

void Gen_ents(Game *, char *);

Game * Start_game(Display *);
