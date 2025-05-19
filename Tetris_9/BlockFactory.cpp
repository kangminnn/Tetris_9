#include "BlockFactory.h"
#include "Constants.h"
#include "Renderer.h"
#include <cstdlib>
#include <ctime>

Block BlockFactory::makeBlock()
{
	int shape;
	int i;
	i = rand() % 100;
	if (i <= stage_data[level].stick_rate) {		//����� ����Ȯ�� ���
		shape = 0;							//����� ������� ����
		return Block(shape, 0, 5, -4);
	}
	shape = (rand() % 6) + 1;		//shape���� 1~6�� ���� ��
	return Block(shape, 0, 5, -4);
}

