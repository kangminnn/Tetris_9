#include "RedBlock.h"

RedBlock::RedBlock(int shape, int angle, int x, int y)
	:Block(shape, angle, x, y)
{
}

int RedBlock::getColor() const
{
	return RED;
}
