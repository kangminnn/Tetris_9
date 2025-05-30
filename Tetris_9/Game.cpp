#include "Game.h"
#include "Constants.h"
#include "Renderer.h"
#include "BlockFactory.h"
#include "InputHandler.h"
#include <conio.h>


Game::Game()
	:level(0), lines(0), score(0), isGameOver(0), board(), curBlock(), nextBlock()
{
}


void Game::run()
{
	hideCursor();
	int i;
	char keytemp;
	Renderer::show_logo();
	board.init();
	while (1)
	{
		showCursor();
		InputHandler::input_data(level);
		hideCursor();
		initStageData();
		Renderer::show_total_block(level);
		//block_shape = BlockFactory::make_new_block();
		//next_block_shape = BlockFactory::make_new_block();
		curBlock = BlockFactory::makeBlock(level);
		nextBlock = BlockFactory::makeBlock(level);
		unique_ptr<Block> silhouetteBlock = make_unique<Block>(*curBlock);
		Renderer::showNextBlock(nextBlock);
		//BlockFactory::block_start(block_shape, &block_angle, &block_x, &block_y);
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
					case KEY_UP:		//회전하기

						/*if (board.strike_check(block_shape, (block_angle + 1) % 4, block_x, block_y) == 0)
						{
							Renderer::erase_cur_block(block_shape, block_angle, block_x, block_y);
							block_angle = (block_angle + 1) % 4;
							Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);
						}*/
						if (board.rotateStrikeCheck(curBlock) == false)
						{
							Renderer::eraseCurBlock(curBlock);
							curBlock->setAngle((curBlock->getAngle() + 1) % 4);
							Renderer::showCurBlock(curBlock);
						}
						break;
					case KEY_LEFT:		//왼쪽으로 이동
						//if (block_x > 1)
						//{
						//	Renderer::erase_cur_block(block_shape, block_angle, block_x, block_y);
						//	block_x--;
						//	if (board.strike_check(block_shape, block_angle, block_x, block_y) == 1)
						//		block_x++;

						//	Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);
						//}
						if (curBlock->getX() > 1)
						{
							Renderer::eraseCurBlock(curBlock);
							curBlock->setX(curBlock->getX() -1);
							if (board.strikeCheck(curBlock) == true)
								curBlock->setX(curBlock->getX() + 1);

							Renderer::showCurBlock(curBlock);
						}
						break;
					case KEY_RIGHT:		//오른쪽으로 이동

						//if (block_x < 14)
						//{
						//	Renderer::erase_cur_block(block_shape, block_angle, block_x, block_y);
						//	block_x++;
						//	if (board.strike_check(block_shape, block_angle, block_x, block_y) == 1)
						//		block_x--;
						//	Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);
						//}
						if (curBlock->getX() < 14)
						{
							Renderer::eraseCurBlock(curBlock);
							curBlock->setX(curBlock->getX() + 1);
							if (board.strikeCheck(curBlock) == true)
								curBlock->setX(curBlock->getX() - 1);

							Renderer::showCurBlock(curBlock);
						}
						break;
					case KEY_DOWN:		//아래로 이동
						//isGameOver = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
						//Renderer::showCurBlock(curBlock);

						isGameOver = board.moveBlock(curBlock, level, score, lines);
						if (isGameOver == 2) {
							//*shape = *next_shape;
							//*next_shape = BlockFactory::make_new_block();
							//BlockFactory::block_start(*shape, angle, x, y);   //angle,x,y는 포인터임
							//Renderer::show_next_block(*next_shape);

							curBlock = move(nextBlock);
							curBlock->setX(5);
							curBlock->setY(-4);
							nextBlock = BlockFactory::makeBlock(level);
							silhouetteBlock = nullptr;
							Renderer::showNextBlock(nextBlock);
						}
						Renderer::showCurBlock(curBlock);
						break;
					}
				}
				if (keytemp == 32)	//스페이스바를 눌렀을때
				{
					//while (isGameOver == 0)
					//{
					//	isGameOver = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
					//}
					//Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);

					while (isGameOver == 0)
					{
						isGameOver = board.moveBlock(curBlock, level, score, lines);
						if (isGameOver == 2) {
							curBlock = move(nextBlock);
							curBlock->setX(5);
							curBlock->setY(-4);
							nextBlock = BlockFactory::makeBlock(level);
							silhouetteBlock = nullptr;
							Renderer::showNextBlock(nextBlock);
						}
						Renderer::showCurBlock(curBlock);
					}
					Renderer::showCurBlock(curBlock);
				}
				if (keytemp == 27) {//esc눌럿을때
					while (!_kbhit()) {
						// 대기 루프 (아무 키 입력될 때까지)
						Renderer::show_pause();
						Sleep(100);
					}
					Renderer::erase_pause();
				}
			}

			if (i % stage_data[level].speed == 0)
			{
		/*		isGameOver = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);

				Renderer::show_cur_block(block_shape, block_angle, block_x, block_y);*/
				isGameOver = board.moveBlock(curBlock, level, score, lines);
				if (isGameOver == 2) {
					curBlock = move(nextBlock);
					curBlock->setX(5);
					curBlock->setY(-4);
					nextBlock = BlockFactory::makeBlock(level);
					silhouetteBlock = nullptr;
					Renderer::showNextBlock(nextBlock);
				}
				Renderer::showCurBlock(curBlock);

			}

			if (stage_data[level].clear_line <= lines)	//클리어 스테이지
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

			// 잔상 보이기
			
			if (silhouetteBlock != nullptr) {
				Renderer::eraseSilhouetteBlock(silhouetteBlock, curBlock);
			}
			silhouetteBlock = make_unique<Block>(*curBlock);
			while (!board.strikeCheck(silhouetteBlock))
			{
				silhouetteBlock->setY(silhouetteBlock->getY() + 1);
			}
			silhouetteBlock->setY(silhouetteBlock->getY() - 1);

			SetColor(GRAY);
			Renderer::showSilhouetteBlock(silhouetteBlock, curBlock);

			gotoxy(77, 23);
			Sleep(15);
			gotoxy(77, 23);
		}
		board.init();
		gameInit();
	}
	return;
}

void Game::gameInit()
{
	level = 0;
	lines = 0;
	score = 0;
	isGameOver = 0;
}
