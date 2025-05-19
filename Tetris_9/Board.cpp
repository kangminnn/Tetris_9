#include "Board.h"
#include "Constants.h"
#include "Renderer.h"
#include"Block.h"
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
            total_block[i][j].occupied = (j == 0 || j == 13) ? 1 : 0;
        }
    }

    // �ٴ� ����
    for (int j = 0; j < 14; ++j) {
        total_block[20][j].occupied = 1;
    }
}




int Board::check_full_line(int& level, int& score, int& lines)
{
	int i, j, k;
	for (i = 0; i < 20; i++)
	{
		for (j = 1; j < 13; j++)
		{
			if (total_block[i][j].occupied == 0)
				break;
		}
		if (j == 13)	//������ �� ä������
		{
			lines++;
			Renderer::show_total_block(level);
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
				total_block[0][j].occupied = 0;
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

bool Board::strikeCheck(unique_ptr<Block>& b)
{
	int i, j;
	int block_dat = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (((b->getX() + j) == 0) || ((b->getX() + j) == 13))
				block_dat = 1;
			else if (b->getY() + i >= 0)
				block_dat = total_block[b->getY() + i][b->getX() + j].occupied;


			if ((block_dat == 1) && (block[b->getShape()][b->getAngle()][i][j] == 1))																							//�������� ��ǥ�� ��������
			{
				return true;
			}
		}
	}
	return false;
}

void Board::mergeBlock(unique_ptr<Block>& b)
{

	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if ((b->getY() + i) < 0 || (b->getX() + j) < 0) {
				break;
			}
			//total_block[b.getY() + i][b.getX() + j].occupied |= block[b.getShape()][b.getAngle()][i][j];
			if (block[b->getShape()][b->getAngle()][i][j]==1) {
				total_block[b->getY() + i][b->getX() + j].occupied = 1;
				total_block[b->getY() + i][b->getX() + j].color = b->getColor();
			}
		}
	}
}

bool Board::rotateStrikeCheck(unique_ptr<Block>& b)
{
	int i, j;
	int block_dat = 0;

	int rotateAngle = (b->getAngle() + 1) % 4;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (((b->getX() + j) == 0) || ((b->getX() + j) == 13))
				block_dat = 1;
			else if (b->getY() + i >= 0)
				block_dat = total_block[b->getY() + i][b->getX() + j].occupied;


			if ((block_dat == 1) && (block[b->getShape()][rotateAngle][i][j] == 1))																							//�������� ��ǥ�� ��������
			{
				return true;
			}
		}
	}
	return false;
}

int Board::moveBlock(unique_ptr<Block>& b, int& level, int& score, int& lines)
{
	Renderer::eraseCurBlock(b);

	b->setY(b->getY() + 1);   //���� ��ĭ �Ʒ��� ����


	if (strikeCheck(b) == true)
	{
		if (b->getY() < 0)   //���ӿ���
		{
			return 1;
		}
		b->setY(b->getY() - 1);
		mergeBlock(b);
		check_full_line(level, score, lines);
		Renderer::show_total_block(level);

		for (int i = 1; i < 13; i++) { // 0�κа� 13�κ��� �׵θ��� �����ؾ���
			if (total_block[0][i].occupied == 1) {
				return 1;
			}
		}
		//*shape = *next_shape;
		//*next_shape = BlockFactory::make_new_block();
		//BlockFactory::block_start(*shape, angle, x, y);   //angle,x,y�� ��������
		//Renderer::show_next_block(*next_shape);

		
		return 2;
	}
	return 0;
}

