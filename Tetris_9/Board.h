#pragma once

class Board {
private:
    int grid[20][10];   // 20x10 테트리스판
public:
    void placeBlock(const Block& block);
    int clearLines();   // 라인 제거 후 제거된 수 반환
    bool isCollision(const Block& block) const;
};
