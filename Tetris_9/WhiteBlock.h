#pragma once
#include "Block.h"
#include "Board.h"
class WhiteBlock : public Block {
public:
    WhiteBlock(int shape, int angle, int x, int y);

    int getColor() const override { return WHITE; }

    bool check(const Board& board, int& level) const override;// ������ �ߵ� ����
    void active(Board& board) override; // ������ cpp����
};