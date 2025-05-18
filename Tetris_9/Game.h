//���� ���� ����
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
    //void update(char input); //���� �ܰ�� �Ѿ�� ����
    //bool over() const; //���� ����Ǵ� ���
    int move_block(int* shape, int* angle, int* x, int* y, int* next_shape);

};