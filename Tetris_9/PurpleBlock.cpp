#include "PurpleBlock.h"

PurpleBlock::PurpleBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

int PurpleBlock::getColor() const
{
    return VOILET;
}
