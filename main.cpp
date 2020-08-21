#include "Figure.h"
#include "Game.h"

int main() {

    Game game;
    game.init();

    Figure fig(0);
    fig.create();

    game.figures.push_back(fig);

    while (game.window.isOpen()) {
        game.processInput();
        game.update();
        game.draw();
    }
    return EXIT_SUCCESS;
}