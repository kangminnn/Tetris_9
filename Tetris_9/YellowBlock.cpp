#include "YellowBlock.h"

YellowBlock::YellowBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

int YellowBlock::getColor() const
{
    return YELLOW;
}
