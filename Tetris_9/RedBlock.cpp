#include "RedBlock.h"
#include "PurpleBlock.h"
#include "Renderer.h"
#include <queue>

RedBlock::RedBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool RedBlock::check(const Board& board, int& level) const
{

    // �������� �۵��Ǵ��� Ȯ��
    if (stage_data[level].abilities.purpleBlockAbility) {
        PurpleBlock::update();
    }

    // ���� ������������ ������ ����� �ɷ��� ��Ȱ��ȭ�Ǿ� �ִٸ� false ��ȯ
    if (!stage_data[level].abilities.redBlockAbility) {
        return false;
    }


    //�����¿� ����
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    //�湮 red�� �� ���� �ȵ�
    bool visited[21][14] = { false };

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 14; j++) {
            if (total_block[i][j].color == RED && !visited[i][j]) {
                vector<pair<int, int>> cluster;
                queue<pair<int, int>> q;

                visited[i][j] = true;
                q.push({ i, j });
                cluster.push_back({ i, j });

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < 21 && ny >= 0 && ny < 14 &&
                            total_block[nx][ny].color == RED && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({ nx, ny });
                            cluster.push_back({ nx, ny });
                        }
                    }
                }

                if (cluster.size() >= MAX_RED) {
                    delete_red.insert(delete_red.end(), cluster.begin(), cluster.end());
                    return true;
                }
            }
        }
    }
    return false;
}

void RedBlock::active(Board& board)
{
    //���ͳ� ������ ����?
    //��ġ �����ϰ� ����ͼ� �����
   //����� ���� �� ���� ����
    for (pair<int, int> del : delete_red) {
        total_block[del.first][del.second].color = DARK_RED;
        //total_block[del.first][del.second].occupied = 0;
    }
    Renderer::show_inner_block();
    Sleep(150);
    for (pair<int, int> del : delete_red) {
        total_block[del.first][del.second].color = 0;
        total_block[del.first][del.second].occupied = 0;
    }
    delete_red.clear();
}
