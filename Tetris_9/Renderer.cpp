#include "Renderer.h"
#include "Constants.h"
#include <conio.h>
#include <iomanip>


int Renderer::show_total_block(int& level)
{
	int i, j;
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (j == 0 || j == 13 || i == 20)		//레벨에 따라 외벽 색이 변함
			{
				switch (level) {
				case 0: SetColor(BLUE); break;
				case 1: SetColor(YELLOW); break;
				case 2: SetColor(SKY_BLUE); break;
				case 3: SetColor(RED); break;
				case 4: SetColor(VOILET); break;
				case 5: SetColor(GREEN); break;
				case 6: SetColor(GRAY); break;
				default: SetColor(WHITE); break;
				}
				gotoxy((j * 2) + ab_x, i + ab_y);
				if (total_block[i][j].occupied == 1)
				{
					cout << "□";
				}
				else {
					cout << "  ";
				}
			}
			else {
				SetColor(total_block[i][j].color);
				gotoxy((j * 2) + ab_x, i + ab_y);
				if (total_block[i][j].occupied == 1)
				{
					cout << "■";
				}
				else {
					cout << "  ";
				}
			}
		}
	}
	SetColor(BLACK);
	gotoxy(77, 23);
	return 0;
}

int Renderer::show_inner_block()
{
	int i, j;
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 14; j++)
		{
			
			SetColor(total_block[i][j].color);
			gotoxy((j * 2) + ab_x, i + ab_y);
			if (total_block[i][j].occupied == 1)
			{
				cout << "■";
			}
			else {
				cout << "  ";
			}
			
		}
	}
	SetColor(BLACK);
	gotoxy(77, 23);
	return 0;
}

int Renderer::show_gameover()
{
	SetColor(RED);
	gotoxy(0 + ab_x, 8 + ab_y);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(0 + ab_x, 9 + ab_y);
	cout << "┃*************************┃";
	gotoxy(0 + ab_x, 10 + ab_y);
	cout << "┃*       GAME OVER       *┃";
	gotoxy(0 + ab_x, 11 + ab_y);
	cout << "┃*************************┃";
	gotoxy(0 + ab_x, 12 + ab_y);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛";
	fflush(stdin);
	Sleep(1000);

	_getche();
	system("cls");

	return 0;
}

void Renderer::show_pause()
{
	SetColor(BLUE);
	gotoxy(2 + ab_x, 8 + ab_y);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(2 + ab_x, 9 + ab_y);
	cout << "┃*********************┃";
	gotoxy(2 + ab_x, 10 + ab_y);
	cout << "┃*       paused      *┃";
	gotoxy(2 + ab_x, 11 + ab_y);
	cout << "┃*********************┃";
	gotoxy(2 + ab_x, 12 + ab_y);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━┛";
}

void Renderer::erase_pause()
{
	gotoxy(2 + ab_x, 8 + ab_y);
	cout << string(23, ' ');
	gotoxy(2 + ab_x, 9 + ab_y);
	cout << string(23, ' ');
	gotoxy(2 + ab_x, 10 + ab_y);
	cout << string(23, ' ');
	gotoxy(2 + ab_x, 11 + ab_y);
	cout << string(23, ' ');
	gotoxy(2 + ab_x, 12 + ab_y);
	cout << string(23, ' ');
}


int Renderer::show_gamestat(int level, int score)
{
	static int printed_text = 0;
	SetColor(GRAY);
	if (printed_text == 0)
	{
		gotoxy(30 + ab_x, 10 + ab_y);
		cout << "STAGE";

		gotoxy(30 + ab_x, 13 + ab_y);
		cout << "SCORE";
	}
	gotoxy(36 + ab_x, 10 + ab_y);
	cout << level + 1;
	gotoxy(36 + ab_x, 13 + ab_y);
	cout << score;
	return 0;
}

