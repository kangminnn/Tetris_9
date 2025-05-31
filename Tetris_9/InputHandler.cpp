#define NOMINMAX
#include "InputHandler.h"
#include "Constants.h"
#include <string>
#include <limits>
#include <sstream>



int InputHandler::input_data(int& level)
{
	int i = 0;
	SetColor(GRAY);
	gotoxy(10, 7); cout << "┏━━━━━━━━━━━━━━━━━━━━<Select Class>━━━━━━━━━━━━━━━━━━┓";
	Sleep(10);
	gotoxy(10, 8); cout << "┃                                                    ┃";
	Sleep(10);
	gotoxy(10, 9); cout << "┃ Class 1 : 흐름과 질서 - 물의 정화 (파랑 블럭)      ┃";
	Sleep(10);
	gotoxy(10, 10); cout << "┃                                                    ┃";
	Sleep(10);
	gotoxy(10, 11); cout << "┃ Class 2 : 겹쳐진 진실 - 비전 마법 (노랑 블럭)      ┃";
	Sleep(10);
	gotoxy(10, 12); cout << "┃                                                    ┃";
	Sleep(10);
	gotoxy(10, 13); cout << "┃ Class 3 : 시간의 얼음 - 냉기 마법 (하늘색 블럭)    ┃";
	Sleep(10);
	gotoxy(10, 14); cout << "┃                                                    ┃";
	Sleep(10);
	gotoxy(10, 15); cout << "┃ Class 4 : 화염의 격류 - 화염 마법 (빨강 블럭)      ┃";
	Sleep(10);
	gotoxy(10, 16); cout << "┃                                                    ┃";
	Sleep(10);
	gotoxy(10, 17); cout << "┃ Class 5 : 금지된 마법 - 암흑 마법 (보라 블럭)      ┃";
	Sleep(10);
	gotoxy(10, 18); cout << "┃                                                    ┃";
	Sleep(10);
	gotoxy(10, 19); cout << "┃ Class 6 : 생명의 순환 - 자연 마법 (초록 블럭)      ┃";
	Sleep(10);
	gotoxy(10, 20); cout << "┃                                                    ┃";
	Sleep(10);
	gotoxy(10, 21); cout << "┃ BOSS MODE : 암흑의 대마도사 「벡타르」 와의 결투   ┃";
	Sleep(10);
	gotoxy(10, 22); cout << "┃                                                    ┃";
	Sleep(10);
	gotoxy(10, 23); cout << "┃ INFINITE MODE : 무한의 탑 - 아르카나 마스터        ┃";
	Sleep(10);
	gotoxy(10, 24); cout << "┃                                                    ┃";
	Sleep(10);
	gotoxy(10, 25); cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	gotoxy(10, 4);
	cout << "Select 7 for boss stage, 8 for infinite mode";

	i = get_valid_int(1, 8);

	level = i - 1;
	system("cls");
	return 0;
}

int InputHandler::get_valid_int(int min, int max) {
	string input;
	int val;

	while (true) {
		clear_line_mt(10, 3);
		cout << "Select Start Class[" << min << "-" << max - 2 << "]: ";
		getline(cin, input);

		// 입력 오류 처리
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			clear_line_mt(10, 3);
			cout << "입력 오류가 발생했습니다.\n";
			continue;
		}

		std::istringstream iss(input);
		if (!(iss >> val) || !(iss.eof())) {
			clear_line_mt(10, 3);
			cout << "숫자만 입력해주세요.\n";
			continue;
		}

		if (val < min || val > max) {
			clear_line_mt(10, 3);
			cout << min << "에서 " << max << " 사이의 값을 입력해주세요.\n";
			continue;
		}

		return val;
	}
}
