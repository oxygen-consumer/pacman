
//
// Created by zaha on 3/5/23.
//

#include "Game.hpp"

Game::Game() {
    this->init_window();
    this->init_map();
}

void Game::init_window() {
    this->video_mode = sf::VideoMode(conf::CELL_SIZE_SCALED * Map::get_map_width(),
                                     conf::CELL_SIZE_SCALED * Map::get_map_height());
    this->window = std::make_shared<sf::RenderWindow>(this->video_mode, "Pacman", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::init_map() {
    this->map = std::make_unique<Map>("assets/Images/Map.png");

    this->player = std::make_unique<Pacman>("assets/Images/Pacman.png", Position{9, 15});

    // TODO: Ghosts
}

bool Game::running() {
    return this->window->isOpen();
}

void Game::run() {
    while (this->running()) {
        this->update();
        this->render();
    }
}

void Game::update() {
    poll_events();

    this->map->update();

    this->player->update();
}

void Game::render() {
    this->window->clear(sf::Color(0, 0, 0)); // test purposes

    this->map->render(this->window);

    this->player->render(this->window);

    this->window->display();
}

void Game::poll_events() {
    static sf::Event ev{};

    while (this->window->pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                switch (ev.key.code) {
                    case sf::Keyboard::Escape:
                        this->window->close();
                        break;
                    default:
                        break;
                }

            default:
                break;
        }
    }
}