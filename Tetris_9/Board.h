//보드 상태, 라인 제거
#pragma once
#include"Block.h"
#include <memory>
using namespace std;

class Board {
private:
    int grid[21][14];
    void checkAndRemoveCyanBlocks(int& level);
public:
    Board() = default;
    void init();
    int check_full_line(int& level, int& score, bool& bomb);
    bool strikeCheck(unique_ptr<Block>& b);
    void mergeBlock(unique_ptr<Block>& b);
    bool rotateStrikeCheck(unique_ptr<Block>& b);
    bool tryRotate(unique_ptr<Block>& b, int i);
    int moveBlock(unique_ptr<Block>& b, int& level, int& score, bool& bomb);
    void clearBottomLines(int& level, int lines);
};
