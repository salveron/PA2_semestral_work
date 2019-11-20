#ifndef SEMESTRAL_WORK_CBENEFIT_H
#define SEMESTRAL_WORK_CBENEFIT_H

#include "CUnit.h"
#include <ncurses.h>

//----------------------------------------------------------------------------------------------------------------------

class CBenefit : public CUnit{
public:
    CBenefit() = default;
    ~CBenefit() = default;

    virtual bool PickedUp() = 0;
    bool Move(int & x_Shift, int & y_Shift) const override;
};

//----------------------------------------------------------------------------------------------------------------------

class CLife : public CBenefit{
public:
    CLife() = delete;
    explicit CLife(int num);
    ~CLife() = default;

    bool PickedUp() override;
    void Print(int y_Pos, int x_Pos) const override;
private:
    int LifeNum;
};

//----------------------------------------------------------------------------------------------------------------------

class CAmmo : public CBenefit{
public:
    CAmmo() = delete;
    explicit CAmmo(int num);
    ~CAmmo() = default;

    bool PickedUp() override;
    void Print(int y_Pos, int x_Pos) const override;
private:
    int AmmoNum;
};

//----------------------------------------------------------------------------------------------------------------------

class CPowerUp : public CBenefit{
public:
    CPowerUp() = delete;
    explicit CPowerUp(PowerUpType type);
    ~CPowerUp() = default;

    bool PickedUp() override;
    void Print(int y_Pos, int x_Pos) const override;
private:
    PowerUpType PUType;
};

//----------------------------------------------------------------------------------------------------------------------

#endif //SEMESTRAL_WORK_CBENEFIT_H
