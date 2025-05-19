#pragma once
#include "Block.h"
#include "Board.h"
class BlueBlock : public Block {
public:
    //BlueBlock();
    BlueBlock(int shape, int angle, int x, int y);
    int getColor() const;
    //bool check(Board& board);
    //void active(Board& board);
};