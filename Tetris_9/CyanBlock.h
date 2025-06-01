#pragma once
#include "Block.h"
#include "Board.h"
class CyanBlock : public Block {
public:
    CyanBlock(int shape, int angle, int x, int y);

    int getColor() const override { return SKY_BLUE; }

    bool check(const Board& board, int& level) const override;// ������ �ߵ� ����
    void active(Board& board) override; // ������ cpp����
};