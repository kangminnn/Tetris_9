#include "PurpleBlock.h"

PurpleBlock::PurpleBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool PurpleBlock::check(const Board& board) const
{
    return false;
}

void PurpleBlock::active(Board& board)
{
}
