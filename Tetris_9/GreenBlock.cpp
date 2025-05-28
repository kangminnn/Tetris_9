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

    // 1. ����� ��� ��ġ ����
    vector<pair<int, int>> cells;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (block[shape][angle][i][j] == 1)
                cells.emplace_back(i, j); // (dy, dx)

    // 2. �ִ� �� ĭ ���� �ø� �� �ִ��� ���
    int maxOffset = 0;
    while (true) {
        bool canMoveUp = true;
        for (const auto& [dy, dx] : cells) {
            int newY = baseY + dy - (maxOffset + 1); // ���� �ø���
            int newX = baseX + dx;
            if (newY < 0 || total_block[newY][newX].occupied) {
                canMoveUp = false;
                break;
            }
        }
        if (!canMoveUp) break;
        ++maxOffset;
    }

    if (maxOffset == 0) return; // ���� �Ұ���

    // 3. ���� ���� (���� maxOffset��ŭ �÷��� ����)
    unique_ptr<Block> clone = make_unique<GreenBlock>(shape, angle, baseX, baseY - maxOffset);
    board.mergeBlock(clone);
}

