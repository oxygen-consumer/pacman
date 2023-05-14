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

    unsigned short current_direction;
    unsigned short next_direction;

    // Returns true if the move was successful
    bool move(unsigned short direction);

public:
    explicit Pacman(const std::string &texture_path, const Position &pos, const std::shared_ptr<Map>& map) : Entity(texture_path, pos, map) {
        this->animation_timer = 0;

        this->current_direction = direction::DOWN;
        this->next_direction = direction::DOWN;

        this->update_texture();
    }

    void update() override;

    void update_texture();

    void render(std::shared_ptr<sf::RenderTarget> target) override;

    void set_direction(short direction);
};


#endif //PACMAN_PACMAN_HPP
