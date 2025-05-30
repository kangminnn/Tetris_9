#include "Constants.h"
#include <string>

//int level;
int ab_x = 0, ab_y = 0;	//화면중 블럭이 나타나는 좌표의 절대위치
//int score;
//int lines;
Cell total_block[21][14];		//화면에 표시되는 블럭들
struct STAGE stage_data[10];

char block[7][4][4][4] = {
	//막대모양
	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,

	//네모모양
	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,

	//'ㅓ' 모양
	0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,	1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,	0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,

	//'ㄱ'모양
	1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,	1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,	0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,

	//'ㄴ' 모양
	1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,	1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,	0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,	1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,

	//'Z' 모양
	1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,	0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,	1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,	0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,

	//'S' 모양
	0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,	0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0

};

void gotoxy(int x, int y) {
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(int color) {
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
}

//abilities {blue, green, cyan, yellow, red, purple}
void initStageData()
{
	// Stage 0 (Tutorial stage)
	stage_data[0].speed = 40;
	stage_data[0].score = 100;
	stage_data[0].abilities = { true, false, false, false, false, false };  // Only blue block ability enabled

	// Stage 1
	stage_data[1].speed = 38;
	stage_data[1].score = 100;
	stage_data[1].abilities = { true, true, false, false, false, false };  // Blue and green abilities

	// Stage 2
	stage_data[2].speed = 35;
	stage_data[2].score = 100;
	stage_data[2].abilities = { true, true, true, false, false, false };  // Blue, green, and sky blue abilities

	// Stage 3
	stage_data[3].speed = 30;
	stage_data[3].score = 100;
	stage_data[3].abilities = { true, true, true, true, false, false };  // All abilities enabled

	// Stage 4 (Mix it up - disable some abilities)
	stage_data[4].speed = 25;
	stage_data[4].score = 100;
	stage_data[4].abilities = { true, true, true, true, true, false };

	// Stage 5
	stage_data[5].speed = 20;
	stage_data[5].score = 100;
	stage_data[5].abilities = { true, true, true, true, true, true };

	// Stage 6 //boss stage
	stage_data[6].speed = 15;
	stage_data[6].score = 100;
	stage_data[6].abilities = { true, true, true, true, true, true };

	// Stage 7 //infinite mode
	stage_data[7].speed = 10;
	stage_data[7].score = 100;
	stage_data[7].abilities = { true, true, true, true, true, true };
}

void clear_block(int x, int y) {
	for (int i = 0; i < 4; i++) {
		gotoxy((x + 0) * 2 + ab_x, y + i + ab_y);
		cout<<"        "; // 정확히 4칸 * 2 = 8칸 폭 지움
	}
}

void clear_line_mt(int x, int y) {
	gotoxy(x, y);  // 콘솔 커서 이동 (이 함수는 그대로 사용)
	cout << string(100, ' ');  // 공백 100개 출력
	gotoxy(x, y);  // 커서를 다시 원위치
}

void hideCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE; // 커서 숨김
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void showCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = TRUE; // 커서 표시
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}