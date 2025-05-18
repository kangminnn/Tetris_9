#include "BlockFactory.h"
#include "Constants.h"
#include "Renderer.h"
#include <cstdlib>
#include <ctime>

int BlockFactory::make_new_block()
{
	int shape;
	int i;
	i = rand() % 100;
	if (i <= stage_data[level].stick_rate)		//����� ����Ȯ�� ���
		return 0;							//����� ������� ����

	shape = (rand() % 6) + 1;		//shape���� 1~6�� ���� ��
	Renderer::show_next_block(shape);
	return shape;
}

int BlockFactory::block_start(int shape, int* angle, int* x, int* y)
{
	*x = 5;
	*y = -3;
	*angle = 0;

	return 0;
}
