//
// Created by zaha on 17/04/23.
//

#ifndef PACMAN_ENTITY_HPP
#define PACMAN_ENTITY_HPP


#include <SFML/Graphics.hpp>
#include "../../config.hpp"
#include "../utils/Position.hpp"


class Entity {
protected:
    sf::Sprite sprite;
    sf::Texture texture;

    Position pos;

    void init_texture(const std::string &path);

    enum direction {
        RIGHT,
        UP,
        LEFT,
        DOWN
    };

public:
    virtual void update() = 0;

    virtual void render(sf::RenderTarget *target) = 0;
};


#endif //PACMAN_ENTITY_HPP
