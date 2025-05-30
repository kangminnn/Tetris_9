#include "YellowBlock.h"

YellowBlock::YellowBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool YellowBlock::check(const Board& board, int& level) const
{
    //노란색 블록은 보드 check_full_lines()에서 다루고 있습니다.
    return false;
}

void YellowBlock::active(Board& board)
{
}
