//
// Created by yudjin on 8/21/20.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Figure.h"

#define width 640
#define height 480
#define latency 5

class Game {
public:
    void tick();

    void update();

    void processInput();

    void draw();

    void init();

    void addFigure();

    sf::RenderWindow window;

private:
    sf::Event events;

    std::vector<Figure*> figures;

    Figure *activeFigure;

};


#endif //TETRIS_GAME_H
