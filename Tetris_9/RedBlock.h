#pragma once
#include "Block.h"
#include "Board.h"
#include <vector>
class RedBlock : public Block {
private:
    mutable vector<pair<int, int>> delete_red;
    const int MAX_RED = 10;
public:
    RedBlock(int shape, int angle, int x, int y);

    int getColor() const override { return RED; }
    std::string getColorName() const override { return "Red"; }

    bool check(const Board& board, int& level) const override;
    void active(Board& board) override;
};