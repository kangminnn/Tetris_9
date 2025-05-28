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

    // ������ ��ǥ �ߺ� ������ 2���� �迭
    bool visited[21][14] = {}; // �ʵ� ũ��: 0~20, 0~13 (�� ����, �ǻ�� 1~12)

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (block[shape][angle][i][j] == 1) {
                int x = baseX + j;
                int y = baseY + i;

                // ���� �� ĭ�� Ž���ؼ� ���� ���� ������ ��ĭ�� ����
                int spawnY = y - 1;
                while (spawnY >= 0 && total_block[spawnY][x].occupied == 1)
                    spawnY--;

                // spawnY�� 0 �̻��̰�, �������� ���� ��ǥ�� ����
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
    cout << "[Green] ���� �Ϸ�" << endl;
}
