#include "Board.h"
#include "Constants.h"
#include "Renderer.h"
#include <cstdlib>   // std::srand, std::rand
#include <ctime>     // std::time
#include <array>     // std::array
#include <algorithm> // std::fill
#include <cstring>   // std::memset


void Board::init() {
    // ��ü ��� �迭�� 0���� �ʱ�ȭ
    std::memset(total_block, 0, sizeof(total_block));

    // �õ� ���� (�ߺ� ȣ�� �����ϰ� �ʹٸ� Ŭ���� �ܺο��� �� ���� ���� ��õ)
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // �� ����
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 14; ++j) {
            total_block[i][j] = (j == 0 || j == 13) ? 1 : 0;
        }
    }

    // �ٴ� ����
    for (int j = 0; j < 14; ++j) {
        total_block[20][j] = 1;
    }
}

bool Board::strike_check(int shape, int angle, int x, int y) const
{
	int i, j;
	int block_dat = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (((x + j) == 0) || ((x + j) == 13))
				block_dat = 1;
			else if (y + i >= 0)
				block_dat = total_block[y + i][x + j];


			if ((block_dat == 1) && (block[shape][angle][i][j] == 1))																							//�������� ��ǥ�� ��������
			{
				return true;
			}
		}
	}
	return false;
}

void Board::merge_block(int shape, int angle, int x, int y)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if ((y + i) < 0 || (x + j) < 0) {
				break;
			}
			total_block[y + i][x + j] |= block[shape][angle][i][j];
		}
	}
	check_full_line();
	Renderer::show_total_block(*this);
}

int Board::check_full_line()
{
	int i, j, k;
	for (i = 0; i < 20; i++)
	{
		for (j = 1; j < 13; j++)
		{
			if (total_block[i][j] == 0)
				break;
		}
		if (j == 13)	//������ �� ä������
		{
			lines++;
			Renderer::show_total_block(*this);
			SetColor(BLUE);
			gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++)
			{
				cout << "��";
				Sleep(10);
			}
			gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++)
			{
				cout << "  ";
				Sleep(10);
			}

			for (k = i; k > 0; k--)
			{
				for (j = 1; j < 13; j++)
					total_block[k][j] = total_block[k - 1][j];
			}
			for (j = 1; j < 13; j++)
				total_block[0][j] = 0;
			score += 100 + (level * 10) + (rand() % 10);

			if (stage_data[level].clear_line <= lines)	//Ŭ���� ��������
			{
				if (level == 9) {
					lines = 0;
				}
				else {
					level++;
					lines = 0;
				}
			}
			Renderer::show_gamestat(level, score, lines);
		}
	}
	return 0;
}
