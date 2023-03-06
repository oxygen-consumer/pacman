//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_LEVELINTERFACE_HPP
#define PACMAN_LEVELINTERFACE_HPP

#include <utility>
#include <vector>
#include <string>


class LevelInterface {
public:
    // Every level should return a pair containing the map and the size of it
    // The map is a vector of strings, each string is a row of the map
    // The size is a pair of ints, the first is the width and the second is the height
    virtual std::pair<std::vector<std::string>, std::pair<int, int>> get_map() = 0;

    /*
     * Map specification:
     * # means wall
     * . means coin
     * o means big coin
     * P means pacman
     * int means ghost of that color
     * space means empty
     * = means wall that can be passed through only by ghosts
     */
};


#endif //PACMAN_LEVELINTERFACE_HPP
