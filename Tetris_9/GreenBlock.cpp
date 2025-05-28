#include "GreenBlock.h"
#include <set>
#include <utility>
#include <iostream>
#include <vector>
#include "Constants.h"
using namespace std;

GreenBlock::GreenBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
    abilityUsed = false;
}

bool GreenBlock::check(const Board& board) const
{
    return true;
}

void GreenBlock::active(Board& board) {
    if (abilityUsed) return;
    abilityUsed = true;

    int shape = getShape();
    int angle = getAngle();
    int baseX = getX();
    int baseY = getY();

    // 1. 블록의 상대 위치 수집
    vector<pair<int, int>> cells;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (block[shape][angle][i][j] == 1)
                cells.emplace_back(i, j); // (dy, dx)

    // 2. 최대 몇 칸 위로 올릴 수 있는지 계산
    int maxOffset = 0;
    while (true) {
        bool canMoveUp = true;
        for (const auto& [dy, dx] : cells) {
            int newY = baseY + dy - (maxOffset + 1); // 위로 올리기
            int newX = baseX + dx;
            if (newY < 0 || total_block[newY][newX].occupied) {
                canMoveUp = false;
                break;
            }
        }
        if (!canMoveUp) break;
        ++maxOffset;
    }

    if (maxOffset == 0) return; // 복제 불가능

    // 3. 복제 생성 (위로 maxOffset만큼 올려서 복사)
    unique_ptr<Block> clone = make_unique<GreenBlock>(shape, angle, baseX, baseY - maxOffset);
    board.mergeBlock(clone);
}

