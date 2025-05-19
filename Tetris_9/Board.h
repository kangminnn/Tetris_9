//보드 상태, 라인 제거
#pragma once
#include"Block.h"
class Board {
private:
    int grid[21][14];
public:
    Board() = default;
    void init();
    //bool strike_check(int shape, int angle, int x, int y) const;
    //void merge_block(int shape, int angle, int x, int y);
    int check_full_line();
    bool strikeCheck(Block b);
    void mergeBlock(Block b);
    bool rotateStrikeCheck(Block b);
    int moveBlock(Block& b);
};
