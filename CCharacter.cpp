#include <iostream>
#include "CCharacter.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------

CCharacter::CCharacter(int life)
    : Life(life){}

bool CCharacter::CheckLife(){
    return Life != 0;
}

//----------------------------------------------------------------------------------------------------------------------

CPlayer::CPlayer(int life, int ammo)
    : CCharacter(life), Ammo(ammo), PoweredUp(false){
    Direction = {0,0,1,0};
}

void CPlayer::Die(){

}

void CPlayer::Print(int y_Pos, int x_Pos) const{
    attron(A_BOLD | COLOR_PAIR(1));
    if (Direction.Up == 1 && Direction.Down == 0 && Direction.Left == 0 && Direction.Right == 0)
        mvaddch(y_Pos, x_Pos, '^');
    else if (Direction.Up == 0 && Direction.Down == 1 && Direction.Left == 0 && Direction.Right == 0)
        mvaddch(y_Pos, x_Pos, 'v');
    else if (Direction.Up == 0 && Direction.Down == 0 && Direction.Left == 1 && Direction.Right == 0)
        mvaddch(y_Pos, x_Pos, '<');
    else if (Direction.Up == 0 && Direction.Down == 0 && Direction.Left == 0 && Direction.Right == 1)
        mvaddch(y_Pos, x_Pos, '>');
    else
        mvaddch(y_Pos, x_Pos, ACS_DIAMOND);
    attroff(A_BOLD | COLOR_PAIR(1));
}

bool CPlayer::Move(int & x_Shift, int & y_Shift) const{
    return false;
}

//----------------------------------------------------------------------------------------------------------------------

CEnemy::CEnemy(int life, EnemyType type)
    : CCharacter(life), EType(type){

    switch(EType){
        case Strong:
            Direction = {0,0,1,0};
            break;
        case Weak:
            Direction = {1,0,0,0};
            break;
    }
}

void CEnemy::Die(){

}

void CEnemy::Print(int y_Pos, int x_Pos) const{
    if(EType == Strong){
        attron(COLOR_PAIR(2));
        mvaddch(y_Pos, x_Pos, 'E');
        attroff(COLOR_PAIR(2));
    }
    else{
        attron(COLOR_PAIR(6));
        mvaddch(y_Pos, x_Pos, 'e');
        attroff(COLOR_PAIR(6));
    }
}

bool CEnemy::Move(int & x_Shift, int & y_Shift) const{
    x_Shift = Direction.Right - Direction.Left;
    y_Shift = Direction.Down - Direction.Up;
    return x_Shift != 0 || y_Shift != 0;
}

//----------------------------------------------------------------------------------------------------------------------