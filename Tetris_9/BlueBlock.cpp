#include "BlueBlock.h"
#include "Constants.h"
#include "PurpleBlock.h"

BlueBlock::BlueBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool BlueBlock::check(const Board& board, int& level) const
{
    // 보라색블록 작동되는지 확인
    if (stage_data[level].abilities.purpleBlockAbility) {
        PurpleBlock::update();
    }
    // 현재 스테이지에서 파란색 블록의 능력이 비활성화되어 있다면 false 반환
    if (!stage_data[level].abilities.blueBlockAbility) {
        return false;
    }
    
    // 블록의 각 열을 확인
    for (int j = 0; j < 4; j++) {
        bool hasBlockInColumn = false;
        int lowestBlockY = -1;

        // 현재 블록의 해당 열에서 가장 아래에 있는 블록 찾기
        for (int i = 3; i >= 0; i--) {
            if (block[shape][angle][i][j] == 1) {
                hasBlockInColumn = true;
                lowestBlockY = y + i;
                break;
            }
        }

        if (hasBlockInColumn && lowestBlockY >= 0 && lowestBlockY < 19) {  // 경계 체크
            // 파란 블록 바로 아래 칸 확인
            if (total_block[lowestBlockY + 1][x + j].occupied == 1) {
                return true;  // 능력 발동 조건 만족
            }
        }
    }
    return false;
}

void BlueBlock::active(Board& board)
{
    // 블록의 각 열을 확인
    for (int j = 0; j < 4; j++) {
        bool hasBlockInColumn = false;
        int lowestBlockY = -1;
        int highestBlockY = -1;

        // 현재 블록의 해당 열에서 가장 아래와 가장 위에 있는 블록 찾기
        for (int i = 3; i >= 0; i--) {
            if (block[shape][angle][i][j] == 1) {
                if (lowestBlockY == -1) {
                    lowestBlockY = y + i;
                }
                highestBlockY = y + i;
            }
        }

        if (total_block[lowestBlockY][x + j].color == VOILET) { return; }

        if (lowestBlockY >= 0 && lowestBlockY < 19) {  // 경계 체크
            // 파란 블록 바로 아래 칸에 블록이 있고, 그 아래가 보드 범위 내라면
            if (total_block[lowestBlockY + 1][x + j].occupied == 1 &&
                lowestBlockY + 2 < 20) {  // 보드 바닥 체크
                // 아래 블록을 한 칸 아래로 이동
                total_block[lowestBlockY + 2][x + j] = total_block[lowestBlockY + 1][x + j];
                total_block[lowestBlockY + 1][x + j].occupied = 0;
                total_block[lowestBlockY + 1][x + j].color = BLACK;
                total_block[lowestBlockY + 1][x + j].count = 0;

                // 파란 블록의 해당 열도 한 칸씩 아래로 이동
                for (int i = lowestBlockY; i >= highestBlockY; i--) {
                    if (i >= 0 && i < 20) {  // 보드 범위 체크
                        total_block[i + 1][x + j] = total_block[i][x + j];
                        if (i == highestBlockY) {  // 가장 위의 블록 위치는 비우기
                            total_block[i][x + j].occupied = 0;
                            total_block[i][x + j].color = BLACK;
                            total_block[i][x + j].count = 0;
                        }
                    }
                }
            }
        }
    }
}
