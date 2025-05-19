//블록 생성
#pragma once
#include"Block.h"
#include"Renderer.h"
class BlockFactory
{
public:
	//static int getRandomShape(int level);
	//static int make_new_block();
	//static int block_start(int shape, int* angle, int* x, int* y);
	static Block makeBlock();
};
