#include "WhiteBlock.h"

WhiteBlock::WhiteBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

int WhiteBlock::getColor() const
{
    return WHITE;
}
