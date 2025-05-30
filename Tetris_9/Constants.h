//��� ���, ���ڿ�
#pragma once
#include <iostream>
#include <Windows.h>
#include <memory>
using namespace std;

#define WIDTH 14
#define HEIGHT 21
#define EXT_KEY 0xffffffe0
#define KEY_LEFT 0x4b
#define KEY_RIGHT 0x4d
#define KEY_UP 0x48
#define KEY_DOWN 0x50

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
	bool greenBlockAbility;    // �׸����(����)
	bool cyanBlockAbility;  // �ϴú��(�Ҹ�)
	bool yellowBlockAbility;   // ������(�ܻ�)
	bool redBlockAbility;  // �������(����)
	bool purpleBlockAbility;   // ������(����)
};

// Add block abilities to stage data
struct STAGE {
	int speed;
	int stick_rate;
	int clear_line;
	BlockAbilities abilities;  // Available abilities for this stage
};

struct Cell {
	int occupied = 0;
	int color = 0; // 1 ~ 7 �� �÷��ڵ�
	int count = 0;
};

//extern int level;
extern int ab_x, ab_y;	//ȭ���� ���� ��Ÿ���� ��ǥ�� ������ġ
//extern int score;
//extern int lines;
extern Cell total_block[21][14];		//ȭ�鿡 ǥ�õǴ� ����
extern struct STAGE stage_data[10];

extern char block[7][4][4][4];

void gotoxy(int x, int y);
void SetColor(int color);
void clear_line_mt(int x, int y);
void clear_block(int x, int y);
void initStageData();

class Constants
{	
};

