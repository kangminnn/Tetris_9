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
	if (i <= stage_data[level].stick_rate)		//막대기 나올확률 계산
		return 0;							//막대기 모양으로 리턴

	shape = (rand() % 6) + 1;		//shape에는 1~6의 값이 들어감
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
