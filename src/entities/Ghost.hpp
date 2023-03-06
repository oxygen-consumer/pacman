//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_GHOST_HPP
#define PACMAN_GHOST_HPP

#include <utility>
#include <ostream>

/*
 * This is very basic, just a skeleton for now
 * This will be used to render and manage ghosts
 * TODO: Delete this shit and implement properly
 * TODO: Enum for ghost colors
 */
class Ghost {
private:
    int _color;
    int _x;
    int _y;

    std::pair<int, int> _target;

public:
    Ghost(int color, int x, int y);
    ~Ghost();

    // cc and =
    Ghost(const Ghost &other);
    Ghost &operator=(const Ghost &other);

    void move();
    void die();

    int get_x();
    int get_y();

    // << operator cos idk where else to put it (send help)
    friend std::ostream &operator<<(std::ostream &os, const Ghost &ghost);
};


#endif //PACMAN_GHOST_HPP
