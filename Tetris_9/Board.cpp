#include "Board.h"

void Board::init()
{
	memset(total_block, 0, sizeof(total_block)); // 쌓인 블록 전부 제거
	int i, j;

	srand((unsigned)time(NULL));


	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				total_block[i][j] = 1;
			}
			else {
				total_block[i][j] = 0;
			}
		}
	}

	for (j = 0; j < 14; j++)			//화면의 제일 밑의 줄은 1로 채운다.
		total_block[20][j] = 1;

}
