#pragma once
#include "Block.h"
#include "Board.h"
class YellowBlock : public Block {
public:
    YellowBlock(int shape, int angle, int x, int y);

    int getColor() const override { return YELLOW; }
    std::string getColorName() const override { return "Yellow"; }

    bool check(const Board& board) const override;// 무조건 발동 예시
    void active(Board& board) override; // 구현은 cpp에서
};