//
// Created by zaha on 14/05/23.
//

#ifndef PACMAN_COLLISIONDETECTION_HPP
#define PACMAN_COLLISIONDETECTION_HPP


#include <cmath>
#include "Map.hpp"
#include "../../entities/Entity.hpp"
#include "../../utils/Position.hpp"
#include "../../../config.hpp"


class CollisionDetection {
public:
    static bool
    is_collision(const Position &position, const std::shared_ptr<Map> &map, bool is_ghost = false) {
        // check for collision with walls
        for (size_t i = 0; i < 4; ++i) {
            short x = 0, y = 0;

            switch (i) {
                case 0: { // Top left
                    x = std::floor(position.get_x());
                    y = std::floor(position.get_y());
                    break;
                }
                case 1: { // Top right
                    x = std::ceil(position.get_x());
                    y = std::floor(position.get_y());
                    break;
                }
                case 2: { // Bottom left
                    x = std::floor(position.get_x());
                    y = std::ceil(position.get_y());
                    break;
                }
                case 3: { // Bottom right
                    x = std::ceil(position.get_x());
                    y = std::ceil(position.get_y());
                    break;
                }
                default: {
                    break;
                }
            }

            // Make sure position is within map bounds
            if (x < 0 || x >= map->get_map_width() || y < 0 || y >= map->get_map_height()) {
                return true;
            }

            if (map->is_cell_wall(x, y) || (!is_ghost && map->is_cell_door(x, y))) {
                return true;
            }
        }

        return false;
    }
};


#endif //PACMAN_COLLISIONDETECTION_HPP
