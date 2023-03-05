//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_GAME_HPP
#define PACMAN_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


/*
 * Singleton class which runs the game
 * TODO: Make it thread safe
 */
class Game {
private:
    static Game *_instance;

    sf::RenderWindow *_window;
    sf::VideoMode _video_mode;
    sf::Event _ev{};

    Game();

public:
    Game(Game &other) = delete;

    void operator=(const Game &other) = delete;

    ~Game();

    static Game *get_instance();

    void run();
};


#endif //PACMAN_GAME_HPP
