//
// Created by zaha on 11/05/23.
//

#ifndef PACMAN_MAP_HPP
#define PACMAN_MAP_HPP


#include <array>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../../config.hpp"
#include "../../utils/exceptions/FileNotFound.hpp"
#include "../../utils/exceptions/InvalidMap.hpp"
#include "../../utils/Position.hpp"
#include "../../utils/resource_holders/TextureHandler.hpp"


class Map {
private:
    static constexpr size_t MAP_WIDTH = 19;
    static constexpr size_t MAP_HEIGHT = 21;
    std::array<std::array<unsigned short, MAP_WIDTH>, MAP_HEIGHT> map;

    const std::array<std::string, MAP_HEIGHT> map_default = {
            "###################",
            "#........#........#",
            "#o##.###.#.###.##o#",
            "#.................#",
            "#.##.#.#####.#.##.#",
            "#....#...#...#....#",
            "####.### # ###.####",
            "   #.#       #.#   ",
            "####.# ##=## #.####",
            "    .  #   #  .    ",
            "####.# ##### #.####",
            "   #.#       #.#   ",
            "####.# ##### #.####",
            "#........#........#",
            "#.##.###.#.###.##.#",
            "#o.#..... .....#.o#",
            "##.#.#.#####.#.#.##",
            "#....#...#...#....#",
            "#.######.#.######.#",
            "#.................#",
            "###################"
    };

    /*
    sf::Sprite sprite;
    sf::Texture texture;
     */
    TextureHandler<std::string> texture_handler;

    void init_texture(const std::string &path);

    void draw_map(std::shared_ptr<sf::RenderTarget> target);

    void load_map();

    explicit Map(const std::string &texture_path);

public:
    inline static std::shared_ptr<Map> &get_instance() {
        static std::shared_ptr<Map> instance(new Map("assets/Images/Map.png"));
        return instance;
    }

    void update();

    void render(std::shared_ptr<sf::RenderTarget> target);

    static unsigned short get_map_height();

    static unsigned short get_map_width();

    enum Cell {
        Empty,
        Wall,
        Door,
        Coin,
        PowerUp
    };

    // void set_cell_empty(unsigned short x, unsigned short y);

    bool is_cell_wall(unsigned short x, unsigned short y);

    bool is_cell_door(unsigned short x, unsigned short y);

    // bool is_cell_coin(unsigned short x, unsigned short y);

    // bool is_cell_power_up(unsigned short x, unsigned short y);
};


#endif //PACMAN_MAP_HPP
