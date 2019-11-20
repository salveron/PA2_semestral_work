#include <iostream>
#include "CBenefit.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------

bool CBenefit::Move(int &x_Shift, int &y_Shift) const{
    return false;
}

//----------------------------------------------------------------------------------------------------------------------

CLife::CLife(int num)
    : LifeNum(num){}

bool CLife::PickedUp(){
    return false;
}

void CLife::Print(int y_Pos, int x_Pos) const{
    attron(COLOR_PAIR(3));
    mvaddch(y_Pos, x_Pos, '+');
    attroff(COLOR_PAIR(3));
}

//----------------------------------------------------------------------------------------------------------------------

CAmmo::CAmmo(int num)
    : AmmoNum(num){}

bool CAmmo::PickedUp(){
    return false;
}

void CAmmo::Print(int y_Pos, int x_Pos) const{
    attron(COLOR_PAIR(4));
    mvaddch(y_Pos, x_Pos, 'A');
    attroff(COLOR_PAIR(4));
}

//----------------------------------------------------------------------------------------------------------------------

CPowerUp::CPowerUp(PowerUpType type)
    : PUType(type){}

bool CPowerUp::PickedUp(){
    return false;
}

void CPowerUp::Print(int y_Pos, int x_Pos) const{
    mvaddch(y_Pos, x_Pos, '=');
}

//----------------------------------------------------------------------------------------------------------------------