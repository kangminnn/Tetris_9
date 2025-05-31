#include "Game.h"
#include "Constants.h"
#include "Renderer.h"
#include "BlockFactory.h"
#include "InputHandler.h"
#include "StoryManager.h"
#include <conio.h>


Game::Game()
	:level(0), score(0), isGameOver(0), board(), curBlock(), nextBlock()
{
}


void Game::run()
{
	hideCursor();
	int i;
	char keytemp;
	Renderer::show_logo();
	StoryManager::showIntro();
	board.init();
	while (1)
	{
		showCursor();
		InputHandler::input_data(level);
		hideCursor();
		StoryManager::showLevelUp(level);
		initStageData();
		Renderer::show_total_block(level);
		curBlock = BlockFactory::makeBlock(level);
		nextBlock = BlockFactory::makeBlock(level);
		unique_ptr<Block> silhouetteBlock = make_unique<Block>(*curBlock);
		Renderer::showNextBlock(nextBlock);
		Renderer::show_gamestat(level, score);
		Renderer::showWizard(level);
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
						if (board.rotateStrikeCheck(curBlock) == false)
						{
							Renderer::eraseCurBlock(curBlock);
							curBlock->setAngle((curBlock->getAngle() + 1) % 4);
							Renderer::showCurBlock(curBlock);
						}
						else {
							while(!board.tryRotate(curBlock));
						}
						break;
					case KEY_LEFT:		//�������� �̵�
						if (curBlock->getX() > 1)
						{
							Renderer::eraseCurBlock(curBlock);
							curBlock->setX(curBlock->getX() -1);
							if (board.strikeCheck(curBlock) == true)
								curBlock->setX(curBlock->getX() + 1);

							Renderer::showCurBlock(curBlock);
						}
						break;
					case KEY_RIGHT:		//���������� �̵�
						if (curBlock->getX() < 14)
						{
							Renderer::eraseCurBlock(curBlock);
							curBlock->setX(curBlock->getX() + 1);
							if (board.strikeCheck(curBlock) == true)
								curBlock->setX(curBlock->getX() - 1);

							Renderer::showCurBlock(curBlock);
						}
						break;
					case KEY_DOWN:		//�Ʒ��� �̵�
						isGameOver = board.moveBlock(curBlock, level, score);
						if (isGameOver == 2) {
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
				if (keytemp == 32)	//�����̽��ٸ� ��������
				{
					while (isGameOver == 0)
					{
						isGameOver = board.moveBlock(curBlock, level, score);
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
				if (keytemp == 27) {//esc��������
					// ��� ���� (�ƹ� Ű �Էµ� ������)
					Renderer::show_pause();
					_getch();
					Renderer::erase_pause();
				}
			}

			if (i % stage_data[level].speed == 0)
			{
				isGameOver = board.moveBlock(curBlock, level, score);
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

			if (stage_data[level].score <= score)	//Ŭ���� ��������
			{
				if (level == 6) {
					StoryManager::showEnding();
					break;
				}
				else {
					level++;
					StoryManager::showLevelUp(level);
					Renderer::showWizard(level);
					score = 0;
				}
			}
			if (isGameOver == 1)
			{
				Renderer::show_gameover();
				SetColor(GRAY);
				break;
			}

			// �ܻ� ���̱�
			
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
	score = 0;
	isGameOver = 0;
}
