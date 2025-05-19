#include "GreenBlock.h"

GreenBlock::GreenBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

int GreenBlock::getColor() const
{
    return GREEN;
}
