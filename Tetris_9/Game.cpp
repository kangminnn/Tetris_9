#include "Game.h"
#include "Constants.h"
#include "Renderer.h"
#include "BlockFactory.h"
#include "InputHandler.h"
#include <conio.h>


Game::Game()
	:level(0), lines(0), score(0), isGameOver(0), board(), currentBlock(), nextBlock()
{
}

void Game::run()
{
	int i;
	char keytemp;
	Renderer::show_logo();
	board.init();
	while (1)
	{
		isGameOver = 0;
		InputHandler::input_data();
		initStageData();
		Renderer::show_total_block(board);
		block_shape = BlockFactory::make_new_block();
		next_block_shape = BlockFactory::make_new_block();
		Renderer::show_next_block(next_block_shape);
		BlockFactory::block_start(block_shape, &block_angle, &block_x, &block_y);
		Renderer::show_gamestat(level, score, lines);
		for (i = 1; 1; i++)
		{
			if (_kbhit())
			{
				keytemp = _getche();
				if (keytemp == EXT_KEY)
				{
					keytemp = _getche();
					switch (keytemp)
					{
					case KEY_UP:		//ȸ���ϱ�

						if (board.strike_check(block_shape, (block_angle + 1) % 4, block_x, block_y) == 0)
						{
							Renderer::erase_cur_block(block_shape, block_angle, block_x, block_y);
							block_angle = (block_angle + 1) % 4;
							Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);
						}
						break;
					case KEY_LEFT:		//�������� �̵�
						if (block_x > 1)
						{
							Renderer::erase_cur_block(block_shape, block_angle, block_x, block_y);
							block_x--;
							if (board.strike_check(block_shape, block_angle, block_x, block_y) == 1)
								block_x++;

							Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);
						}
						break;
					case KEY_RIGHT:		//���������� �̵�

						if (block_x < 14)
						{
							Renderer::erase_cur_block(block_shape, block_angle, block_x, block_y);
							block_x++;
							if (board.strike_check(block_shape, block_angle, block_x, block_y) == 1)
								block_x--;
							Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);
						}
						break;
					case KEY_DOWN:		//�Ʒ��� �̵�
						isGameOver = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
						Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);
						break;
					}
				}
				if (keytemp == 32)	//�����̽��ٸ� ��������
				{
					while (isGameOver == 0)
					{
						isGameOver = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
					}
					Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);
				}
			}
			if (i % stage_data[level].speed == 0)
			{
				isGameOver = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);

				Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);
			}

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
			if (isGameOver == 1)
			{
				Renderer::show_gameover();
				SetColor(GRAY);
				break;
			}

			gotoxy(77, 23);
			Sleep(15);
			gotoxy(77, 23);
		}
		board.init();
	}
	return;
}

int Game::move_block(int* shape, int* angle, int* x, int* y, int* next_shape)
{
	Renderer::erase_cur_block(*shape, *angle, *x, *y);

	(*y)++;   //���� ��ĭ �Ʒ��� ����


	if (board.strike_check(*shape, *angle, *x, *y) == 1)
	{
		if (*y < 0)   //���ӿ���
		{
			return 1;
		}
		(*y)--;
		board.merge_block(*shape, *angle, *x, *y);

		for (int i = 1; i < 13; i++) { // 0�κа� 13�κ��� �׵θ��� �����ؾ���
			if (total_block[0][i] == 1) {
				return 1;
			}
		}
		*shape = *next_shape;
		*next_shape = BlockFactory::make_new_block();
		BlockFactory::block_start(*shape, angle, x, y);   //angle,x,y�� ��������
		Renderer::show_next_block(*next_shape);
		return 2;
	}
	return 0;
}
