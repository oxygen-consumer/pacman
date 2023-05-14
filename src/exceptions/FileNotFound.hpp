//
// Created by zaha on 14/05/23.
//

#ifndef PACMAN_FILENOTFOUND_HPP
#define PACMAN_FILENOTFOUND_HPP


#include <stdexcept>


class FileNotFound : public std::runtime_error {
public:
    explicit FileNotFound(const std::string &message) : std::runtime_error(message) {}
};


#endif //PACMAN_FILENOTFOUND_HPP
