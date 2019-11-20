#include "CGame.h"
using namespace std;

#define KEY_MOVE_UP 'w'
#define KEY_MOVE_DOWN 's'
#define KEY_MOVE_LEFT 'a'
#define KEY_MOVE_RIGHT 'd'
#define KEY_QUIT 'q'
#define KEY_SHOOT ' '

//----------------------------------------------------------------------------------------------------------------------

CGame::CGame(ifstream & ifs)
    :isRunning(true), PlayerDirection({0,0,1,0}){

    string line;
    int cnt = 0;

    Map.resize(1000);

    while(getline(ifs, line)){
        for(int i = 0; i < (int)line.size(); i++){
            switch(line.at(i)){
                case '#':
                    Map.at(cnt).push_back(make_shared <CWall> ());
                    break;
                case ' ':
                    Map.at(cnt).push_back(nullptr);
                    break;
                case 'i':
                    Map.at(cnt).push_back(make_shared <CPlayer> (3, 5));
                    P_x = i;
                    P_y = cnt;
                    PlayerLife = 3;
                    PlayerAmmo = 5;
                    break;
                case 'E':
                    Map.at(cnt).push_back(make_shared <CEnemy> (2, Strong));
                    break;

                case 'e':
                    Map.at(cnt).push_back(make_shared <CEnemy> (1, Weak));
                    break;
                case 'A':
                    Map.at(cnt).push_back(make_shared <CAmmo> (5));
                    break;
                case '+':
                    Map.at(cnt).push_back(make_shared <CLife> (1));
                    break;
            }
        }
        cnt++;
    }

    Width = (int)line.size();
    Height = cnt;

    Map.resize(cnt);
}

//----------------------------------------------------------------------------------------------------------------------

void CGame::Draw(){
    for(int i = 0; i < Height; i++){
        for (int j = 0; j < Width; j++){
            if (!Map.at(i).at(j)){
                attron(COLOR_PAIR(0));
                mvaddch(i, j, ' ');
                attroff(COLOR_PAIR(0));
            }
            else
                if (!Map.at(i).at(j)->GetPrinted()) {
                    Map.at(i).at(j)->Print(i, j);
                    Map.at(i).at(j)->SetPrinted(true);
                }
            refresh();
        }
        mvaddch(i, Width, '\n');
        refresh();
    }

    attron(A_BOLD);
    mvprintw(1, Width + 2, "Height: %d", Height);
    mvprintw(2, Width + 2, "Width: %d", Width);
    mvprintw(3, Width + 2, "Lives: %d", PlayerLife);
    mvprintw(4, Width + 2, "Ammo: %d", PlayerAmmo);
    mvprintw(5, Width + 2, "Player x position: %d", P_x);
    mvprintw(6, Width + 2, "Player y position: %d", P_y);
    attroff(A_BOLD);
}

//----------------------------------------------------------------------------------------------------------------------

void CGame::Input(){
    halfdelay(5);

    int ch = getch();

    switch(ch){
        case KEY_MOVE_UP:
            if(!Map.at(P_y - 1).at(P_x)){
                Swap(P_y, P_x, P_y - 1, P_x);
                P_y--;
            }
            SetPlayerDirection({1,0,0,0});
            break;
        case KEY_MOVE_DOWN:
            if(!Map.at(P_y + 1).at(P_x)){
                Swap(P_y, P_x, P_y + 1, P_x);
                P_y++;
            }
            SetPlayerDirection({0,1,0,0});
            break;
        case KEY_MOVE_LEFT:
            if(!Map.at(P_y).at(P_x - 1)){
                Swap(P_y, P_x, P_y, P_x - 1);
                P_x--;
            }
            SetPlayerDirection({0,0,1,0});
            break;
        case KEY_MOVE_RIGHT:
            if(!Map.at(P_y).at(P_x + 1)){
                Swap(P_y, P_x, P_y, P_x + 1);
                P_x++;
            }
            SetPlayerDirection({0,0,0,1});
            break;
        case KEY_SHOOT:
            if (PlayerAmmo > 0){
                PlayerAmmo--;
            }
            break;
        case KEY_QUIT:
            isRunning = false;
            break;
    }
}

//----------------------------------------------------------------------------------------------------------------------

void CGame::Logic(){
    int x_Sh, y_Sh;

    for (int i = 0; i < Height; i++){
        for (int j = 0; j < Width; j++){
            if(Map.at(i).at(j) && Map.at(i).at(j)->Move(x_Sh, y_Sh) && i + y_Sh >= 0 && i + y_Sh < Height && j + x_Sh >= 0 && j + x_Sh < Width){
                if (!Map.at(i + y_Sh).at(j + x_Sh)){
                    Swap(i, j, i + y_Sh, j + x_Sh);
                }
                else{
                    Map.at(i).at(j)->ChangeDirection();
                }
            }
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------

bool CGame::Running(){
    return isRunning;
}

//----------------------------------------------------------------------------------------------------------------------

void CGame::Swap(int a_y, int a_x, int b_y, int b_x){
    Map.at(a_y).at(a_x)->SetPrinted(false);
    if (Map.at(b_y).at(b_x))
        Map.at(b_y).at(b_x)->SetPrinted(false);
    Map.at(a_y).at(a_x).swap(Map.at(b_y).at(b_x));
}

//----------------------------------------------------------------------------------------------------------------------

void CGame::SetPlayerDirection(const DirectionType & direction){
    Map.at(P_y).at(P_x)->SetDirection(direction);
    PlayerDirection = direction;
}

//----------------------------------------------------------------------------------------------------------------------