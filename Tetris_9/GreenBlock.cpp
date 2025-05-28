#include "GreenBlock.h"
#include <set>
#include <utility>
#include <iostream>
#include "Constants.h"
using namespace std;

GreenBlock::GreenBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool GreenBlock::check(const Board& board) const
{
    return true;
}

void GreenBlock::active(Board& board)
{
    int shape = getShape();
    int angle = getAngle();
    int baseX = getX();
    int baseY = getY();

    // 복제된 좌표 중복 방지용 2차원 배열
    bool visited[21][14] = {}; // 필드 크기: 0~20, 0~13 (벽 제외, 실사용 1~12)

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (block[shape][angle][i][j] == 1) {
                int x = baseX + j;
                int y = baseY + i;

                // 위로 한 칸씩 탐색해서 가장 먼저 만나는 빈칸에 복제
                int spawnY = y - 1;
                while (spawnY >= 0 && total_block[spawnY][x].occupied == 1)
                    spawnY--;

                // spawnY가 0 이상이고, 복제하지 않은 좌표면 복제
                if (spawnY >= 0 && !visited[spawnY][x]) {
                    unique_ptr<Block> clone = make_unique<GreenBlock>(shape, angle, baseX, spawnY - i);
                    clone->setX(baseX);
                    clone->setY(spawnY - i);
                    board.mergeBlock(clone);
                    visited[spawnY][x] = true;
                }
            }
        }
    }
    cout << "[Green] 복제 완료" << endl;
}
