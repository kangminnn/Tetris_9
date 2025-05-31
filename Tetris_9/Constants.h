//��� ���, ���ڿ�
#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <memory>
using namespace std;

#define WIDTH 14
#define HEIGHT 21
#define EXT_KEY 0xffffffe0
#define KEY_LEFT 0x4b
#define KEY_RIGHT 0x4d
#define KEY_UP 0x48
#define KEY_DOWN 0x50

#define SCORE 30 //����׿� ������ 100�����Ұ�
#define HP 200 //���� ü��

enum {
	BLACK,      /*  0 : ��� */
	DARK_BLUE,    /*  1 : ��ο� �Ķ� */
	DARK_GREEN,    /*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */
	DARK_RED,    /*  4 : ��ο� ���� */
	DARK_VOILET,  /*  5 : ��ο� ���� */
	DARK_YELLOW,  /*  6 : ��ο� ��� */
	GRAY,      /*  7 : ȸ�� */
	DARK_GRAY,    /*  8 : ��ο� ȸ�� */
	BLUE,      /*  9 : �Ķ� */
	GREEN,      /* 10 : �ʷ� */
	SKY_BLUE,    /* 11 : �ϴ� */
	RED,      /* 12 : ���� */
	VOILET,      /* 13 : ���� */
	YELLOW,      /* 14 : ��� */
	WHITE,      /* 15 : �Ͼ� */
};

// �� Ư���ɷ� On/Off
struct BlockAbilities {
	bool blueBlockAbility;     // ����(������)
	bool yellowBlockAbility;   // ������(�ܻ�)
	bool cyanBlockAbility;  // �ϴú��(�Ҹ�)
	bool redBlockAbility;  // �������(����)
	bool purpleBlockAbility;   // ������(����)
	bool greenBlockAbility;    // �׸����(����)
};

// Add block abilities to stage data
struct STAGE {
	int speed;
	int score;
	BlockAbilities abilities;  // Available abilities for this stage
};

struct Cell {
	int occupied = 0;
	int color = 0; // 1 ~ 7 �� �÷��ڵ�
	int count = 0;
};

extern int ab_x, ab_y;	//ȭ���� ���� ��Ÿ���� ��ǥ�� ������ġ
extern Cell total_block[21][14];		//ȭ�鿡 ǥ�õǴ� ����
extern struct STAGE stage_data[8];

extern char block[7][4][4][4];

void gotoxy(int x, int y);
void SetColor(int color);
void SetStageColor(int level);
void clear_line_mt(int x, int y);
void clear_block(int x, int y);
void initStageData();
void hideCursor();
void showCursor();
void centerPrint(int y, const string& text, int width);
void waitForKeyAfterDelay();

class Constants
{	
};

