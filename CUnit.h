#ifndef SEMESTRAL_WORK_CUNIT_H
#define SEMESTRAL_WORK_CUNIT_H

#include <ncurses.h>

//----------------------------------------------------------------------------------------------------------------------

enum PowerUpType{DoubleDamage, Immunity, Ammo, Life};
enum EnemyType{Weak, Strong};
struct DirectionType{
    int Up;
    int Down;
    int Left;
    int Right;
};

//----------------------------------------------------------------------------------------------------------------------

class CUnit{
public:

    CUnit();
    explicit CUnit(DirectionType direction);
    ~CUnit() = default;

    virtual void Print(int y_Pos, int x_Pos) const = 0;
    virtual bool Move(int & x_Shift, int & y_Shift) const = 0;

    void ChangeDirection();
    void SetDirection(const DirectionType & direction);
    void SetPrinted(bool value);
    bool GetPrinted();

protected:
    bool Printed;
    DirectionType Direction;
};

//----------------------------------------------------------------------------------------------------------------------

class CWall : public CUnit{
public:
    CWall() = default;
    ~CWall() = default;

    void Print(int y_Pos, int x_Pos) const override;
    bool Move(int & x_Shift, int & y_Shift) const override;
};

//----------------------------------------------------------------------------------------------------------------------

class CBullet : public CUnit{
public:
    CBullet() = default;
    explicit CBullet(DirectionType direction);
    ~CBullet() = default;

    void Print(int y_Pos, int x_Pos) const override;
    bool Move(int & x_Shift, int & y_Shift) const override;
};

//----------------------------------------------------------------------------------------------------------------------

#endif //SEMESTRAL_WORK_CUNIT_H