//
// Created by yudjin on 8/21/20.
//

#include "Game.h"

void printFigure(Figure f) {
    std::cout << "============================================================\n";
    for (Cell c : f.cells) {
        std::cout << "cell at (" << c.position.x << "," << c.position.y << ")\n";
    }
}

void Game::processInput() {
    switch (events.key.code) {
        case sf::Keyboard::Up:
            activeFigure->rotate();
            break;
        case sf::Keyboard::Left:
            activeFigure->move(-moveStep, 0);
//            printFigure(activeFigure);
            break;
        case sf::Keyboard::Right:
            activeFigure->move(moveStep, 0);
//            printFigure(activeFigure);
            break;
        case sf::Keyboard::Down:
            activeFigure->verticalSpeed *= 10;
            break;
        case sf::Keyboard::Escape:
            window.close();
    }
}


void Game::update() {
    while (window.pollEvent(events)) {
        if (events.type == sf::Event::Closed)
            window.close();
        if (events.type == sf::Event::KeyPressed) {
            processInput();
        }
    }
    int lowestY = activeFigure->getLowestCell().position.y;
    if(lowestY < height - moveStep) {
        activeFigure->move(0, moveStep);
    } else {
        addFigure();
    }
}

void Game::draw() {
    window.clear();
//    std::cout << figures[0]->cells[1].position.x << "\n";
//    std::cout << activeFigure.cells[1].position.x << "\n";

    for (Figure *f : figures) {
        f->draw();
        for (Cell c : f->cells) {
            window.draw(c.sh);
        }
    }
    sleep(sf::milliseconds(latency));
    window.display();
}

void Game::init() {
    this->window.create(sf::VideoMode(width, height), "Tetris");
}

void Game::addFigure() {
    auto *fig = new Figure;
    fig->create();
    activeFigure = fig;
    figures.push_back(fig);
}