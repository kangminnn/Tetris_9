#include "Board.h"

void Board::init()
{
	memset(total_block, 0, sizeof(total_block)); // ���� ��� ���� ����
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

	for (j = 0; j < 14; j++)			//ȭ���� ���� ���� ���� 1�� ä���.
		total_block[20][j] = 1;

}
