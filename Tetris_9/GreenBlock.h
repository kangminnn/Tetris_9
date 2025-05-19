#pragma once
#include "Block.h"
#include "Board.h"
class GreenBlock : public Block {
public:
    //GreenBlock();
    GreenBlock(int shape, int angle, int x, int y);
    int getColor() const;
    //bool check(Board& board);
    //void active(Board& board);
};