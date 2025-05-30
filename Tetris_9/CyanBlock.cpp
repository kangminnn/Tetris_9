#include "CyanBlock.h"
using namespace std;

CyanBlock::CyanBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool CyanBlock::check(const Board& board, int& level) const
{
    // 현재 스테이지에서 하늘색 블록의 능력이 비활성화되어 있다면 false 반환
    if (!stage_data[level].abilities.cyanBlockAbility) {
        return false;
    }
    // 블록이 착지했을 때만 능력 발동
    return true;
}

void CyanBlock::active(Board& board)
{
    // 하늘색 블록은 moveBlock에서 처리됨
// 여기서는 아무것도 하지 않음
}
