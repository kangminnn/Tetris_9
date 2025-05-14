#pragma once

class Board {
private:
    int grid[20][10];   // 20x10 ��Ʈ������
public:
    void placeBlock(const Block& block);
    int clearLines();   // ���� ���� �� ���ŵ� �� ��ȯ
    bool isCollision(const Block& block) const;
};
