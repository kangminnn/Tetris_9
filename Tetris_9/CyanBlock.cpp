#include "CyanBlock.h"
using namespace std;

CyanBlock::CyanBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool CyanBlock::check(const Board& board, int& level) const
{
    // ���� ������������ �ϴû� ����� �ɷ��� ��Ȱ��ȭ�Ǿ� �ִٸ� false ��ȯ
    if (!stage_data[level].abilities.cyanBlockAbility) {
        return false;
    }
    // ����� �������� ���� �ɷ� �ߵ�
    return true;
}

void CyanBlock::active(Board& board)
{
    // �ϴû� ����� moveBlock���� ó����
// ���⼭�� �ƹ��͵� ���� ����
}
