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
	if (i <= stage_data[level].stick_rate) {		//막대기 나올확률 계산
		shape = 0;							//막대기 모양으로 리턴
		return Block(shape, 0, 5, -4);
	}
	shape = (rand() % 6) + 1;		//shape에는 1~6의 값이 들어감
	return Block(shape, 0, 5, -4);
}

