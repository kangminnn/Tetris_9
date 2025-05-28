#include "Block.h"
#include "Board.h"
#include <set>
#include <utility>

class GreenBlock : public Block {
public:
    GreenBlock(int shape, int angle, int x, int y)
        : Block(shape, angle, x, y) {
    }

    int getColor() const override { return GREEN; }
    std::string getColorName() const override { return "Green"; }

    bool check(const Board& board) const override;// ������ �ߵ� ����
    void active(Board& board) override; // ������ cpp����
};