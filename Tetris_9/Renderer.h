#pragma once
#include "Board.h"
#include "Block.h"

class Renderer {
public:
    void drawBoard(const Board& board, const Block& block);
    void showMessage(const std::string& message);
};
