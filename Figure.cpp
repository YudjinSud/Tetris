//
// Created by yudjin on 8/21/20.
//

#include "Figure.h"

std::pair<int,int> calculateOffset(int cnt, int shape) {
    std::pair<int,int> ofs;
    if (shapes[shape][cnt] % 2 == 0) {
        ofs.first = 0;
        ofs.second = shapes[shape][cnt++] / 2;
    }
    else {
        ofs.first = 1;
        ofs.second = shapes[shape][cnt++] / 2;
    }
    return ofs;
}

void Figure::create() {
    v2f startPos(250, 250);
    this->cells = std::vector<Cell>(4);

    int cnt = 0;

    for (Cell &c : this->cells) {
        std::pair<int,int> offset = calculateOffset(cnt++, shape);
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
    }
}

void Figure::rotate() {

}

void Figure::move(int x, int y) {

}

