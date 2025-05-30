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
	stage_data[0].stick_rate = 20;
	stage_data[0].clear_line = 20;
	stage_data[0].abilities = { true, false, false, false, false, false };  // Only blue block ability enabled

	// Stage 1
	stage_data[1].speed = 38;
	stage_data[1].stick_rate = 18;
	stage_data[1].clear_line = 2;
	stage_data[1].abilities = { true, true, false, false, false, false };  // Blue and green abilities

	// Stage 2
	stage_data[2].speed = 35;
	stage_data[2].stick_rate = 18;
	stage_data[2].clear_line = 2;
	stage_data[2].abilities = { true, true, true, false, false, false };  // Blue, green, and sky blue abilities

	// Stage 3
	stage_data[3].speed = 30;
	stage_data[3].stick_rate = 17;
	stage_data[3].clear_line = 2;
	stage_data[3].abilities = { true, true, true, true, false, false };  // All abilities enabled

	// Stage 4 (Mix it up - disable some abilities)
	stage_data[4].speed = 25;
	stage_data[4].stick_rate = 16;
	stage_data[4].clear_line = 2;
	stage_data[4].abilities = { true, true, true, true, true, false };

	// Stage 5
	stage_data[5].speed = 20;
	stage_data[5].stick_rate = 14;
	stage_data[5].clear_line = 2;
	stage_data[5].abilities = { true, true, true, true, true, true };

	// Stage 6
	stage_data[6].speed = 15;
	stage_data[6].stick_rate = 14;
	stage_data[6].clear_line = 2;
	stage_data[6].abilities = { true, true, true, true, true, true };

	// Stage 7
	stage_data[7].speed = 10;
	stage_data[7].stick_rate = 13;
	stage_data[7].clear_line = 2;
	stage_data[7].abilities = { true, true, true, true, true, true };

	// Stage 8
	stage_data[8].speed = 6;
	stage_data[8].stick_rate = 12;
	stage_data[8].clear_line = 2;
	stage_data[8].abilities = { true, true, true, true, true, true };

	// Stage 9 (Final stage - all abilities)
	stage_data[9].speed = 4;
	stage_data[9].stick_rate = 11;
	stage_data[9].clear_line = 99999;
	stage_data[9].abilities = { true, true, true, true, true, true };
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