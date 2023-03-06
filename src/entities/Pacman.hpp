//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_PACMAN_HPP
#define PACMAN_PACMAN_HPP


/*
 * This is very basic, just a skeleton for now
 * This will be used to render and manage pacman
 * TODO: Delete this shit and implement it properly
 */
class Pacman {
private:
    int _x;
    int _y;
    int _score;

    bool _is_alive;
    bool _is_super;
    bool _is_moving;

    int _direction;
    int _speed;
    int _super_time;

public:
    Pacman(int x, int y);
    ~Pacman() = default;

    void die();
    void eat();
    void super();

    int get_x();
    int get_y();

    int get_direction();
    void set_direction(int direction);
    void set_moving(bool moving);

    /*
     * TODO: I need some method to move pacman, same for ghosts
     *
     * Maybe a move method called by the game loop?
     * It would check for collisions and stuff for pacman
     * and implement the AI for ghosts
     *
     * Either that or I would do everything in the game engine
     * and these classes would just be data containers
     * except for the ghost AI
     *
     * Idk how to do this yet, I need to learn SFML better
     *
     * Also I should implement an interface for these classes
    */
};


#endif //PACMAN_PACMAN_HPP
