//��� ����
#pragma once
#include"Block.h"
#include"Renderer.h"
#include <memory>
class BlockFactory
{
public:
	static unique_ptr<Block> makeBlock(int& level);
};
