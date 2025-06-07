//��� ����, ȸ��, �̵�
#pragma once
#include "Constants.h"

class Board;
 
class Block {
protected:
    int shape;
    int angle;
    int x, y;
public:
    Block() = default;
    Block(int shape, int angle, int x, int y);

    // ��� ���� �� �̸�(�ʿ�� �������̵�)
    virtual int getColor() const { return DARK_GRAY; }  // �⺻��

    // --- �ɷ� �ý���: �����Լ� �߰� ---
    // ������ �´��� üũ (Board ���� �ʿ�� const Board& ���)
    virtual bool check(const Board& board, int& level) const { return false; }
    // �ɷ� ����
    virtual void active(Board& board) { /* do nothing by default */ }

    int getShape() const;
    int getAngle() const;
    int getX() const;
    int getY() const;
    void setAngle(int angle);
    void setX(int x);
    void setY(int y);
    void set(int shape, int angle, int x, int y);
};
