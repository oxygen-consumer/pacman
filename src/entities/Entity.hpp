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
#include "../utils/resource_holders/TextureHandler.hpp"


class Entity {
protected:
    TextureHandler<std::string> texture_handler;

    Position pos;
    std::shared_ptr<Map> map;

    std::string texture_path;

public:
    Entity(std::string texture_path, const Position &pos, const std::shared_ptr<Map> &map) : pos{pos}, map{map},
                                                                                             texture_path{std::move(
                                                                                                     texture_path)} {}

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
