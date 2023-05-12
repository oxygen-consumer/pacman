//
// Created by zaha on 11/05/23.
//

#ifndef PACMAN_MAP_HPP
#define PACMAN_MAP_HPP


#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include "../../../config.hpp"


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

    sf::Sprite sprite;
    sf::Texture texture;

    void init_texture(const std::string &path);

    void draw_map(sf::RenderTarget *target);

    void load_map();

public:
    Map(const std::string &texture_path);

    void update();

    void render(sf::RenderTarget *target);

    static unsigned short get_map_height();

    static unsigned short get_map_width();

    enum Cell {
        Empty,
        Wall,
        Door,
        Coin,
        PowerUp
    };
};


#endif //PACMAN_MAP_HPP
