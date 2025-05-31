//스토리 텍스트
#pragma once
#include <string>
#include "Constants.h"

class StoryManager {
public:
    static void showIntro();
    static void showLevelUp(int level);
    static void showEnding();
};