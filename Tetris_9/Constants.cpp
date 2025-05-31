#include "Constants.h"
#include <string>

//int level;
int ab_x = 4, ab_y = 4;	//ȭ���� ���� ��Ÿ���� ��ǥ�� ������ġ
//int score;
//int lines;
Cell total_block[21][14];		//ȭ�鿡 ǥ�õǴ� ����
struct STAGE stage_data[8];

char block[7][4][4][4] = {
	//������
	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,

	//�׸���
	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,

	//'��' ���
	0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,	1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,	0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,

	//'��'���
	1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,	1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,	0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,

	//'��' ���
	1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,	1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,	0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,	1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,

	//'Z' ���
	1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,	0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,	1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,	0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,

	//'S' ���
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
		cout<<"        "; // ��Ȯ�� 4ĭ * 2 = 8ĭ �� ����
	}
}

void clear_line_mt(int x, int y) {
	gotoxy(x, y);  // �ܼ� Ŀ�� �̵� (�� �Լ��� �״�� ���)
	cout << string(100, ' ');  // ���� 100�� ���
	gotoxy(x, y);  // Ŀ���� �ٽ� ����ġ
}

void hideCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE; // Ŀ�� ����
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void showCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = TRUE; // Ŀ�� ǥ��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void centerPrint(int y, const string& text, int width) {
	int x = (width - text.length()) / 2;
	gotoxy(x, y);
	cout << text;
}


// �����̳� �������� ��� �� ���
void waitForKeyAfterDelay() {
	Sleep(2000);       // 1. ���
	while (_kbhit()) _getch();    // 2. ���� ���� (��Ÿ ����)
	_getch();              // 3. Ű �Է� ���
}