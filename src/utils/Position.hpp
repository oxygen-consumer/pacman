//
// Created by zaha on 12/05/23.
//

#ifndef PACMAN_POSITION_HPP
#define PACMAN_POSITION_HPP


#include <ostream>

class Position {
private:
    unsigned short x, y;

public:
    explicit Position() {
        this->x = 0;
        this->y = 0;
    }

    explicit Position(unsigned short x, unsigned short y) : x{x}, y{y} {}

    [[nodiscard]] unsigned short get_x() const {
        return this->x;
    }

    void set_x(unsigned short x_) {
        this->x = x_;
    }

    void set_y(unsigned short y_) {
        this->y = y_;
    }

    [[nodiscard]] unsigned short get_y() const {
        return this->y;
    };

    Position(const Position &position) {
        this->x = position.x;
        this->y = position.y;
    }

    Position &operator=(const Position &position) = default;

    friend bool operator==(const Position &lhs, const Position &rhs) {
        return lhs.x == rhs.x &&
               lhs.y == rhs.y;
    }

    friend bool operator!=(const Position &lhs, const Position &rhs) {
        return !(rhs == lhs);
    }

    ~Position() = default;

    friend std::ostream &operator<<(std::ostream &os, const Position &position) {
        os << "x: " << position.x << " y: " << position.y;
        return os;
    }
};


#endif //PACMAN_POSITION_HPP