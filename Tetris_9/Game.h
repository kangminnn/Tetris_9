//게임 상태 관리
#pragma once
#include "Board.h"
#include "Block.h"

class Game {
private:
    Board board;
    Block currentBlock;
    Block nextBlock;
    int level;
    int score;
    int lines;
    int isGameOver;
public:
    Game();
    void run();
    //void update(char input); //다음 단계로 넘어가는 로직
    //bool over() const; //게임 종료되는 경우
    int move_block(int* shape, int* angle, int* x, int* y, int* next_shape);

};