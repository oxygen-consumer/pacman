//
// Created by zaha on 3/5/23.
//

#include "Ghost.hpp"

Ghost::Ghost(int color, int x, int y) {
    this->_color = color;
    this->_x = x;
    this->_y = y;
}

Ghost::~Ghost() = default;

Ghost::Ghost(const Ghost &other) {
    this->_color = other._color;
    this->_x = other._x;
    this->_y = other._y;
}

Ghost &Ghost::operator=(const Ghost &other) {
    this->_color = other._color;
    this->_x = other._x;
    this->_y = other._y;

    return *this;
}

void Ghost::move() {
    // TODO: Implement Ghost AI
}

void Ghost::die() {
    // TODO: Implement Ghost death animation
    // TODO: This will set the ghost target to base
}

int Ghost::get_x() {
    return this->_x;
}

int Ghost::get_y() {
    return this->_y;
}

std::ostream &operator<<(std::ostream &os, const Ghost &ghost) {
    os << "Ghost: " << ghost._color << " " << ghost._x << " " << ghost._y;
    return os;
}