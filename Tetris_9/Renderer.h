//콘솔 출력
#pragma once
#include "Board.h"
#include "Block.h"
#include "BlockFactory.h"

class Renderer {
public:
	static int show_total_block(int& level);
	static int show_gameover();
	static void show_pause();
	static void erase_pause();
	static int show_gamestat(int level, int score);
	static int show_logo();

	static void showNextBlock(unique_ptr<Block>& b);
	static void showCurBlock(unique_ptr<Block>& b);
	static void showSilhouetteBlock(unique_ptr<Block>& b, unique_ptr<Block>& b2);
	static void eraseCurBlock(unique_ptr<Block>& b);
	static void eraseSilhouetteBlock(unique_ptr<Block>& b, unique_ptr<Block>& b2);
};
