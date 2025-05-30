#include "RedBlock.h"

RedBlock::RedBlock(int shape, int angle, int x, int y)
	:Block(shape, angle, x, y)
{
}

bool RedBlock::check(const Board& board, int& level) const
{
	return false;
}

void RedBlock::active(Board& board)
{
}
