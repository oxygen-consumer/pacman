//
// Created by zaha on 3/5/23.
//

#include "Pacman.hpp"

void Pacman::update() {
    move();

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

void Pacman::render(std::shared_ptr<sf::RenderTarget> target) {
    target->draw(this->sprite);
}

void Pacman::set_direction(short direction) {
    // can't go back
    if ((this->current_direction == direction::UP && direction == direction::DOWN) ||
        (this->current_direction == direction::DOWN && direction == direction::UP) ||
        (this->current_direction == direction::LEFT && direction == direction::RIGHT) ||
        (this->current_direction == direction::RIGHT && direction == direction::LEFT)) {
        return;
    }

    // TODO: call collision detection here

    this->current_direction = direction;
}

void Pacman::move() {
    double movement_factor = 1.0 / conf::CELL_SIZE;
    Position next_pos = this->pos;

    switch (this->current_direction) {
        case direction::UP: {
            next_pos.set_y(this->pos.get_y() - movement_factor);
            break;
        }
        case direction::DOWN: {
            next_pos.set_y(this->pos.get_y() + movement_factor);
            break;
        }
        case direction::LEFT: {
            next_pos.set_x(this->pos.get_x() - movement_factor);
            break;
        }
        case direction::RIGHT: {
            next_pos.set_x(this->pos.get_x() + movement_factor);
            break;
        }
    }

    if (CollisionDetection::is_collision(next_pos, this->map)) {
        return;
    }

    this->pos = next_pos;
}