#include "Block.h"
#include "Board.h"

class GreenBlock : public Block {
private:
    bool abilityUsed;
public:
    GreenBlock(int shape, int angle, int x, int y);

    int getColor() const override { return GREEN; }

    bool check(const Board& board, int& level) const override;// ������ �ߵ� ����
    void active(Board& board) override; // ������ cpp����
};