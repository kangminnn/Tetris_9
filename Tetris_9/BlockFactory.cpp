#include "BlockFactory.h"
#include "Constants.h"
#include "Renderer.h"
#include <cstdlib>
#include <ctime>
#include "RedBlock.h"
#include "BlueBlock.h"
#include "GreenBlock.h"
#include "YellowBlock.h"
#include "PurpleBlock.h"
#include "CyanBlock.h"
#include "WhiteBlock.h"



unique_ptr<Block> BlockFactory::makeBlock(int& level)
{
	int shape;
	int i;
	i = rand() % 100;
	if (i <= stage_data[level].stick_rate) {		//����� ����Ȯ�� ���
		shape = 0;							//����� ������� ����
		//return Block(shape, 0, 5, -4);
	}
	else shape = (rand() % 6) + 1;		//shape���� 1~6�� ���� ��
	//return Block(shape, 0, 5, -4);
    int r = rand() % 7; // 0 ~ 6 (7���� ��)
    switch (r)
    {
    case 0: return make_unique<RedBlock>(shape, 0, 5, -4);
    case 1: return make_unique<BlueBlock>(shape, 0, 5, -4);
    case 2: return make_unique<GreenBlock>(shape, 0, 5, -4);
    case 3: return make_unique<YellowBlock>(shape, 0, 5, -4);
    case 4: return make_unique<PurpleBlock>(shape, 0, 5, -4);
    case 5: return make_unique<CyanBlock>(shape, 0, 5, -4);
    case 6: return make_unique<WhiteBlock>(shape, 0, 5, -4);
    default: return make_unique<WhiteBlock>(shape, 0, 5, -4); // fallback
    }
}