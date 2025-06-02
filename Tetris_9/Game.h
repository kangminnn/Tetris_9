//게임 상태 관리
#pragma once
#include "Board.h"
#include "Block.h"
#include "Renderer.h"
#include "BlockFactory.h"
#include <list>

class Game {
private:
    Board board;
    unique_ptr<Block> curBlock;
    unique_ptr<Block> nextBlock;
    int level;
    int score;
    int isGameOver;
    bool bomb;
    //data 저장용
    int total_score;
    list<int> saved_score;
public:
    Game();
    void run();
    void gameInit();
};