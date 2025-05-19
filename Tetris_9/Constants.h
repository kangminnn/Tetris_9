//블록 모양, 문자열
#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

#define WIDTH 14
#define HEIGHT 21
#define EXT_KEY 0xffffffe0
#define KEY_LEFT 0x4b
#define KEY_RIGHT 0x4d
#define KEY_UP 0x48
#define KEY_DOWN 0x50

enum {
	BLACK,      /*  0 : 까망 */
	DARK_BLUE,    /*  1 : 어두운 파랑 */
	DARK_GREEN,    /*  2 : 어두운 초록 */
	DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
	DARK_RED,    /*  4 : 어두운 빨강 */
	DARK_VOILET,  /*  5 : 어두운 보라 */
	DARK_YELLOW,  /*  6 : 어두운 노랑 */
	GRAY,      /*  7 : 회색 */
	DARK_GRAY,    /*  8 : 어두운 회색 */
	BLUE,      /*  9 : 파랑 */
	GREEN,      /* 10 : 초록 */
	SKY_BLUE,    /* 11 : 하늘 */
	RED,      /* 12 : 빨강 */
	VOILET,      /* 13 : 보라 */
	YELLOW,      /* 14 : 노랑 */
	WHITE,      /* 15 : 하양 */
};

struct STAGE {
	int speed;
	int stick_rate;
	int clear_line;
};

struct Cell {
	int occupied = 0;
	int color = 0; // 1 ~ 7 등 컬러코드
};

extern int level;
extern int ab_x, ab_y;	//화면중 블럭이 나타나는 좌표의 절대위치
extern int score;
extern int lines;
extern Cell total_block[21][14];		//화면에 표시되는 블럭들
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

