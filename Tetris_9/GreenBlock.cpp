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
    // 현재 스테이지에서 초록색 블록의 능력이 비활성화되어 있다면 false 반환
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

    // 1. 현재 블록이 차지하는 셀들의 위치를 파악
    vector<pair<int, int>> blockCells;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (block[shape][angle][i][j] == 1) {
                blockCells.emplace_back(baseY + i, baseX + j);
            }
        }
    }

    // 2. 복제 블록을 위치시킬 수 있는 가장 가까운 높이 찾기
    int minOffsetY = 1;  // 최소 1칸 위부터 시작
    bool foundValidPosition = false;

    while (minOffsetY < 21) {  // 보드의 높이 제한
        bool canPlaceHere = true;

        // 현재 오프셋에서 모든 블록 셀이 유효한지 확인
        for (const auto& [cellY, cellX] : blockCells) {
            int newY = cellY - minOffsetY;

            // 보드 범위를 벗어나거나 이미 블록이 있는 경우
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

    // 3. 유효한 위치를 찾았다면 복제 블록 생성
    if (foundValidPosition) {
        // 새로운 GreenBlock 생성 (복제 블록)
        unique_ptr<Block> cloneBlock = make_unique<GreenBlock>(shape, angle, baseX, baseY - minOffsetY);
        // 복제된 블록의 abilityUsed를 true로 설정하여 연쇄 복제 방지
        static_cast<GreenBlock*>(cloneBlock.get())->abilityUsed = true;
        // 보드에 복제 블록 병합
        board.mergeBlock(cloneBlock);
    }
}