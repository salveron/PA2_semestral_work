#ifndef SEMESTRAL_WORK_CGAME_H
#define SEMESTRAL_WORK_CGAME_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <memory>
#include "CUnit.h"
#include "CCharacter.h"
#include "CBenefit.h"
#include <ncurses.h>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------

class CGame{
public:
    explicit CGame(ifstream & ifs);
    ~CGame() = default;

    void Draw();
    void Input();
    void Logic();

    bool Running();

    void SetPlayerDirection(const DirectionType & direction);
private:
    bool isRunning;
    int Width;
    int Height;
    vector<vector<shared_ptr<CUnit>>> Map;
    int P_x;
    int P_y;
    DirectionType PlayerDirection;
    int PlayerLife;
    int PlayerAmmo;
    void Swap(int a_x, int a_y, int b_x, int b_y);
};

//----------------------------------------------------------------------------------------------------------------------

#endif //SEMESTRAL_WORK_CGAME_H
