#include "GreenBlock.h"
#include <utility>
#include <vector>
#include "Constants.h"
using namespace std;

GreenBlock::GreenBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
    abilityUsed = false;
}

bool GreenBlock::check(const Board& board, int& level) const
{
    // ���� ������������ �ʷϻ� ����� �ɷ��� ��Ȱ��ȭ�Ǿ� �ִٸ� false ��ȯ
    if (!stage_data[level].abilities.greenBlockAbility) {
        return false;
    }
    return true;
}

void GreenBlock::active(Board& board) {
    if (abilityUsed) return;
    abilityUsed = true;

    int shape = getShape();
    int angle = getAngle();
    int baseX = getX();
    int baseY = getY();

    // 1. ���� ����� �����ϴ� ������ ��ġ�� �ľ�
    vector<pair<int, int>> blockCells;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (block[shape][angle][i][j] == 1) {
                blockCells.emplace_back(baseY + i, baseX + j);
            }
        }
    }

    // 2. ���� ����� ��ġ��ų �� �ִ� ���� ����� ���� ã��
    int minOffsetY = 1;  // �ּ� 1ĭ ������ ����
    bool foundValidPosition = false;

    while (minOffsetY < 21) {  // ������ ���� ����
        bool canPlaceHere = true;

        // ���� �����¿��� ��� ��� ���� ��ȿ���� Ȯ��
        for (const auto& [cellY, cellX] : blockCells) {
            int newY = cellY - minOffsetY;

            // ���� ������ ����ų� �̹� ����� �ִ� ���
            if (newY < 0 || total_block[newY][cellX].occupied) {
                canPlaceHere = false;
                break;
            }
        }

        if (canPlaceHere) {
            foundValidPosition = true;
            break;
        }

        minOffsetY++;
    }

    // 3. ��ȿ�� ��ġ�� ã�Ҵٸ� ���� ��� ����
    if (foundValidPosition) {
        // ���ο� GreenBlock ���� (���� ���)
        unique_ptr<Block> cloneBlock = make_unique<GreenBlock>(shape, angle, baseX, baseY - minOffsetY);
        // ������ ����� abilityUsed�� true�� �����Ͽ� ���� ���� ����
        static_cast<GreenBlock*>(cloneBlock.get())->abilityUsed = true;
        // ���忡 ���� ��� ����
        board.mergeBlock(cloneBlock);
    }
}