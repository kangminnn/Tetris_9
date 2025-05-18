//블록 정보, 회전, 이동
#pragma once
class Block {
protected:
    int shape;
    int angle;
    int x, y;
public:
    //Block();
    //Block(int shape);
    //void moveLeft();
    //void moveRight();
    //void moveDown();
    void rotate_block();
    //int getShape() const;
    //int getAngle() const;
    //int getX() const;
    //int getY() const;
    //void set(int shape, int angle, int x, int y);
};
