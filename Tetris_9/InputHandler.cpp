#define NOMINMAX
#include "InputHandler.h"
#include "Constants.h"
#include <string>
#include <limits>
#include <sstream>



int InputHandler::input_data()
{
	int i = 0;
	SetColor(GRAY);
	gotoxy(10, 7);
	cout << "����������������������<GAME KEY>������������������";
	Sleep(10);
	gotoxy(10, 8);
	cout << "�� UP   : Rotate Block        ��";
	Sleep(10);
	gotoxy(10, 9);
	cout << "�� DOWN : Move One-Step Down  ��";
	Sleep(10);
	gotoxy(10, 10);
	cout << "�� SPACE: Move Bottom Down    ��";
	Sleep(10);
	gotoxy(10, 11);
	cout << "�� LEFT : Move Left           ��";
	Sleep(10);
	gotoxy(10, 12);
	cout << "�� RIGHT: Move Right          ��";
	Sleep(10);
	gotoxy(10, 13);
	cout << "������������������������������������������������������������";


	while (i < 1 || i>8)
	{
		gotoxy(10, 3);
		cout << "Select Start level[1-8]:       \b\b\b\b\b\b\b";
		i = get_valid_int(1, 8);
	}

	level = i - 1;
	system("cls");
	return 0;
}

int InputHandler::get_valid_int(int min, int max) {
	string input;
	int val;

	while (true) {
		clear_line_mt(10, 3);
		cout << "Select Start level[" << min << "-" << max << "]: ";
		getline(cin, input);

		// �Է� ���� ó��
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			clear_line_mt(10, 3);
			cout << "�Է� ������ �߻��߽��ϴ�.\n";
			continue;
		}

		std::istringstream iss(input);
		if (!(iss >> val) || !(iss.eof())) {
			clear_line_mt(10, 3);
			cout << "���ڸ� �Է����ּ���.\n";
			continue;
		}

		if (val < min || val > max) {
			clear_line_mt(10, 3);
			cout << min << "���� " << max << " ������ ���� �Է����ּ���.\n";
			continue;
		}

		return val;
	}
}
