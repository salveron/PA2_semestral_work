#ifndef SEMESTRAL_WORK_CCHARACTER_H
#define SEMESTRAL_WORK_CCHARACTER_H

#include "CUnit.h"
#include <ncurses.h>

//----------------------------------------------------------------------------------------------------------------------

class CCharacter : public CUnit {
public:
    CCharacter() = default;
    CCharacter(int life);
    ~CCharacter() = default;

    virtual void Die() = 0;

    bool CheckLife();
protected:
    int Life;
};

//----------------------------------------------------------------------------------------------------------------------

class CPlayer : public CCharacter{
public:
    CPlayer() = delete;
    CPlayer(int life, int ammo);
    ~CPlayer() = default;

    void Die() override;
    void Print(int y_Pos, int x_Pos) const override;
    bool Move(int & x_Shift, int & y_Shift) const override;
private:
    int Ammo;
    bool PoweredUp;
    PowerUpType PUType;
};

//----------------------------------------------------------------------------------------------------------------------

class CEnemy : public CCharacter{
public:
    CEnemy() = delete;
    CEnemy(int life, EnemyType type);
    ~CEnemy() = default;

    void Die() override;
    void Print(int y_Pos, int x_Pos) const override;
    bool Move(int & x_Shift, int & y_Shift) const override;
private:
    EnemyType EType;
};

//----------------------------------------------------------------------------------------------------------------------

#endif //SEMESTRAL_WORK_CCHARACTER_H
