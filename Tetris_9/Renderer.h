//콘솔 출력
#pragma once
#include "Board.h"
#include "Block.h"
#include "BlockFactory.h"
#include <list>

class Renderer {
public:
	static int show_total_block(int& level);
	static int show_inner_block();
	static int show_gameover();
	static void show_pause();
	static void erase_pause();
	static void show_gamestat(int level, int score, bool bomb);
	static void show_gamekey(bool bomb);
	static int show_logo();
	static void show_score(list<int>saved_score);

	static void showNextBlock(unique_ptr<Block>& b);
	static void showCurBlock(unique_ptr<Block>& b);
	static void showSilhouetteBlock(unique_ptr<Block>& b, unique_ptr<Block>& b2);
	static void eraseCurBlock(unique_ptr<Block>& b);
	static void eraseSilhouetteBlock(unique_ptr<Block>& b, unique_ptr<Block>& b2);
	static void updateSilhouetteBlock(Board& board, unique_ptr<Block>& silhouette, unique_ptr<Block>& currentBlock);
	static void showWizard(int level);
	static void particle(int level);
	static void showEnemy(int level);
	static void drawInput();
};