#include "CyanBlock.h"
using namespace std;

CyanBlock::CyanBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool CyanBlock::check(const Board& board, int& level) const
{
    // 하늘색 블록은 moveBlock에서 처리됨
    // 여기서는 아무것도 하지 않음
    return false;
}

void CyanBlock::active(Board& board)
{
    // 하늘색 블록은 moveBlock에서 처리됨
    // 여기서는 아무것도 하지 않음
}
