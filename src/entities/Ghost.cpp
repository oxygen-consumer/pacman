//
// Created by zaha on 3/5/23.
//

#include "Ghost.hpp"

void Ghost::update() {
    // TODO
}

void Ghost::render(std::shared_ptr<sf::RenderTarget> target) {
    target->draw(this->sprite);
}