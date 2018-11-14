#ifndef screen_h
#define screen_h
#define SCREEN_SIZE 25
typedef enum {
    map,
    combat,
    inv
} screen_state;

typedef struct{
    char screenText [SCREEN_SIZE][SCREEN_SIZE];
    screen_state state;
} Screen;


void Init();
void fill_screen(Screen s);
void Display_map(Screen s);

#endif