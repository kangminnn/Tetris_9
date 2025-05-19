#include "CyanBlock.h"

CyanBlock::CyanBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

int CyanBlock::getColor() const
{
    return SKY_BLUE;
}
