#include "CyanBlock.h"

CyanBlock::CyanBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool CyanBlock::check(const Board& board) const
{
    return false;
}

void CyanBlock::active(Board& board)
{
}
