#pragma once

class Block {
private:
    int shape[4][4];   // 4x4 ºí·Ï
    int x, y;
public:
    void moveLeft();
    void moveRight();
    void moveDown();
    void rotate();
    int** getShape();
    int getX() const;
    int getY() const;
};
