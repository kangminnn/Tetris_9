#pragma once
#include "Block.h"
#include "Board.h"
class BlueBlock : public Block {
public:
    BlueBlock(int shape, int angle, int x, int y);

    int getColor() const override { return BLUE; }

    bool check(const Board& board, int& level) const override;// ������ �ߵ� ����
    void active(Board& board) override; // ������ cpp����
    static void update();
};