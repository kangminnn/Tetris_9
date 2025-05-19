//게임 상태 관리
#pragma once
#include "Board.h"
#include "Block.h"
#include "Renderer.h"
#include "BlockFactory.h"

class Game {
private:
    Board board;
    Block curBlock;
    Block nextBlock;
    int level;
    int score;
    int lines;
    int isGameOver;
public:
    Game();
    void run();


};