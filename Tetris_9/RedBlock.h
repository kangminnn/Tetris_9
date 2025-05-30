#pragma once
#include "Block.h"
#include "Board.h"
class RedBlock : public Block {
public:
    RedBlock(int shape, int angle, int x, int y);

    int getColor() const override { return RED; }
    std::string getColorName() const override { return "Red"; }

    bool check(const Board& board, int& level) const override;// ������ �ߵ� ����
    void active(Board& board) override; // ������ cpp����
};