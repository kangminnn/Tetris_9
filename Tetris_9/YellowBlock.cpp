#include "YellowBlock.h"

YellowBlock::YellowBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool YellowBlock::check(const Board& board, int& level) const
{
    // ����� ����� moveBlock���� ó����
    // ���⼭�� �ƹ��͵� ���� ����
    return false;
}

void YellowBlock::active(Board& board)
{
    // ����� ����� moveBlock���� ó����
    // ���⼭�� �ƹ��͵� ���� ����
}
