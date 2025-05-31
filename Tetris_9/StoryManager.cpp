#include "StoryManager.h"
#include <conio.h>

void StoryManager::showIntro()
{
	SetColor(BLUE);
    system("cls"); // �ܼ� ȭ�� �����
    centerPrint(3, "==============================", 80);
    centerPrint(4, "���� �� ��ī����", 80);
    centerPrint(5, "==============================", 80);

    SetColor(WHITE);
    centerPrint(7, "������: 202211261 �谭��", 80);
    centerPrint(8, "        202211327 ���¸�", 80);
    centerPrint(9, "        202411346 �̽���", 80);
    centerPrint(10, "        202412353 ������", 80);

    centerPrint(12, "������ ���´�. ���´� ������. �׸��� ���� �� ������ �׾� �ø��� ������.", 80);
    centerPrint(13, "����� ���Ƹ�ī�� �����б����� ������ ���Ի�.", 80);
    centerPrint(14, "�̰��� ����� ������ ����Ʈ������ �̿��� ���� �Ӽ� ���� �ٷ��", 80);
    centerPrint(15, "������ ��������� �淯���� ���� ���� �б���.", 80);
    centerPrint(16, "������ ����� ������ ���� �� ���￡�� ���ܳ� �Ӽ��� ��ȭ����", 80);
    centerPrint(17, "���� �� �������� ���´�.", 80);

    SetColor(BLUE);
    centerPrint(19, "������ �����Ϸ��� �ƹ� Ű�� ��������...", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLevelUp(int level)
{
    system("cls");
    switch (level) {
    case 0: showLV1(); break;
    case 1: showLV2(); break;
    case 2: showLV3(); break;
    case 3: showLV4(); break;
    case 4: showLV5(); break;
    case 5: showLV6(); break;
    case 6: showLV7(); break;
    case 7: showIFNT(); break;
    }
}
void StoryManager::showLV1()
{
    SetColor(BLUE);
    system("cls");
    centerPrint(5, "[1�ܰ� - ���� ������]", 80);
    SetColor(WHITE);
    centerPrint(7, "�Ƹ�ī�� �����б��� ������ ���.", 80);
    centerPrint(9, "ù ������ ���� �帧�� �����ϰ� �ٷ�� ���̾���.", 80);
    centerPrint(11, "���� �������� �ʴ´�. �귯���� ���̴�.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV2()
{
    SetColor(YELLOW);
    system("cls");
    centerPrint(5, "[2�ܰ� - ������ ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "������ ȯ���� �����. �׸��� ȯ���� ���� ������� �ʴ´�.", 80);
    centerPrint(9, "��� ���� �� ���� ���ŷδ� ������� �ʴ´�.", 80);
    centerPrint(11, "������ ������ �� ��Ǯ �� ���ܾ� �Ѵ�.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV3()
{
    SetColor(SKY_BLUE);
    system("cls");
    centerPrint(5, "[3�ܰ� - ������ ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "������ ����� ��������.", 80);
    centerPrint(9, "�ϴû� ���� ��� ������� �ʴ´�.", 80);
    centerPrint(11, "�ð��� �帧 �ӿ��� õõ�� ����� ���̴�.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV4()
{
    SetColor(RED);
    system("cls");
    centerPrint(5, "[4�ܰ� - �Ҳ��� ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "������ �����Ѵ�. ������ �Ҳ��� ����������.", 80);
    centerPrint(9, "���� ���� ������ �ֺ� ������ �Բ� �����Ѵ�.", 80);
    centerPrint(11, "������� ���� ���� �ĸ��� �θ���.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV5()
{
    SetColor(VOILET);
    system("cls");
    centerPrint(5, "[5�ܰ� - ������ ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "����� ���� ȥ���� ��¡.", 80);
    centerPrint(9, "�ֺ��� �Ұ� �� �Ӽ��� ����ȭ��Ų��.", 80);
    centerPrint(11, "������ ������ ��� �տ��� ������ϴ�.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV6()
{
    SetColor(GREEN);
    system("cls");
    centerPrint(5, "[6�ܰ� - �ڿ��� ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "�ʷ� ���� �ڽ��� �����Ѵ�.", 80);
    centerPrint(9, "������ ������ �ϳ����� ������ â���Ѵ�.", 80);
    centerPrint(11, "�ܼ��� ���Ŵ� �ذ�å�� �ƴϴ�.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV7()
{
    SetColor(GRAY);
    system("cls");
    centerPrint(5, "[7�ܰ� - ������ ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "��� �տ� ������ ��Ÿ����.", 80);
    centerPrint(9, "��� �Ӽ��� �ɼ��ϰ� Ȱ������ ���ϸ� ����� �� ����.", 80);
    centerPrint(11, "���� ������ �������� ������ ���۵ȴ�.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showIFNT()
{
    SetColor(BLUE);
    system("cls");
    centerPrint(5, "[���Ѹ�� - ������ ȸ��]", 80);
    SetColor(WHITE);
    centerPrint(7, "�̰��� ������ ������ �帧�� �̾����� ����.", 80);
    centerPrint(9, "�ð���, ��Ģ�� �ǹ̰� ����.", 80);
    centerPrint(11, "�ڽŸ��� ������� ������ �̾��.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showEnding()
{
	SetColor(BLUE);
	system("cls");
    centerPrint(4, "========================================", 80);
    centerPrint(6, "     [���� - �븶������ ��]     ", 80);
    SetColor(WHITE);
    centerPrint(8, "����� ��� �Ӽ��� ������ ������,", 80);
    centerPrint(9, "������ ������ �帧���� �޾Ƶ��̴� ���� ������ϴ�.", 80);
    centerPrint(11, "�����, �����Ե��� ��ſ��� ���� ���Դϴ�.", 80);
    centerPrint(13, "����� ���� �����б��� ������ �Ǿ����ϴ�.", 80);

    centerPrint(16, "\"���� �� ��������,", 80);
    centerPrint(17, "  ����� �������� ������ ������ �� �ֽ��ϴ�.\"", 80);

    centerPrint(20, "������ �����մϴ�, ������ �����翩!", 80);

    centerPrint(23, "������ �����Ϸ��� �ƹ� Ű�� ��������...", 80);
    waitForKeyAfterDelay();
    system("cls");
}
