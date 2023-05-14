//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_PACMAN_HPP
#define PACMAN_PACMAN_HPP


#include "Entity.hpp"


class Pacman : Entity {
private:
    // animation stuff
    short animation_timer;
    const short animation_stages = 6;
    // this will be used later
    // const short death_animation_stages = 12;

    short current_direction;

public:
    explicit Pacman(const std::string &texture_path, const Position &pos) : Entity(texture_path, pos) {
        this->animation_timer = 0;

        this->current_direction = direction::RIGHT;
    }

    void update() override;

    void render(std::shared_ptr<sf::RenderTarget> target) override;

    void set_direction(short direction);

    void move();
};


#endif //PACMAN_PACMAN_HPP
