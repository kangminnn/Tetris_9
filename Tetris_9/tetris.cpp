#include "Game.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "StoryManager.h"

int main() {
    Game game;
    Renderer renderer;
    InputHandler inputHandler;
    StoryManager story;

    story.showIntro();

    while (!game.isGameOver()) {
        renderer.drawBoard(game.getBoard(), game.getBlock());
        char input = inputHandler.getInput();
        game.update(input);
    }

    story.showEnding();
    return 0;
}
