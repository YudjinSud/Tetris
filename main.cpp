#include "Figure.h"
#include "Game.h"

int main() {

    Game game;
    game.init();
    game.addFigure();

    while (game.window.isOpen()) {
        game.update();
        game.draw();
    }
    return EXIT_SUCCESS;
}