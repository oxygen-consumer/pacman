//
// Created by zaha on 14/05/23.
//

#ifndef PACMAN_INVALIDMAP_HPP
#define PACMAN_INVALIDMAP_HPP


#include <stdexcept>


class InvalidMap : public std::runtime_error {
public:
    explicit InvalidMap(const std::string &message) : std::runtime_error(message) {}
};


#endif //PACMAN_INVALIDMAP_HPP
