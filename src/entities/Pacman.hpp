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
    [[maybe_unused]] const short death_animation_stages = 12;

    short current_direction;

public:
    explicit Pacman(const std::string &texture_path);

    void update() override;

    void render(sf::RenderTarget *target) override;

};


#endif //PACMAN_PACMAN_HPP
