#include "BlueBlock.h"
#include "Constants.h"
#include "PurpleBlock.h"

BlueBlock::BlueBlock(int shape, int angle, int x, int y)
    :Block(shape, angle, x, y)
{
}

bool BlueBlock::check(const Board& board, int& level) const
{
    // �������� �۵��Ǵ��� Ȯ��
    if (stage_data[level].abilities.purpleBlockAbility) {
        PurpleBlock::update();
    }
    // ���� ������������ �Ķ��� ����� �ɷ��� ��Ȱ��ȭ�Ǿ� �ִٸ� false ��ȯ
    if (!stage_data[level].abilities.blueBlockAbility) {
        return false;
    }
    
    // ����� �� ���� Ȯ��
    for (int j = 0; j < 4; j++) {
        bool hasBlockInColumn = false;
        int lowestBlockY = -1;

        // ���� ����� �ش� ������ ���� �Ʒ��� �ִ� ��� ã��
        for (int i = 3; i >= 0; i--) {
            if (block[shape][angle][i][j] == 1) {
                hasBlockInColumn = true;
                lowestBlockY = y + i;
                break;
            }
        }

        if (hasBlockInColumn && lowestBlockY >= 0 && lowestBlockY < 19) {  // ��� üũ
            // �Ķ� ��� �ٷ� �Ʒ� ĭ Ȯ��
            if (total_block[lowestBlockY + 1][x + j].occupied == 1) {
                return true;  // �ɷ� �ߵ� ���� ����
            }
        }
    }
    return false;
}

void BlueBlock::active(Board& board)
{
    // ����� �� ���� Ȯ��
    for (int j = 0; j < 4; j++) {
        bool hasBlockInColumn = false;
        int lowestBlockY = -1;
        int highestBlockY = -1;

        // ���� ����� �ش� ������ ���� �Ʒ��� ���� ���� �ִ� ��� ã��
        for (int i = 3; i >= 0; i--) {
            if (block[shape][angle][i][j] == 1) {
                if (lowestBlockY == -1) {
                    lowestBlockY = y + i;
                }
                highestBlockY = y + i;
            }
        }

        if (total_block[lowestBlockY][x + j].color == VOILET) { return; }

        if (lowestBlockY >= 0 && lowestBlockY < 19) {  // ��� üũ
            // �Ķ� ��� �ٷ� �Ʒ� ĭ�� ����� �ְ�, �� �Ʒ��� ���� ���� �����
            if (total_block[lowestBlockY + 1][x + j].occupied == 1 &&
                lowestBlockY + 2 < 20) {  // ���� �ٴ� üũ
                // �Ʒ� ����� �� ĭ �Ʒ��� �̵�
                total_block[lowestBlockY + 2][x + j] = total_block[lowestBlockY + 1][x + j];
                total_block[lowestBlockY + 1][x + j].occupied = 0;
                total_block[lowestBlockY + 1][x + j].color = BLACK;
                total_block[lowestBlockY + 1][x + j].count = 0;

                // �Ķ� ����� �ش� ���� �� ĭ�� �Ʒ��� �̵�
                for (int i = lowestBlockY; i >= highestBlockY; i--) {
                    if (i >= 0 && i < 20) {  // ���� ���� üũ
                        total_block[i + 1][x + j] = total_block[i][x + j];
                        if (i == highestBlockY) {  // ���� ���� ��� ��ġ�� ����
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
