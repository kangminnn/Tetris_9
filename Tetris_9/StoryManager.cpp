#include "StoryManager.h"
#include <conio.h>

void StoryManager::showIntro()
{
	SetColor(GREEN);
	system("cls");
	gotoxy(10, 10);
	cout << "intro";
	Sleep(1000);
	while (!_kbhit()) {
		// ��� ���� (�ƹ� Ű �Էµ� ������)
		Sleep(100);
	}
}

void StoryManager::showLevelUp(int level)
{
	SetColor(GREEN);
	system("cls");
	gotoxy(10, 10);
	cout << "level : " << level;
	Sleep(1000);
	while (!_kbhit()) {
		// ��� ���� (�ƹ� Ű �Էµ� ������)
		Sleep(100);
	}
}

void StoryManager::showEnding()
{
	SetColor(GREEN);
	system("cls");
	gotoxy(10, 10);
	cout << "end";
	Sleep(1000);
	while (!_kbhit()) {
		// ��� ���� (�ƹ� Ű �Էµ� ������)
		Sleep(100);
	}
}
