//
// Created by zaha on 17/04/23.
//

#include "Entity.hpp"

void Entity::init_texture(const std::string &path) {
    if (!this->texture.loadFromFile(path)) {
        // TODO: throw custom exception
        throw std::runtime_error("Could not load texture from " + path);
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(conf::DISPLAY_SCALE, conf::DISPLAY_SCALE);
}