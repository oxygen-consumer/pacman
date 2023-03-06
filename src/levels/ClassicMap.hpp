//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_CLASSICMAP_HPP
#define PACMAN_CLASSICMAP_HPP

#include "LevelInterface.hpp"
#include <utility>
#include <vector>
#include <string>


class ClassicMap : public LevelInterface {
private:
    std::vector<std::string> _map;
    std::pair<int, int> _size;

public:
    ClassicMap();
    ~ClassicMap();

    std::pair<std::vector<std::string>, std::pair<int, int>> get_map() override;
};


#endif //PACMAN_CLASSICMAP_HPP
