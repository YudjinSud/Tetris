//
// Created by yudjin on 8/21/20.
//

#include "Figure.h"

std::pair<int, int> calculateOffset(int cnt, int shape) {
    std::pair<int, int> ofs;
    ofs.first = shapes[shape][cnt] % 2;
    ofs.second = shapes[shape][cnt] / 2;

    return ofs;
}

void Figure::create() {
    srand((unsigned) time(0));
    v2f startPos(250, 10);
    this->cells = std::vector<Cell>(4);
    this->shape = rand() % shapes.size();
    int cnt = 0;

    for (Cell &c : this->cells) {
        std::pair<int, int> offset = calculateOffset(cnt++, shape);
        c.position = v2f(startPos.x + cellSize * offset.first,
                         startPos.y + cellSize * offset.second);
        c.color = sf::Color::Green;

    }
}

void Figure::draw() {
    for (Cell &c : this->cells) {
        c.sh.setFillColor(c.color);
        c.sh.setPosition(c.position);
        c.sh.setSize(v2f(cellSize, cellSize));
        c.sh.setOutlineColor(sf::Color::Black);
        c.sh.setOutlineThickness(1);
    }
}

void Figure::rotate() {

}

void Figure::move(float x, float y) {
    for (Cell &c : cells) {
        c.position.x += x;
        c.position.y += y * this->verticalSpeed;
        c.sh.setPosition(c.position);
    }
}

Cell Figure::getLowestCell() {
    int minY = 0;
    Cell res;
    for(Cell &c : cells) {
        if(c.position.y > minY) {
            minY = c.position.y;
            res = c;
        }
    }
    return res;
}