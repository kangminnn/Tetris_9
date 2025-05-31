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
	int shape = rand() % 7;		//shape에는 0~6의 값이 들어감
    int r = rand() % 100 + 1; // 1 ~ 100 (확률 나누기 위함)
    if (stage_data[level].abilities.blueBlockAbility && r>0 && r<=20) return make_unique<BlueBlock>(shape, 0, 5, -4);
    if (stage_data[level].abilities.yellowBlockAbility && r>20 && r<=30) return make_unique<YellowBlock>(shape, 0, 5, -4);
    if (stage_data[level].abilities.cyanBlockAbility && r > 30 && r <= 40) return make_unique<CyanBlock>(shape, 0, 5, -4);
    if (stage_data[level].abilities.redBlockAbility && r > 40 && r <= 50) return make_unique<RedBlock>(shape, 0, 5, -4);
    if (stage_data[level].abilities.purpleBlockAbility && r > 50 && r <= 60) return make_unique<PurpleBlock>(shape, 0, 5, -4);
    if (stage_data[level].abilities.greenBlockAbility && r > 60 && r <= 67) return make_unique<GreenBlock>(shape, 0, 5, -4);
    else return make_unique<WhiteBlock>(shape, 0, 5, -4);
}

unique_ptr<Block> BlockFactory::makeLogoBlock(int& color, int& shape)
{
    if (color == 0) return make_unique<BlueBlock>(shape, 0, 5, -4);
    if (color == 1) return make_unique<YellowBlock>(shape, 0, 5, -4);
    if (color == 2) return make_unique<CyanBlock>(shape, 0, 5, -4);
    if (color == 3) return make_unique<RedBlock>(shape, 0, 5, -4);
    if (color == 4) return make_unique<PurpleBlock>(shape, 0, 5, -4);
    if (color == 5) return make_unique<GreenBlock>(shape, 0, 5, -4);
    else return make_unique<WhiteBlock>(shape, 0, 5, -4);
}