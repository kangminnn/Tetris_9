#include "BlueBlock.h"
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
    for (int j = 1; j <= 12; j++) {
        for (int i = 18; i >= 0; i--) { // 아래에서 위로
            if (total_block[i][j].color == BLUE && total_block[i][j].occupied == 1) {
                int k = i;
                while (k + 1 < 20 && total_block[k + 1][j].occupied == 0) {
                    k++;
                }
                if (k != i) {
                    // 아래로 이동
                    total_block[k][j] = total_block[i][j];
                    total_block[i][j].occupied = 0;
                    total_block[i][j].color = 0;
                    total_block[i][j].count = 0;
                }
            }
        }
    }
}