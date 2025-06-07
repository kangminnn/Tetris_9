//블록 정보, 회전, 이동
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

    // 블록 색상 및 이름(필요시 오버라이딩)
    virtual int getColor() const { return DARK_GRAY; }  // 기본값

    // --- 능력 시스템: 가상함수 추가 ---
    // 조건이 맞는지 체크 (Board 정보 필요시 const Board& 사용)
    virtual bool check(const Board& board, int& level) const { return false; }
    // 능력 실행
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
