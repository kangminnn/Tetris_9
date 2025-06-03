#include "BlueBlock.h"
#include "PurpleBlock.h"
#include "Constants.h"
#include "Renderer.h"
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
    return true;
}

void BlueBlock::active(Board& board)
{
    update();
}
void BlueBlock::update() {

    bool falling = true;

    while (falling) {
        falling = false;
        for (int i = 18; i >= 0; i--) { // 아래에서 위로 순회
            for (int j = 1; j <= 12; j++) {
                PurpleBlock::update(); // 퍼플 효과 적용
                if (total_block[i][j].color == BLUE && total_block[i][j].occupied == 1) {
                    if (total_block[i + 1][j].occupied == 0) {
                        // 이펙트 보여주기
                        Renderer::show_inner_block();
                        Sleep(50);

                        // 아래로 한 칸 이동
                        total_block[i + 1][j] = total_block[i][j];
                        total_block[i][j].occupied = 0;
                        total_block[i][j].color = 0;
                        total_block[i][j].count = 0;

                        falling = true; // 이번 프레임에서 이동 발생함
                    }
                }
            }
        }
    }
}