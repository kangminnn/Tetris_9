#include "YellowBlock.h"

YellowBlock::YellowBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool YellowBlock::check(const Board& board, int& level) const
{
    // 노란색 블록은 moveBlock에서 처리됨
    // 여기서는 아무것도 하지 않음
    return false;
}

void YellowBlock::active(Board& board)
{
    // 노란색 블록은 moveBlock에서 처리됨
    // 여기서는 아무것도 하지 않음
}
