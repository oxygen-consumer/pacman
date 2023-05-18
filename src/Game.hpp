//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_GAME_HPP
#define PACMAN_GAME_HPP


#include "entities/Pacman.hpp"


class Game {
private:
    bool paused = true;

    // Window
    std::shared_ptr<sf::RenderWindow> window;
    sf::VideoMode video_mode{};

    void init_window();

    // Entities
    std::shared_ptr<Pacman> player;

    // Map
    std::shared_ptr<Map> map;
    std::shared_ptr<Interface> interface;

    void init_objects();

    Game();

    // Event handler
    void poll_events();

    // TODO: move update and render to a separate class?
    void update();

    void render();

public:
    Game(Game &other) = delete;

    void operator=(const Game &other) = delete;

    ~Game() = default;

    inline static Game &get_instance() {
        static Game instance;
        return instance;
    }

    void run();

    bool running();
};


#endif //PACMAN_GAME_HPP