#include "Constants.h"
#include <string>

//int level;
int ab_x = 4, ab_y = 4;	//화면중 블럭이 나타나는 좌표의 절대위치
//int score;
//int lines;
Cell total_block[21][14];		//화면에 표시되는 블럭들
struct STAGE stage_data[8];

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

void SetStageColor(int level) {
	switch (level) {
	case 0: SetColor(BLUE); break;
	case 1: SetColor(YELLOW); break;
	case 2: SetColor(SKY_BLUE); break;
	case 3: SetColor(RED); break;
	case 4: SetColor(VOILET); break;
	case 5: SetColor(GREEN); break;
	case 6: SetColor(GRAY); break;
	default: SetColor(WHITE); break;
	}
}

//abilities {blue, green, cyan, yellow, red, purple}
void initStageData()
{
	// Stage 0 (Tutorial stage)
	stage_data[0].speed = 40;
	stage_data[0].score = SCORE;
	stage_data[0].abilities = { true, false, false, false, false, false };  // Only blue block ability enabled

	// Stage 1
	stage_data[1].speed = 38;
	stage_data[1].score = SCORE;
	stage_data[1].abilities = { true, true, false, false, false, false };  // Blue and yellow abilities

	// Stage 2
	stage_data[2].speed = 35;
	stage_data[2].score = SCORE;
	stage_data[2].abilities = { true, true, true, false, false, false };  // Blue, yellow, and sky blue abilities

	// Stage 3
	stage_data[3].speed = 30;
	stage_data[3].score = SCORE;
	stage_data[3].abilities = { true, true, true, true, false, false };  // Blue, yellow, sky blue, red

	// Stage 4 (Mix it up - disable some abilities)
	stage_data[4].speed = 25;
	stage_data[4].score = SCORE;
	stage_data[4].abilities = { true, true, true, true, true, false }; // Blue, yellow, sky blue, red, purple

	// Stage 5
	stage_data[5].speed = 20;
	stage_data[5].score = SCORE;
	stage_data[5].abilities = { true, true, true, true, true, true }; // Blue, yellow, sky blue, red, purple, green

	// Stage 6 //boss stage
	stage_data[6].speed = 15;
	stage_data[6].score = HP;
	stage_data[6].abilities = { true, true, true, true, true, true };

	// Stage 7 //infinite mode
	stage_data[7].speed = 10;
	stage_data[7].score = 10000000;
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

void centerPrint(int y, const string& text, int width) {
	int x = (width - text.length()) / 2;
	gotoxy(x, y);
	cout << text;
}


// 엔딩이나 스테이지 출력 후 대기
void waitForKeyAfterDelay() {
	Sleep(2000);       // 1. 대기
	while (_kbhit()) _getch();    // 2. 버퍼 비우기 (연타 방지)
	_getch();              // 3. 키 입력 대기
}