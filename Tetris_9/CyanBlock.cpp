#include "CyanBlock.h"
using namespace std;

CyanBlock::CyanBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool CyanBlock::check(const Board& board, int& level) const
{
    // �ϴû� ����� moveBlock���� ó����
    // ���⼭�� �ƹ��͵� ���� ����
    return false;
}

void CyanBlock::active(Board& board)
{
    // �ϴû� ����� moveBlock���� ó����
    // ���⼭�� �ƹ��͵� ���� ����
}