int Renderer::show_logo()
{
	int i;

	gotoxy(13, 3);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	Sleep(100);
	gotoxy(13, 4);
	cout << "┃"; SetColor(RED); cout << "◆ ◆ ◆"; SetColor(BLUE); cout << "  ◆ ◆ ◆"; SetColor(GREEN); cout << "  ◆ ◆ ◆"; SetColor(YELLOW); cout << "   ◆ ◆ ◆";
	SetColor(VOILET); cout << "   ◆"; SetColor(SKY_BLUE); cout << "  ◆ ◆ ◆ "; SetColor(WHITE); cout << "┃";
	Sleep(100);
	gotoxy(13, 5);
	cout << "┃"; SetColor(RED); cout << "  ◆"; SetColor(BLUE); cout << "    ◆"; SetColor(GREEN); cout << "        ◆"; SetColor(YELLOW); cout << "     ◆   ◆";
	SetColor(VOILET); cout << "   ◆"; SetColor(SKY_BLUE); cout << "  ◆"; SetColor(WHITE); cout << "     ┃";
	Sleep(100);
	gotoxy(13, 6);
	cout << "┃"; SetColor(RED); cout << "  ◆"; SetColor(BLUE); cout << "    ◆ ◆ ◆"; SetColor(GREEN); cout << "    ◆"; SetColor(YELLOW); cout << "     ◆ ◆";
	SetColor(VOILET); cout << "     ◆"; SetColor(SKY_BLUE); cout << "    ◆"; SetColor(WHITE); cout << "   ┃";
	Sleep(100);
	gotoxy(13, 7);
	cout << "┃"; SetColor(RED); cout << "  ◆"; SetColor(BLUE); cout << "    ◆"; SetColor(GREEN); cout << "        ◆"; SetColor(YELLOW); cout << "     ◆  ◆";
	SetColor(VOILET); cout << "    ◆"; SetColor(SKY_BLUE); cout << "      ◆"; SetColor(WHITE); cout << " ┃";
	Sleep(100);
	gotoxy(13, 8);
	cout << "┃"; SetColor(RED); cout << "  ◆"; SetColor(BLUE); cout << "    ◆ ◆ ◆"; SetColor(GREEN); cout << "    ◆"; SetColor(YELLOW); cout << "     ◆   ◆";
	SetColor(VOILET); cout << "   ◆"; SetColor(SKY_BLUE); cout << "  ◆ ◆ ◆"; SetColor(WHITE); cout << " ┃";
	Sleep(100);
	gotoxy(13, 9);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	gotoxy(23, 20);
	cout << "Please Press Any Key~!";


	for (i = 0;; i++) {
		if (i % 40 == 0) {
			clear_block(6 - ab_x / 2, 14 - ab_y);
			clear_block(12 - ab_x / 2, 14 - ab_y);
			clear_block(19 - ab_x / 2, 14 - ab_y);
			clear_block(26 - ab_x / 2, 14 - ab_y);

			int color[7] = { 0,1,2,3,4,5,6 };
			int shape[7] = { 0,1,2,3,4,5,6 };
			// Fisher-Yates 셔플
			for (int i = 6; i > 0; i--) {
				int j = rand() % (i + 1);
				int temp = color[i];
				color[i] = color[j];
				color[j] = temp;
				j = rand() % (i + 1);
				temp = shape[i];
				shape[i] = shape[j];
				shape[j] = temp;
			}

			unique_ptr<Block> bl;
			bl = BlockFactory::makeLogoBlock(color[0], shape[0]);
			bl->setX(6 - ab_x / 2); bl->setY(14 - ab_y);
			showCurBlock(bl);
			bl = BlockFactory::makeLogoBlock(color[1], shape[1]);
			bl->setX(12 - ab_x / 2); bl->setY(14 - ab_y);
			showCurBlock(bl);
			bl = BlockFactory::makeLogoBlock(color[2], shape[2]);
			bl->setX(19 - ab_x / 2); bl->setY(14 - ab_y);
			showCurBlock(bl);
			bl = BlockFactory::makeLogoBlock(color[3], shape[3]);
			bl->setX(26 - ab_x / 2); bl->setY(14 - ab_y);
			showCurBlock(bl);
		}

		if (_kbhit()) break;
		Sleep(30);
	}

	_getche();
	system("cls");
	return 0;
}

void Renderer::showNextBlock(unique_ptr<Block>& b)
{
	int i, j;
	SetColor(GRAY);
	for (i = 1; i < 7; i++)
	{
		gotoxy(30 + ab_x, i + ab_y);
		for (j = 0; j < 6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				cout << "□ ";
			}
			else {
				cout << "  ";
			}

		}
	}
	b->setX(17);
	b->setY(2);
	showCurBlock(b);


	return ;
}

void Renderer::showCurBlock(unique_ptr<Block>& b)
{
	int i, j;
	SetColor(b->getColor());

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if ((j + b->getY() + ab_y) < 0)
				continue;

			if (block[b->getShape()][b->getAngle()][j][i] == 1)
			{
				gotoxy((i + b->getX()) * 2 + ab_x, j + b->getY() + ab_y);
				cout << "■";

			}
		}
	}
	SetColor(BLACK);
	gotoxy(77, 23);
	return ;
}

void Renderer::showSilhouetteBlock(unique_ptr<Block>& b, unique_ptr<Block>& b2)
{
	if (b->getY() - b2->getY() <= 4) return;
	SetColor(GRAY);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((j + b->getY()) < 0)
				continue;

			if (block[b->getShape()][b->getAngle()][j][i] == 1)
			{
				gotoxy((i + b->getX()) * 2 + ab_x, j + b->getY() + ab_y);
				cout << "□";

			}
		}
	}
	SetColor(BLACK);
	gotoxy(77, 23);
}

void Renderer::eraseCurBlock(unique_ptr<Block>& b)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (block[b->getShape()][b->getAngle()][j][i] == 1)
			{
				gotoxy((i + b->getX()) * 2 + ab_x, j + b->getY() + ab_y);
				cout << "  ";
				//break;

			}
		}
	}
	return ;
}

void Renderer::eraseSilhouetteBlock(unique_ptr<Block>& b, unique_ptr<Block>& b2)
{
	if (b->getY() - b2->getY() < 4) return;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (block[b->getShape()][b->getAngle()][j][i] == 1)
			{
				gotoxy((i + b->getX()) * 2 + ab_x, j + b->getY() + ab_y);
				cout << "  ";
				//break;
			}
		}
	}
	return;
}


