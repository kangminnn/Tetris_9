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
    drawWizard(0);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV2()
{
    SetColor(BLUE);
    system("cls");
    centerPrint(5, "[2�ܰ� - ������ ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "������ ȯ���� �����. �׸��� ȯ���� ���� ������� �ʴ´�.", 80);
    centerPrint(9, "��� ���� �� ���� ���ŷδ� ������� �ʴ´�.", 80);
    centerPrint(11, "������ ������ �� ��Ǯ �� ���ܾ� �Ѵ�.", 80);
    drawWizard(1);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV3()
{
    SetColor(BLUE);
    system("cls");
    centerPrint(5, "[3�ܰ� - ������ ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "������ ����� ��������.", 80);
    centerPrint(9, "�ϴû� ���� ��� ������� �ʴ´�.", 80);
    centerPrint(11, "�ð��� �帧 �ӿ��� õõ�� ����� ���̴�.", 80);
    drawWizard(2);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV4()
{
    SetColor(BLUE);
    system("cls");
    centerPrint(5, "[4�ܰ� - �Ҳ��� ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "������ �����Ѵ�. ������ �Ҳ��� ����������.", 80);
    centerPrint(9, "���� ���� ������ �ֺ� ������ �Բ� �����Ѵ�.", 80);
    centerPrint(11, "������� ���� ���� �ĸ��� �θ���.", 80);
    drawWizard(3);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV5()
{
    SetColor(BLUE);
    system("cls");
    centerPrint(5, "[5�ܰ� - ������ ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "����� ���� ȥ���� ��¡.", 80);
    centerPrint(9, "�ֺ��� �Ұ� �� �Ӽ��� ����ȭ��Ų��.", 80);
    centerPrint(11, "������ ������ ��� �տ��� ������ϴ�.", 80);
    drawWizard(4);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV6()
{
    SetColor(BLUE);
    system("cls");
    centerPrint(5, "[6�ܰ� - �ڿ��� ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "�ʷ� ���� �ڽ��� �����Ѵ�.", 80);
    centerPrint(9, "������ ������ �ϳ����� ������ â���Ѵ�.", 80);
    centerPrint(11, "�ܼ��� ���Ŵ� �ذ�å�� �ƴϴ�.", 80);
    drawWizard(5);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV7()
{
    SetColor(BLUE);
    system("cls");
    centerPrint(5, "[7�ܰ� - ������ ����]", 80);
    SetColor(WHITE);
    centerPrint(7, "��� �տ� ������ ��Ÿ����.", 80);
    centerPrint(9, "��� �Ӽ��� �ɼ��ϰ� Ȱ������ ���ϸ� ����� �� ����.", 80);
    centerPrint(11, "���� ������ �������� ������ ���۵ȴ�.", 80);
    drawWizard(6);
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
    drawWizard(6);
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



void StoryManager::particle(int color, int c)
{
    SetColor(color);
    if (c == 0) {
        gotoxy(46, 14); cout << "*";
        gotoxy(59, 14); cout << "*";

        gotoxy(49, 15); cout << "*";
        gotoxy(55, 15); cout << "*";
        gotoxy(61, 15); cout << "*";

        gotoxy(52, 16); cout << "*";
        gotoxy(63, 16); cout << "*";
    }
    else if (c == 1) {
        gotoxy(46, 15); cout << "*";
        gotoxy(59, 15); cout << "*";

        gotoxy(49, 16); cout << "*";
        gotoxy(55, 16); cout << "*";
        gotoxy(61, 16); cout << "*";

        gotoxy(52, 17); cout << "*";
        gotoxy(63, 17); cout << "*";
    }
    else if (c == 2) {
        gotoxy(46, 16); cout << "*";
        gotoxy(59, 16); cout << "*";

        gotoxy(49, 17); cout << "*";
        gotoxy(55, 17); cout << "*";
        gotoxy(61, 17); cout << "*";

        gotoxy(52, 18); cout << "*";
        gotoxy(63, 18); cout << "*";
    }
    else if (c == 3) {
            
        int cx=55, cy=17;
            SetColor(RED);

            gotoxy(46, 17);
            cout << "* *  *";

            // �߽�
            gotoxy(cx, cy);         cout << "*";

            // ����
            gotoxy(cx, cy - 1);     cout << "|";
            gotoxy(cx, cy - 2);     cout << "|";
            gotoxy(cx, cy + 1);     cout << "|";
            gotoxy(cx, cy + 2);     cout << "|";

            // �¿�
            gotoxy(cx - 1, cy);     cout << "-";
            gotoxy(cx - 2, cy);     cout << "-";
            gotoxy(cx + 1, cy);     cout << "-";
            gotoxy(cx + 2, cy);     cout << "-";

            // �밢��
            gotoxy(cx - 2, cy - 2); cout << "\\";
            gotoxy(cx + 2, cy - 2); cout << "/";
            gotoxy(cx - 2, cy + 2); cout << "/";
            gotoxy(cx + 2, cy + 2); cout << "\\";

    }
}

void StoryManager::drawWizard(int level)
{

    if (level == 0) {
        centerPrint(14, "  /^\\", 80);
        centerPrint(15, "   (o_o) /", 80);
        centerPrint(16, "  <|||>/", 80);
        centerPrint(17, " /   \\", 80);
        particle(BLUE, 0);
    }
    else if (level == 1) {
        centerPrint(14, "  /*\\", 80);
        centerPrint(15, "   (o_o) /", 80);
        centerPrint(16, "  <|||>/", 80);
        centerPrint(17, " /   \\", 80);
        particle(YELLOW, 0);
    }
    else if (level == 2) {
        centerPrint(14, "  /^\\", 80);
        centerPrint(15, "  /^^^\\", 80);
        centerPrint(16, "   (o_o) /", 80);
        centerPrint(17, "  <|||>/", 80);
        centerPrint(18, " /   \\", 80);
        particle(SKY_BLUE, 1);
    }
    else if (level == 3) {
        centerPrint(14, "  /^\\", 80);
        centerPrint(15, "  /^*^\\", 80);
        centerPrint(16, "   (o_o) /", 80);
        centerPrint(17, "  <|||>/", 80);
        centerPrint(18, " /   \\", 80);
        particle(RED, 1);
    }
    else if (level == 4) {
        centerPrint(14, "  /^\\", 80);
        centerPrint(15, "  /^^^\\", 80);
        centerPrint(16, "  /^^^^^\\", 80);
        centerPrint(17, "   (o_o) /", 80);
        centerPrint(18, "  <|||>/", 80);
        centerPrint(19, " /   \\", 80);
        particle(VOILET, 2);
    }
    else if (level == 5) {
        centerPrint(14, "  /^\\", 80);
        centerPrint(15, "  /^*^\\", 80);
        centerPrint(16, "  /^^^^^\\", 80);
        centerPrint(17, "   (o_o) /", 80);
        centerPrint(18, "  <|||>/", 80);
        centerPrint(19, " /   \\", 80);
        particle(GREEN, 2);
    }
    else if (level == 6) {
        centerPrint(14, "  /^\\", 80);
        centerPrint(15, "  /^*^\\", 80);
        centerPrint(16, "  /^***^\\", 80);
        centerPrint(17, "   (o_o) /", 80);
        centerPrint(18, "  <|||>/", 80);
        centerPrint(19, " /   \\", 80);
        particle(GRAY, 3);
    }
}
