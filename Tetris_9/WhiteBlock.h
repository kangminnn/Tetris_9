#pragma once
#include "Block.h"
#include "Board.h"
class WhiteBlock : public Block {
public:
    //WhiteBlock();
    WhiteBlock(int shape, int angle, int x, int y);
    int getColor() const;
    //bool check(Board& board);
    //void active(Board& board);
};