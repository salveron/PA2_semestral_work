#include <iostream>
#include <fstream>
#include <sstream>
#include "CGame.h"
#include "CUnit.h"
#include "CCharacter.h"
#include "CBenefit.h"
#include <ncurses.h>

int main(int argc, char * argv []){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    //keypad(stdscr, true);

    ifstream ifs;
    ifs.open("Map.txt", ios::in);
    if(!ifs){
        endwin();
        return 1;
    }
    CGame game (ifs);
    ifs.close();

    while(game.Running()){
        game.Draw();
        game.Input();
        game.Logic();
    }

    refresh();
    endwin();
    return 0;
}
