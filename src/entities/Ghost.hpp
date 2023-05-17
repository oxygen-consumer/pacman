//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_GHOST_HPP
#define PACMAN_GHOST_HPP

#include <utility>
#include "Entity.hpp"

class Ghost : Entity {
private:
    unsigned short color;

public:
    explicit Ghost(const std::string &texture_path, const Position &pos, unsigned short color) :
            Entity(texture_path, pos), color{color} {}

    void update() override;

    // Will be implemented later
    void render(std::shared_ptr<sf::RenderTarget> target) override = 0;

    [[nodiscard]] unsigned short get_color() const {
        return this->color;
    }
};


#endif //PACMAN_GHOST_HPP
