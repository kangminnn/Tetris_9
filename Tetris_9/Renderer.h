//콘솔 출력
#pragma once
#include "Board.h"
#include "Block.h"
#include "BlockFactory.h"

class Renderer {
public:
	static int show_total_block(int& level);
	//static int show_cur_block(int shape, int angle, int x, int y);
	//static int erase_cur_block(int shape, int angle, int x, int y);
	static int show_gameover();
	static int show_gamestat(int level, int score, int lines);
	static int show_logo();
	//static int show_next_block(int shape);
	//
	static void showNextBlock(unique_ptr<Block>& b);
	static void showCurBlock(unique_ptr<Block>& b);
	static void eraseCurBlock(unique_ptr<Block>& b);
	//static void drawStageFrame();

};
