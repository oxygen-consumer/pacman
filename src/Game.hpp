//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_GAME_HPP
#define PACMAN_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


/*
 * Game engine
 * Singleton WITHOUT thread safety (not needed)
 */
class Game {
private:
    // Window
    sf::RenderWindow *window;
    const sf::VideoMode video_mode{400, 600};

    Game();

    // Event handler
    void poll_events();

    void update();

    void render();

public:
    Game(Game &other) = delete;

    void operator=(const Game &other) = delete;

    ~Game();

    inline static Game &get_instance() {
        static Game instance;
        return instance;
    }

    void run();

    bool running();
};


#endif //PACMAN_GAME_HPP