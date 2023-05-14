
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
    this->window->setFramerateLimit(conf::FPS);
    this->window->setVerticalSyncEnabled(false);
}

void Game::init_map() {
    this->map = std::make_shared<Map>("assets/Images/Map.png");

    this->player = std::make_unique<Pacman>("assets/Images/Pacman.png", Position{9, 15}, this->map);

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
                    // quit the game
                    case sf::Keyboard::Escape: {
                        this->window->close();
                        break;
                    }
                    // pause the game
                    case sf::Keyboard::P: {
                        // TODO
                        break;
                    }

                    // move the player
                    case sf::Keyboard::Up: {
                        this->player->set_direction(Entity::direction::UP);
                        break;
                    }
                    case sf::Keyboard::Down: {
                        this->player->set_direction(Entity::direction::DOWN);
                        break;
                    }
                    case sf::Keyboard::Left: {
                        this->player->set_direction(Entity::direction::LEFT);
                        break;
                    }
                    case sf::Keyboard::Right: {
                        this->player->set_direction(Entity::direction::RIGHT);
                        break;
                    }

                    default: {
                        break;
                    }
                }

            default:
                break;
        }
    }
}