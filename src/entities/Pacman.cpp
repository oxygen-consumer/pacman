//
// Created by zaha on 3/5/23.
//

#include "Pacman.hpp"

Pacman::Pacman(int x, int y) {
    this->_x = x;
    this->_y = y;

    this->_is_alive = true;
    this->_is_super = false;
    this->_is_moving = false;

    this->_direction = 0;
    this->_speed = 1;
    this->_super_time = 0;
}

void Pacman::die() {
    this->_is_alive = false;
    // TODO: Implement death animation
}

void Pacman::eat() {
    this->_score += 1;
}

void Pacman::super() {
    this->_is_super = true;
    this->_super_time = 0;
}

int Pacman::get_x() {
    return this->_x;
}

int Pacman::get_y() {
    return this->_y;
}

int Pacman::get_direction() {
    return this->_direction;
}

void Pacman::set_direction(int direction) {
    this->_direction = direction;
}

void Pacman::set_moving(bool moving) {
    this->_is_moving = moving;
}