#pragma once
#include "Block.h"
#include "Board.h"
class CyanBlock : public Block {
public:
    //CyanBlock();
    CyanBlock(int shape, int angle, int x, int y);
    int getColor() const;
    //bool check(Board& board);
    //void active(Board& board);
};