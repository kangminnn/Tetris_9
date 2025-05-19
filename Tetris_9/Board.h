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
    bool strikeCheck(unique_ptr<Block>& b);
    void mergeBlock(unique_ptr<Block>& b);
    bool rotateStrikeCheck(unique_ptr<Block>& b);
    int moveBlock(unique_ptr<Block>& b);
};
