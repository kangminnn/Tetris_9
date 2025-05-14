#pragma once
#include "Board.h"
#include "Block.h"

class Game {
private:
    Board board;
    Block currentBlock;
    bool gameOver;
    int level, score;
public:
    Game();
    void update(char input);     // �Է� ó��
    bool isGameOver() const;
    Board getBoard() const;
    Block getBlock() const;
};
