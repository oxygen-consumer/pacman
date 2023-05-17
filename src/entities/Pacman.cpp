//
// Created by zaha on 3/5/23.
//

#include "Pacman.hpp"

void Pacman::update() {
    if (!move(next_direction)) {
        move(current_direction);
    } else {
        current_direction = next_direction;
    }

    this->update_texture();
}

void Pacman::update_texture() {
    // select a texture based on the current direction and animation stage
    short animation_stage = this->animation_timer / conf::ANIMATION_SPEED;
    this->texture_handler.select_cell("pacman", animation_stage, current_direction);

    this->animation_timer++;
    // reset the timer when it reaches the last animation stage
    if (this->animation_timer == conf::ANIMATION_SPEED * this->animation_stages) {
        this->animation_timer = 0;
    }

    this->texture_handler.set_position("pacman", this->pos);
}

void Pacman::render(std::shared_ptr<sf::RenderTarget> target) {
    this->texture_handler.render("pacman", target);
}

void Pacman::set_direction(short direction) {
    // can't go back
    if ((this->current_direction == direction::UP && direction == direction::DOWN) ||
        (this->current_direction == direction::DOWN && direction == direction::UP) ||
        (this->current_direction == direction::LEFT && direction == direction::RIGHT) ||
        (this->current_direction == direction::RIGHT && direction == direction::LEFT)) {
        return;
    }

    this->next_direction = direction;
}

// TODO: movement in another class?
bool Pacman::move(unsigned short direction) {
    double movement_factor = 1.0 / conf::CELL_SIZE;
    Position next_pos = this->pos;

    switch (direction) {
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
        default: {
            break;
        }
    }

    // Handle teleportation
    if (next_pos.get_x() < 0) {
        next_pos.set_x(this->map->get_map_width() - 1);
    } else if (next_pos.get_x() >= this->map->get_map_width() - 1) {
        next_pos.set_x(0);
    }

    if (CollisionDetection::is_collision(next_pos, this->map)) {
        return false;
    }

    this->pos = next_pos;
    return true;
}
