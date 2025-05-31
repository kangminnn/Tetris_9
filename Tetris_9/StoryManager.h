//스토리 텍스트
#pragma once
#include <string>
#include "Constants.h"

class StoryManager {
public:
    static void showIntro();
    static void showLevelUp(int level);
    static void showLV1();
    static void showLV2();
    static void showLV3();
    static void showLV4();
    static void showLV5();
    static void showLV6();
    static void showLV7();
    static void showIFNT();
    static void showEnding();
};