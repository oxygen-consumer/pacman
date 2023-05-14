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
    explicit Ghost(const std::string &texture_path, const Position &pos, const std::shared_ptr<Map> &map,
                   unsigned short color) : Entity(texture_path,
                                                  pos, map),
                                           color{color} {}

    void update() override;

    void render(std::shared_ptr<sf::RenderTarget> target) override;

    [[nodiscard]] unsigned short get_color() const {
        return this->color;
    }
};


#endif //PACMAN_GHOST_HPP
