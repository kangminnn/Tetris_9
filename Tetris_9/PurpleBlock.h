#pragma once
#include "Block.h"
#include "Board.h"

class PurpleBlock : public Block {
public:
    PurpleBlock(int shape, int angle, int x, int y);

    int getColor() const override { return VOILET; }

    bool check(const Board& board, int& level) const override;
    void active(Board& board) override;
    static void update();
};