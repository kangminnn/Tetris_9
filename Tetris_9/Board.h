#pragma once

class Board {
private:
    int grid[21][14];
public:
    Board();
    void init();
    bool strike_check(int shape, int angle, int x, int y) const;
    void merge_block(int shape, int angle, int x, int y);
    int check_full_line();
};
