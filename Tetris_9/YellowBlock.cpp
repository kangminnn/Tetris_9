#include "YellowBlock.h"

YellowBlock::YellowBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool YellowBlock::check(const Board& board, int& level) const
{
    //����� ����� ���� check_full_lines()���� �ٷ�� �ֽ��ϴ�.
    return false;
}

void YellowBlock::active(Board& board)
{
}
