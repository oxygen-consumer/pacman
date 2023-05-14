//
// Created by zaha on 17/04/23.
//

#include "Entity.hpp"

void Entity::init_texture() {
    if (!this->texture.loadFromFile(this->texture_path)) {
        throw FileNotFound("Texture file not found: " + this->texture_path);
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(conf::DISPLAY_SCALE, conf::DISPLAY_SCALE);
}

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "pos: " << entity.pos;
    return os;
}
