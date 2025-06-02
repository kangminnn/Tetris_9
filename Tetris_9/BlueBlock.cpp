#include "BlueBlock.h"
#include "Constants.h"
#include <vector>

BlueBlock::BlueBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool BlueBlock::check(const Board& board, int& level) const
{
    if (!stage_data[level].abilities.blueBlockAbility) {
        return false;
    }

    // 블록의 가장 아래 부분이 다른 블록과 접촉하는지 확인
    for (int j = 0; j < 4; j++) {
        bool hasBlock = false;
        int lowestY = -1;

        // 현재 열에서 가장 아래 블록 찾기
        for (int i = 3; i >= 0; i--) {
            if (block[shape][angle][i][j] == 1) {
                hasBlock = true;
                lowestY = y + i;
                break;
            }
        }

        if (hasBlock && lowestY >= 0 && lowestY < 19) {
            // 파란 블록 바로 아래에 다른 블록이 있고
            if (total_block[lowestY + 1][x + j].occupied == 1) {
                // 그 아래에 빈 공간이 있는지 확인
                for (int checkY = lowestY + 2; checkY < 20; checkY++) {
                    if (total_block[checkY][x + j].occupied == 0) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void BlueBlock::active(Board& board)
{
    // 각 열별로 처리
    for (int j = 0; j < 4; j++) {
        // 현재 열에서 파란 블록들의 위치 찾기 (위에서부터)
        vector<int> blockPositions;
        for (int i = 0; i < 4; i++) {
            if (block[shape][angle][i][j] == 1) {
                int realY = y + i;
                if (realY >= 0 && realY < 20) {
                    blockPositions.push_back(realY);
                }
            }
        }

        if (blockPositions.empty()) continue;

        // 가장 아래에 있는 블록 찾기
        int lowestY = blockPositions.back();
        if (lowestY >= 19) continue;

        // 아래 블록과 접촉 확인
        if (total_block[lowestY + 1][x + j].occupied == 1) {
            // 모든 빈 공간 찾기
            vector<int> emptySpaces;
            bool foundOccupied = false;

            // 접촉한 블록 바로 아래부터 검사
            for (int checkY = lowestY + 2; checkY < 20; checkY++) {
                if (!foundOccupied && total_block[checkY][x + j].occupied == 0) {
                    emptySpaces.push_back(checkY);
                }
                else if (total_block[checkY][x + j].occupied == 1) {
                    foundOccupied = true;  // 블록을 만남
                }
                else if (foundOccupied && total_block[checkY][x + j].occupied == 0) {
                    emptySpaces.push_back(checkY);  // 다음 빈 공간 시작
                    foundOccupied = false;
                }
            }

            if (!emptySpaces.empty()) {
                // 이동 전 현재 열의 상태 저장
                vector<pair<int, bool>> columnState;  // {y좌표, 이동했는지 여부}
                for (int pos : blockPositions) {
                    columnState.push_back({ pos, false });
                }

                // 파란 블록들을 아래서부터 이동 (가장 아래 있는 블록부터)
                for (int i = blockPositions.size() - 1; i >= 0; i--) {
                    int currentY = blockPositions[i];

                    // 현재 블록 아래의 가장 먼 빈 공간 찾기
                    int targetY = -1;
                    for (int k = emptySpaces.size() - 1; k >= 0; k--) {
                        if (emptySpaces[k] > currentY) {
                            targetY = emptySpaces[k];
                            emptySpaces.pop_back();  // 사용한 빈 공간 제거
                            break;
                        }
                    }

                    if (targetY != -1) {
                        // 현재 위치 비우기
                        total_block[currentY][x + j].occupied = 0;
                        total_block[currentY][x + j].color = 0;
                        total_block[currentY][x + j].count = 0;

                        // 새 위치에 블록 배치
                        total_block[targetY][x + j].occupied = 1;
                        total_block[targetY][x + j].color = BLUE;
                        total_block[targetY][x + j].count = 0;

                        // 이동 표시
                        columnState[i].second = true;
                    }
                }

                // 이동하지 않은 블록들을 아래로 이동
                int maxMoveDown = 0;  // 최대 이동 가능 거리
                for (int i = columnState.size() - 1; i >= 0; i--) {
                    if (columnState[i].second) {  // 이동한 블록 발견
                        maxMoveDown++;  // 위의 블록들이 내려올 수 있는 거리 증가
                    }
                    else if (maxMoveDown > 0) {  // 이동하지 않은 블록을 아래로 이동
                        int fromY = columnState[i].first;
                        int toY = fromY + maxMoveDown;

                        if (toY < 20) {
                            // 현재 위치 비우기
                            total_block[fromY][x + j].occupied = 0;
                            total_block[fromY][x + j].color = 0;
                            total_block[fromY][x + j].count = 0;

                            // 새 위치에 블록 배치
                            total_block[toY][x + j].occupied = 1;
                            total_block[toY][x + j].color = BLUE;
                            total_block[toY][x + j].count = 0;
                        }
                    }
                }
            }
        }
    }
}