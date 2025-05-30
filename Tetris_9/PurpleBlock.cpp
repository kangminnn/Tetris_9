#include "PurpleBlock.h"
#include <queue>

PurpleBlock::PurpleBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool PurpleBlock::check(const Board& board, int& level) const
{
    // ���� ������������ �ϴû� ����� �ɷ��� ��Ȱ��ȭ�Ǿ� �ִٸ� false ��ȯ
    if (!stage_data[level].abilities.purpleBlockAbility) {
        return false;
    }
    return true;
}

void PurpleBlock::active(Board& board)
{
    update();
}

void PurpleBlock::update()
{
    queue<pair<int, int>> q;

    //�ʱ� purple�� ��ġ���� ť�� ����
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 14; ++j) {
            if (total_block[i][j].color == VOILET) {
                q.push({ i, j });
            }
        }
    }

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && nx < 21 && ny >= 0 && ny < 14) {
                if (total_block[nx][ny].color == RED || total_block[nx][ny].color == BLUE) {
                    total_block[nx][ny].color = VOILET;
                    q.push({ nx, ny });
                }
            }
        }
    }
}
