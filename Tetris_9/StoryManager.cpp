#include "StoryManager.h"
#include <conio.h>

void StoryManager::showIntro()
{
	SetColor(BLUE);
    system("cls"); // 콘솔 화면 지우기
    centerPrint(3, "==============================", 80);
    centerPrint(4, "마법 블럭 아카데미", 80);
    centerPrint(5, "==============================", 80);

    SetColor(WHITE);
    centerPrint(7, "제작자: 202211261 김강민", 80);
    centerPrint(8, "        202211327 윤승모", 80);
    centerPrint(9, "        202411346 이승준", 80);
    centerPrint(10, "        202412353 김태은", 80);

    centerPrint(12, "마법은 형태다. 형태는 질서다. 그리고 블럭은 그 질서를 쌓아 올리는 도구다.", 80);
    centerPrint(13, "당신은 『아르카나 마법학교』에 입학한 신입생.", 80);
    centerPrint(14, "이곳은 고대의 마도구 「테트리움」을 이용해 마법 속성 블럭을 다루는", 80);
    centerPrint(15, "전설의 마법사들을 길러내는 유서 깊은 학교다.", 80);
    centerPrint(16, "마법의 기원은 오래전 차원 간 전쟁에서 생겨난 속성의 조화였고", 80);
    centerPrint(17, "블럭은 그 에너지의 형태다.", 80);

    SetColor(BLUE);
    centerPrint(19, "게임을 시작하려면 아무 키나 누르세요...", 80);
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
    centerPrint(5, "[1단계 - 물의 조율자]", 80);
    SetColor(WHITE);
    centerPrint(7, "아르카나 마법학교에 입학한 당신.", 80);
    centerPrint(9, "첫 수업은 물의 흐름을 이해하고 다루는 것이었다.", 80);
    centerPrint(11, "블럭은 무너지지 않는다. 흘러내릴 뿐이다.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV2()
{
    SetColor(YELLOW);
    system("cls");
    centerPrint(5, "[2단계 - 이중의 비전]", 80);
    SetColor(WHITE);
    centerPrint(7, "마법은 환상을 만든다. 그리고 환상은 쉽게 사라지지 않는다.", 80);
    centerPrint(9, "노란 블럭은 한 번의 제거로는 사라지지 않는다.", 80);
    centerPrint(11, "진실을 보려면 한 꺼풀 더 벗겨야 한다.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV3()
{
    SetColor(SKY_BLUE);
    system("cls");
    centerPrint(5, "[3단계 - 서리의 숨결]", 80);
    SetColor(WHITE);
    centerPrint(7, "차가운 기운이 느껴진다.", 80);
    centerPrint(9, "하늘색 블럭은 즉시 사라지지 않는다.", 80);
    centerPrint(11, "시간의 흐름 속에서 천천히 사라질 것이다.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV4()
{
    SetColor(RED);
    system("cls");
    centerPrint(5, "[4단계 - 불꽃의 낙인]", 80);
    SetColor(WHITE);
    centerPrint(7, "열정은 폭발한다. 마법의 불꽃이 내려꽂힌다.", 80);
    centerPrint(9, "빨간 블럭은 터지며 주변 블럭까지 함께 제거한다.", 80);
    centerPrint(11, "제어되지 않은 힘은 파멸을 부른다.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV5()
{
    SetColor(VOILET);
    system("cls");
    centerPrint(5, "[5단계 - 암흑의 간섭]", 80);
    SetColor(WHITE);
    centerPrint(7, "보라색 블럭은 혼돈의 상징.", 80);
    centerPrint(9, "주변의 불과 물 속성을 무력화시킨다.", 80);
    centerPrint(11, "질서의 마법은 어둠 앞에서 무기력하다.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV6()
{
    SetColor(GREEN);
    system("cls");
    centerPrint(5, "[6단계 - 자연의 반향]", 80);
    SetColor(WHITE);
    centerPrint(7, "초록 블럭은 자신을 복제한다.", 80);
    centerPrint(9, "생명의 마법은 하나에서 여럿을 창조한다.", 80);
    centerPrint(11, "단순한 제거는 해결책이 아니다.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showLV7()
{
    SetColor(GRAY);
    system("cls");
    centerPrint(5, "[7단계 - 시험의 전당]", 80);
    SetColor(WHITE);
    centerPrint(7, "당신 앞에 보스가 나타났다.", 80);
    centerPrint(9, "모든 속성을 능숙하게 활용하지 못하면 상대할 수 없다.", 80);
    centerPrint(11, "이제 진정한 마법사의 시험이 시작된다.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showIFNT()
{
    SetColor(BLUE);
    system("cls");
    centerPrint(5, "[무한모드 - 무한의 회랑]", 80);
    SetColor(WHITE);
    centerPrint(7, "이곳은 끝없는 마법의 흐름이 이어지는 공간.", 80);
    centerPrint(9, "시간도, 규칙도 의미가 없다.", 80);
    centerPrint(11, "자신만의 방식으로 마법을 이어가라.", 80);
    waitForKeyAfterDelay();
    system("cls");
}

void StoryManager::showEnding()
{
	SetColor(BLUE);
	system("cls");
    centerPrint(4, "========================================", 80);
    centerPrint(6, "     [졸업 - 대마법사의 길]     ", 80);
    SetColor(WHITE);
    centerPrint(8, "당신은 모든 속성의 마법을 익혔고,", 80);
    centerPrint(9, "무한한 마력의 흐름마저 받아들이는 법을 배웠습니다.", 80);
    centerPrint(11, "어느덧, 선생님들이 당신에게 고개를 숙입니다.", 80);
    centerPrint(13, "당신은 이제 마법학교의 전설이 되었습니다.", 80);

    centerPrint(16, "\"지금 이 순간부터,", 80);
    centerPrint(17, "  당신은 스스로의 마법을 정의할 수 있습니다.\"", 80);

    centerPrint(20, "졸업을 축하합니다, 위대한 마법사여!", 80);

    centerPrint(23, "게임을 종료하려면 아무 키나 누르세요...", 80);
    waitForKeyAfterDelay();
    system("cls");
}
