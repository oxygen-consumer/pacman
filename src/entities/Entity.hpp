//
// Created by zaha on 17/04/23.
//

#ifndef PACMAN_ENTITY_HPP
#define PACMAN_ENTITY_HPP


#include <SFML/Graphics.hpp>
#include <ostream>
#include "../../config.hpp"
#include "../utils/Position.hpp"


class Entity {
protected:
    sf::Sprite sprite;
    sf::Texture texture;

    Position pos;

    std::string texture_path;

    void init_texture();

    enum direction {
        RIGHT,
        UP,
        LEFT,
        DOWN
    };

public:
    Entity(const std::string &texture_path, const Position &pos) : pos(pos), texture_path(texture_path) {
        this->init_texture();
    }

    virtual void update() = 0;

    virtual void render(sf::RenderTarget *target) = 0;

    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);
};


#endif //PACMAN_ENTITY_HPP
