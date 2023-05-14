//
// Created by zaha on 11/05/23.
//

#include "Map.hpp"

void Map::init_texture(const std::string &path) {
    if (!this->texture.loadFromFile(path)) {
        throw FileNotFound("Texture file not found: " + path);
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(conf::DISPLAY_SCALE, conf::DISPLAY_SCALE);
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

                    // I have no fucking idea how this formula works
                    sprite.setTextureRect(sf::IntRect(conf::CELL_SIZE * (down + 2 * (left + 2 * (right + 2 * up))), 0,
                                                      conf::CELL_SIZE, conf::CELL_SIZE));
                    break;
                }
                case Cell::Coin: {
                    this->sprite.setTextureRect(sf::IntRect(0, conf::CELL_SIZE, conf::CELL_SIZE, conf::CELL_SIZE));
                    break;
                }
                case Cell::PowerUp: {
                    this->sprite.setTextureRect(
                            sf::IntRect(conf::CELL_SIZE, conf::CELL_SIZE, conf::CELL_SIZE, conf::CELL_SIZE));
                    break;
                }
                case Cell::Empty: {
                    this->sprite.setTextureRect(
                            sf::IntRect(3 * conf::CELL_SIZE, conf::CELL_SIZE, conf::CELL_SIZE, conf::CELL_SIZE));
                    break;
                }
                case Cell::Door: {
                    this->sprite.setTextureRect(
                            sf::IntRect(2 * conf::CELL_SIZE, conf::CELL_SIZE, conf::CELL_SIZE, conf::CELL_SIZE));
                    break;
                }
                default: {
                    throw InvalidMap("Invalid map cell at (" + std::to_string(i) + ", " + std::to_string(j) + ")");
                }
            }

            this->sprite.setPosition(j * conf::CELL_SIZE_SCALED, i * conf::CELL_SIZE_SCALED);
            target->draw(this->sprite);
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

void Map::set_cell_empty(unsigned short x, unsigned short y) {
    this->map[y][x] = Cell::Empty;
}

bool Map::is_cell_wall(unsigned short x, unsigned short y) {
    return this->map[y][x] == Cell::Wall;
}

bool Map::is_cell_door(unsigned short x, unsigned short y) {
    return this->map[y][x] == Cell::Door;
}

bool Map::is_cell_coin(unsigned short x, unsigned short y) {
    return this->map[y][x] == Cell::Coin;
}

bool Map::is_cell_power_up(unsigned short x, unsigned short y) {
    return this->map[y][x] == Cell::PowerUp;
}