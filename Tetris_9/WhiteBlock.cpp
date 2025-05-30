#include "WhiteBlock.h"

WhiteBlock::WhiteBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool WhiteBlock::check(const Board& board, int& level) const
{
    return false;
}

void WhiteBlock::active(Board& board)
{
    //¹«´É·Â
}
