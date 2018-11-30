#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "display.h"
#include "game.h"
#include "types.h"

/* Everything is y,x because thats how ncurses functions are! */

int main(){
  Game * g = Start_game(Start_display());

  while(Update_game(g));

}


/*
    Display * d = Start_display();

    Update(d);

    wborder(stdscr, '.', '.', '.', '.', '.', '.', '.', '.');
    refresh();

    while(1);


    while(1){

        char c = getch();
        switch(c){
            case 27:
                endwin();
                return 0;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            default:
                break;
        }
        //clear();
        mvprintw(y, x, "@");
        refresh();

    }
    */
