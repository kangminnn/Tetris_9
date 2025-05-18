#pragma once
#include "Board.h"
#include "Block.h"


class Renderer {
public:
	static int show_total_block(const Board& board);
	static int show_cur_block(int shape, int angle, int x, int y);
	static int erase_cur_block(int shape, int angle, int x, int y);
	static int show_gameover();
	static int show_gamestat(int level, int score, int lines);
	static int show_logo();
	static int show_next_block(int shape);
	static void drawStageFrame();

};
