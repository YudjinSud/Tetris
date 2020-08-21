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

class Game {
public:

    void update();

    void processInput();

    void draw();

    void init();

    sf::RenderWindow window;

    std::vector<Figure> figures;

private:

};


#endif //TETRIS_GAME_H
