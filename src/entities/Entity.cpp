//
// Created by zaha on 17/04/23.
//

#include "Entity.hpp"

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "pos: " << entity.pos;
    return os;
}
