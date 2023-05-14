//
// Created by zaha on 17/04/23.
//

#ifndef PACMAN_ENTITY_HPP
#define PACMAN_ENTITY_HPP


#include <SFML/Graphics.hpp>
#include <ostream>
#include <utility>
#include <memory>
#include "../../config.hpp"
#include "../utils/Position.hpp"
#include "../utils/exceptions/FileNotFound.hpp"
#include "../interface/map/Map.hpp"
#include "../interface/map/CollisionDetection.hpp"


class Entity {
protected:
    sf::Sprite sprite;
    sf::Texture texture;

    Position pos;
    std::shared_ptr<Map> map;

    std::string texture_path;

    void init_texture();

public:
    Entity(std::string texture_path, const Position &pos, const std::shared_ptr<Map> &map) : pos{pos}, map{map},
                                                                                             texture_path{std::move(
                                                                                                     texture_path)} {
        this->init_texture();
    }

    virtual void update() = 0;

    virtual void render(std::shared_ptr<sf::RenderTarget> target) = 0;

    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);

    virtual ~Entity() = default;

    enum direction {
        RIGHT,
        UP,
        LEFT,
        DOWN
    };
};


#endif //PACMAN_ENTITY_HPP
