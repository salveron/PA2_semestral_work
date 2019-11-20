#include <iostream>
#include "CUnit.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------

CUnit::CUnit()
    : Printed(false), Direction({0,0,0,0}){}


CUnit::CUnit(DirectionType direction)
        : Printed(false), Direction(direction){}

void CUnit::ChangeDirection(){
    int tmp = Direction.Up;
    Direction.Up = Direction.Down;
    Direction.Down = tmp;
    tmp = Direction.Left;
    Direction.Left = Direction.Right;
    Direction.Right = tmp;
}

void CUnit::SetDirection(const DirectionType & direction){
    Direction = direction;
}

void CUnit::SetPrinted(bool value){
    Printed = value;
}

bool CUnit::GetPrinted(){
    return Printed;
}

//----------------------------------------------------------------------------------------------------------------------

void CWall::Print(int x_Pos, int y_Pos) const{
    attron(COLOR_PAIR(7));
    mvaddch(x_Pos, y_Pos, ACS_CKBOARD);
    attroff(COLOR_PAIR(7));
}

bool CWall::Move(int & x_Shift, int & y_Shift) const{
    return false;
}

//----------------------------------------------------------------------------------------------------------------------

CBullet::CBullet(DirectionType direction)
    : CUnit(direction){}

void CBullet::Print(int x_Pos, int y_Pos) const{
    attron(COLOR_PAIR(4));
    mvaddch(x_Pos, y_Pos, ACS_BULLET);
    attroff(COLOR_PAIR(4));
}

bool CBullet::Move(int & x_Shift, int & y_Shift) const{
    return false;//todo
}

//----------------------------------------------------------------------------------------------------------------------