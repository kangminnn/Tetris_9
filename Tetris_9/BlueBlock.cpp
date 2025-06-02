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

    // ����� ���� �Ʒ� �κ��� �ٸ� ��ϰ� �����ϴ��� Ȯ��
    for (int j = 0; j < 4; j++) {
        bool hasBlock = false;
        int lowestY = -1;

        // ���� ������ ���� �Ʒ� ��� ã��
        for (int i = 3; i >= 0; i--) {
            if (block[shape][angle][i][j] == 1) {
                hasBlock = true;
                lowestY = y + i;
                break;
            }
        }

        if (hasBlock && lowestY >= 0 && lowestY < 19) {
            // �Ķ� ��� �ٷ� �Ʒ��� �ٸ� ����� �ְ�
            if (total_block[lowestY + 1][x + j].occupied == 1) {
                // �� �Ʒ��� �� ������ �ִ��� Ȯ��
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
    // �� ������ ó��
    for (int j = 0; j < 4; j++) {
        // ���� ������ �Ķ� ��ϵ��� ��ġ ã�� (����������)
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

        // ���� �Ʒ��� �ִ� ��� ã��
        int lowestY = blockPositions.back();
        if (lowestY >= 19) continue;

        // �Ʒ� ��ϰ� ���� Ȯ��
        if (total_block[lowestY + 1][x + j].occupied == 1) {
            // ��� �� ���� ã��
            vector<int> emptySpaces;
            bool foundOccupied = false;

            // ������ ��� �ٷ� �Ʒ����� �˻�
            for (int checkY = lowestY + 2; checkY < 20; checkY++) {
                if (!foundOccupied && total_block[checkY][x + j].occupied == 0) {
                    emptySpaces.push_back(checkY);
                }
                else if (total_block[checkY][x + j].occupied == 1) {
                    foundOccupied = true;  // ����� ����
                }
                else if (foundOccupied && total_block[checkY][x + j].occupied == 0) {
                    emptySpaces.push_back(checkY);  // ���� �� ���� ����
                    foundOccupied = false;
                }
            }

            if (!emptySpaces.empty()) {
                // �̵� �� ���� ���� ���� ����
                vector<pair<int, bool>> columnState;  // {y��ǥ, �̵��ߴ��� ����}
                for (int pos : blockPositions) {
                    columnState.push_back({ pos, false });
                }

                // �Ķ� ��ϵ��� �Ʒ������� �̵� (���� �Ʒ� �ִ� ��Ϻ���)
                for (int i = blockPositions.size() - 1; i >= 0; i--) {
                    int currentY = blockPositions[i];

                    // ���� ��� �Ʒ��� ���� �� �� ���� ã��
                    int targetY = -1;
                    for (int k = emptySpaces.size() - 1; k >= 0; k--) {
                        if (emptySpaces[k] > currentY) {
                            targetY = emptySpaces[k];
                            emptySpaces.pop_back();  // ����� �� ���� ����
                            break;
                        }
                    }

                    if (targetY != -1) {
                        // ���� ��ġ ����
                        total_block[currentY][x + j].occupied = 0;
                        total_block[currentY][x + j].color = 0;
                        total_block[currentY][x + j].count = 0;

                        // �� ��ġ�� ��� ��ġ
                        total_block[targetY][x + j].occupied = 1;
                        total_block[targetY][x + j].color = BLUE;
                        total_block[targetY][x + j].count = 0;

                        // �̵� ǥ��
                        columnState[i].second = true;
                    }
                }

                // �̵����� ���� ��ϵ��� �Ʒ��� �̵�
                int maxMoveDown = 0;  // �ִ� �̵� ���� �Ÿ�
                for (int i = columnState.size() - 1; i >= 0; i--) {
                    if (columnState[i].second) {  // �̵��� ��� �߰�
                        maxMoveDown++;  // ���� ��ϵ��� ������ �� �ִ� �Ÿ� ����
                    }
                    else if (maxMoveDown > 0) {  // �̵����� ���� ����� �Ʒ��� �̵�
                        int fromY = columnState[i].first;
                        int toY = fromY + maxMoveDown;

                        if (toY < 20) {
                            // ���� ��ġ ����
                            total_block[fromY][x + j].occupied = 0;
                            total_block[fromY][x + j].color = 0;
                            total_block[fromY][x + j].count = 0;

                            // �� ��ġ�� ��� ��ġ
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