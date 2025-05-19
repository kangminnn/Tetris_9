#include "BlueBlock.h"

BlueBlock::BlueBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

int BlueBlock::getColor() const
{
    return BLUE;
}
