#include "BlueBlock.h"

BlueBlock::BlueBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool BlueBlock::check(const Board& board) const
{
    return false;
}

void BlueBlock::active(Board& board)
{
}
