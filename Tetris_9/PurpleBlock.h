#pragma once
#include "Block.h"
#include "Board.h"
class PurpleBlock : public Block {
public:
    //PurpleBlock();
    PurpleBlock(int shape, int angle, int x, int y);
    int getColor() const;
    //bool check(Board& board);
    //void active(Board& board);
};