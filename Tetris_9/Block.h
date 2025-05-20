//블록 정보, 회전, 이동
#pragma once
#include "Constants.h"

class Block {
protected:
    int shape;
    int angle;
    int x, y;
public:
    Block() = default;
    Block(int shape, int angle, int x, int y);
    //void rotate_block();
    virtual int getColor() const; 
    int getShape() const;
    int getAngle() const;
    int getX() const;
    int getY() const;
    void setAngle(int angle);
    void setX(int x);
    void setY(int y);
    void set(int shape, int angle, int x, int y);
};
