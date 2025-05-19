#include "Renderer.h"
#include "Constants.h"
#include <conio.h>
#include <iomanip>


int Renderer::show_total_block(const Board& board)
{
	int i, j;
	SetColor(DARK_GRAY);
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (j == 0 || j == 13 || i == 20)		//레벨에 따라 외벽 색이 변함
			{
				SetColor((level % 6) + 1);

			}
			else {
				SetColor(DARK_GRAY);
			}
			gotoxy((j * 2) + ab_x, i + ab_y);
			if (total_block[i][j] == 1)
			{
				cout << "■";
			}
			else {
				cout <<  "  ";
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
	gotoxy(5, 8);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(5, 9);
	cout << "┃*************************┃";
	gotoxy(5, 10);
	cout << "┃*       GAME OVER       *┃";
	gotoxy(5, 11);
	cout << "┃*************************┃";
	gotoxy(5, 12);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━┛";
	fflush(stdin);
	Sleep(1000);

	_getche();
	system("cls");

	return 0;
}

int Renderer::show_gamestat(int level, int score, int lines)
{
	static int printed_text = 0;
	SetColor(GRAY);
	if (printed_text == 0)
	{
		gotoxy(30, 10);
		cout << "STAGE";

		gotoxy(30, 13);
		cout << "SCORE";

		gotoxy(30, 16);
		cout << "LINES";


	}
	gotoxy(36, 10);
	cout << level + 1;
	gotoxy(36, 13);
	cout << score;
	gotoxy(36, 16);
	cout << stage_data[level].clear_line - lines;
	return 0;
}

int Renderer::show_logo()
{
	int i;

	gotoxy(13, 3);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	Sleep(100);
	gotoxy(13, 4);
	cout << "┃◆ ◆ ◆  ◆ ◆ ◆  ◆ ◆ ◆   ◆ ◆ ◆   ◆  ◆ ◆ ◆ ┃";
	Sleep(100);
	gotoxy(13, 5);
	cout << "┃  ◆    ◆        ◆     ◆   ◆   ◆  ◆     ┃";
	Sleep(100);
	gotoxy(13, 6);
	cout << "┃  ◆    ◆ ◆ ◆    ◆     ◆ ◆     ◆    ◆   ┃";
	Sleep(100);
	gotoxy(13, 7);
	cout << "┃  ◆    ◆        ◆     ◆  ◆    ◆      ◆ ┃";
	Sleep(100);
	gotoxy(13, 8);
	cout << "┃  ◆    ◆ ◆ ◆    ◆     ◆   ◆   ◆  ◆ ◆ ◆ ┃";
	Sleep(100);
	gotoxy(13, 9);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


	gotoxy(23, 20);
	cout << "Please Press Any Key~!";


	for (i = 0;; i++) {
		if (i % 40 == 0) {
			clear_block(6, 14);
			clear_block(12, 14);
			clear_block(19, 14);
			clear_block(26, 14);

			//show_cur_block(rand() % 7, rand() % 4, 6, 14);
			//show_cur_block(rand() % 7, rand() % 4, 12, 14);
			//show_cur_block(rand() % 7, rand() % 4, 19, 14);
			//show_cur_block(rand() % 7, rand() % 4, 26, 14);

			showCurBlock(Block(rand() % 7, rand() % 4, 6, 14));
			showCurBlock(Block(rand() % 7, rand() % 4, 12, 14));
			showCurBlock(Block(rand() % 7, rand() % 4, 19, 14));
			showCurBlock(Block(rand() % 7, rand() % 4, 26, 14));
		}

		if (_kbhit()) break;
		Sleep(30);
	}

	_getche();
	system("cls");
	return 0;
}

void Renderer::showNextBlock(Block b)
{
	int i, j;
	SetColor((level + 1) % 6 + 1);
	for (i = 1; i < 7; i++)
	{
		gotoxy(30, i);
		for (j = 0; j < 6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				cout << "■ ";
			}
			else {
				cout << "  ";
			}

		}
	}
	b.setX(17);
	b.setY(2);
	showCurBlock(b);


	return ;
}

void Renderer::showCurBlock(Block b)
{
	int i, j;

	switch (b.getShape())
	{
	case 0:
		SetColor(RED);
		break;
	case 1:
		SetColor(BLUE);
		break;
	case 2:
		SetColor(SKY_BLUE);
		break;
	case 3:
		SetColor(WHITE);
		break;
	case 4:
		SetColor(YELLOW);
		break;
	case 5:
		SetColor(VOILET);
		break;
	case 6:
		SetColor(GREEN);
		break;
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if ((j + b.getY()) < 0)
				continue;

			if (block[b.getShape()][b.getAngle()][j][i] == 1)
			{
				gotoxy((i + b.getX()) * 2 + ab_x, j + b.getY() + ab_y);
				cout << "■";

			}
		}
	}
	SetColor(BLACK);
	gotoxy(77, 23);
	return ;
}

void Renderer::eraseCurBlock(Block b)
{

	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (block[b.getShape()][b.getAngle()][j][i] == 1)
			{
				gotoxy((i + b.getX()) * 2 + ab_x, j + b.getY() + ab_y);
				cout << "  ";
				//break;

			}
		}
	}
	return ;
}

