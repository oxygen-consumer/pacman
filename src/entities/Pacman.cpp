//
// Created by zaha on 3/5/23.
//

#include "Pacman.hpp"

Pacman::Pacman(const std::string &texture_path) {
    this->init_texture(texture_path);

    this->animation_timer = 0;

    this->current_direction = direction::RIGHT;

    this->pos.set_x(9);
    this->pos.set_y(15);
}

void Pacman::update() {
    // select a texture based on the current direction and animation stage
    short animation_stage = this->animation_timer / conf::ANIMATION_SPEED;
    this->sprite.setTextureRect(
            sf::IntRect(animation_stage * conf::CELL_SIZE, current_direction * conf::CELL_SIZE, conf::CELL_SIZE,
                        conf::CELL_SIZE));

    this->animation_timer++;
    // reset the timer when it reaches the last animation stage
    if (this->animation_timer == conf::ANIMATION_SPEED * this->animation_stages) {
        this->animation_timer = 0;
    }

    this->sprite.setPosition(this->pos.get_x() * conf::CELL_SIZE_SCALED, this->pos.get_y() * conf::CELL_SIZE_SCALED);
}

void Pacman::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
}
