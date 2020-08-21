//
// Created by yudjin on 8/21/20.
//

#include "Game.h"

void Game::processInput() {

}

void Game::update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::draw() {
    window.clear();
    for (Figure f : figures) {
        f.draw();
        for(Cell c : f.cells) {
            window.draw(c.sh);
        }
    }

    window.display();
}

void Game::init() {
    this->window.create(sf::VideoMode(width, height), "Tetris");
}