//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_GAME_HPP
#define PACMAN_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "entities/Pacman.hpp"
#include "interface/map/Map.hpp"


/*
 * Game engine
 * Singleton WITHOUT thread safety (not needed)
 */
class Game {
private:
    // Window
    std::shared_ptr<sf::RenderWindow> window;
    sf::VideoMode video_mode{};

    void init_window();

    // Entities
    std::unique_ptr<Pacman> player;

    // Map
    std::shared_ptr<Map> map;

    void init_map();

    Game();

    // Event handler
    void poll_events();

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