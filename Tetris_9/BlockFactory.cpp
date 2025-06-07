#include "BlockFactory.h"
#include <cstdlib>
#include "RedBlock.h"
#include "BlueBlock.h"
#include "GreenBlock.h"
#include "YellowBlock.h"
#include "PurpleBlock.h"
#include "CyanBlock.h"
#include "WhiteBlock.h"

int blockRate[8][6] = {
    {25, 0, 0, 0, 0, 0},
    {20, 45, 0, 0, 0, 0},
    {20, 45, 60, 0, 0, 0},
    {20, 35, 45, 65, 0, 0},
    {20, 35, 45, 65, 75, 0},
    {20, 35, 45, 65, 75, 80},
    {20, 40, 50, 70, 80, 87},
    {23, 46, 56, 70, 80, 85}
};

unique_ptr<Block> BlockFactory::makeBlock(int& level)
{
	int shape = rand() % 7;		//shape에는 0~6의 값이 들어감
    int r = rand() % 100 + 1; // 1 ~ 100 (확률 나누기 위함)
    if (r > 0 && r <= blockRate[level][0]) return make_unique<BlueBlock>(shape, 0, 5, -4);
    if (r> blockRate[level][0] && r<= blockRate[level][1]) return make_unique<YellowBlock>(shape, 0, 5, -4);
    if (r > blockRate[level][1] && r <= blockRate[level][2]) return make_unique<CyanBlock>(shape, 0, 5, -4);
    if (r > blockRate[level][2] && r <= blockRate[level][3]) return make_unique<RedBlock>(shape, 0, 5, -4);
    if (r > blockRate[level][3] && r <= blockRate[level][4]) return make_unique<PurpleBlock>(shape, 0, 5, -4);
    if (r > blockRate[level][4] && r <= blockRate[level][5]) return make_unique<GreenBlock>(shape, 0, 5, -4);
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