#define NOMINMAX
#include "InputHandler.h"
#include "Constants.h"
#include <string>
#include <limits>
#include <sstream>
#include "Renderer.h"





int InputHandler::get_valid_int(int min, int max) {
	string input;
	int val;
	bool error = false;
	Renderer renderer;

	while (true) {
		renderer.drawInput();
		clear_line_mt(10, 3);
		cout << "Select Start Class[" << min << "-" << max - 2 << "]: ";
		getline(cin, input);

		// 입력 오류 처리
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");

			cout << "입력 오류가 발생했습니다.\n";
			continue;
		}

		std::istringstream iss(input);
		if (!(iss >> val) || !(iss.eof())) {
			system("cls");
			cout << "숫자만 입력해주세요.\n";
			continue;
		}

		if (val < min || val > max) {
			system("cls");
			cout << min << "에서 " << max << " 사이의 값을 입력해주세요.\n";
			continue;
		}

		return val;
	}
}
