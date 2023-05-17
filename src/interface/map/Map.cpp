//
// Created by zaha on 11/05/23.
//

#include "Map.hpp"

void Map::init_texture(const std::string &path) {
    this->texture_handler.load("map", path);
}

void Map::draw_map(std::shared_ptr<sf::RenderTarget> target) {
    for (size_t i = 0; i < MAP_HEIGHT; ++i) {
        for (size_t j = 0; j < MAP_WIDTH; ++j) {
            switch (this->map[i][j]) {
                case Cell::Wall: {
                    bool up = i > 0 && this->map[i - 1][j] == Cell::Wall;
                    bool down = i < MAP_HEIGHT - 1 && this->map[i + 1][j] == Cell::Wall;
                    bool left = j > 0 && this->map[i][j - 1] == Cell::Wall;
                    bool right = j < MAP_WIDTH - 1 && this->map[i][j + 1] == Cell::Wall;

                    this->texture_handler.select_cell("map", down + 2 * (left + 2 * (right + 2 * up)), 0);
                    break;
                }
                case Cell::Coin: {
                    this->texture_handler.select_cell("map", 0, 1);
                    break;
                }
                case Cell::PowerUp: {
                    this->texture_handler.select_cell("map", 1, 1);
                    break;
                }
                case Cell::Empty: {
                    this->texture_handler.select_cell("map", 3, 1);
                    break;
                }
                case Cell::Door: {
                    this->texture_handler.select_cell("map", 2, 1);
                    break;
                }
                default: {
                    throw InvalidMap("Invalid map cell at (" + std::to_string(i) + ", " + std::to_string(j) + ")");
                }
            }

            this->texture_handler.set_position("map", Position{static_cast<double>(j), static_cast<double>(i)});
            this->texture_handler.render("map", target);
        }
    }
}

Map::Map(const std::string &texture_path) {
    this->init_texture(texture_path);

    this->load_map();
}

void Map::update() {

}

void Map::render(std::shared_ptr<sf::RenderTarget> target) {
    this->draw_map(target);
}

void Map::load_map() {
    for (size_t i = 0; i < MAP_HEIGHT; ++i) {
        for (size_t j = 0; j < MAP_WIDTH; ++j) {
            switch (this->map_default[i][j]) {
                case '#': {
                    this->map[i][j] = Cell::Wall;
                    break;
                }
                case '.': {
                    this->map[i][j] = Cell::Coin;
                    break;
                }
                case 'o': {
                    this->map[i][j] = Cell::PowerUp;
                    break;
                }
                case ' ': {
                    this->map[i][j] = Cell::Empty;
                    break;
                }
                case '=': {
                    this->map[i][j] = Cell::Door;
                    break;
                }
                default: {
                    throw InvalidMap("Invalid map cell at (" + std::to_string(i) + ", " + std::to_string(j) + ")");
                }
            }
        }
    }
}

unsigned short Map::get_map_height() {
    return MAP_HEIGHT;
}

unsigned short Map::get_map_width() {
    return MAP_WIDTH;
}

//void Map::set_cell_empty(unsigned short x, unsigned short y) {
//    this->map[y][x] = Cell::Empty;
//}

bool Map::is_cell_wall(unsigned short x, unsigned short y) {
    return this->map[y][x] == Cell::Wall;
}

bool Map::is_cell_door(unsigned short x, unsigned short y) {
    return this->map[y][x] == Cell::Door;
}

//bool Map::is_cell_coin(unsigned short x, unsigned short y) {
//    return this->map[y][x] == Cell::Coin;
//}

//bool Map::is_cell_power_up(unsigned short x, unsigned short y) {
//    return this->map[y][x] == Cell::PowerUp;
//}