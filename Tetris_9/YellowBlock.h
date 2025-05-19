#pragma once
#include "Block.h"
#include "Board.h"
class YellowBlock : public Block {
public:
    //YellowBlock();
    YellowBlock(int shape, int angle, int x, int y);
    int getColor() const;
    //bool check(Board& board);
    //void active(Board& board);
};