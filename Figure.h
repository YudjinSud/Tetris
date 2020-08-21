//
// Created by yudjin on 8/21/20.
//


#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#define vi std::vector<int>
#define matrix std::vector<std::vector<int>>
#define v2f sf::Vector2f

const float cellSize = 20;

const matrix shapes = {
        {2, 3, 4, 5}, // square
        {4, 2, 3, 1}, // N
        {5, 3, 2, 0}, // N - reversed
        {0, 2, 4, 6}, // I
        {0, 2, 4, 5}, // L
        {1, 3, 5, 4}, // L - reversed
        {2, 3, 1, 5}, // T
};

class Cell {
public:
    v2f position;
    sf::Color color;
    sf::RectangleShape sh;
};


class Figure {
public:

    Figure(int shape) : shape(shape) {}

    void create();

    void draw();

    void rotate();

    void move(int x, int y);

    std::vector<Cell> cells;

private:
    int shape;
};


#endif //TETRIS_FIGURE_H
