
//
// Created by zaha on 3/5/23.
//

#include "Game.hpp"

Game::Game() {
    this->init_window();
    this->init_objects();
}

void Game::init_window() {
    this->video_mode = sf::VideoMode(conf::CELL_SIZE_SCALED * Map::get_map_width(),
                                     conf::CELL_SIZE_SCALED * (Map::get_map_height() + 1));
    this->window = std::make_shared<sf::RenderWindow>(this->video_mode, "Pacman",
                                                      sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(conf::FPS);
    this->window->setVerticalSyncEnabled(false);
}

void Game::init_objects() {
    this->map = Map::get_instance();
    this->interface = Interface::get_instance();

    this->player = Pacman::get_instance();

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

    this->interface->update(this->paused);

    if (paused) {
        return;
    }

    this->map->update();

    this->player->update();
}

void Game::render() {
    this->window->clear(sf::Color(0, 0, 0));

    this->map->render(this->window);
    this->interface->render(this->window);

    this->player->render(this->window);

    this->window->display();
}

// TODO: move this to a separate class
void Game::poll_events() {
    static sf::Event ev{};

    while (this->window->pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::Closed: {
                this->window->close();
                break;
            }

            case sf::Event::KeyPressed: {
                switch (ev.key.code) {
                    // quit the game
                    case sf::Keyboard::Escape: {
                        this->window->close();
                        break;
                    }

                    // pause the game
                    case sf::Keyboard::P: {
                        paused = !paused;
                        break;
                    }

                    // move the player
                    case sf::Keyboard::Up:
                    case sf::Keyboard::W: {
                        this->player->set_direction(Entity::direction::UP);
                        paused = false;
                        break;
                    }
                    case sf::Keyboard::Down:
                    case sf::Keyboard::S: {
                        this->player->set_direction(Entity::direction::DOWN);
                        paused = false;
                        break;
                    }
                    case sf::Keyboard::Left:
                    case sf::Keyboard::A: {
                        this->player->set_direction(Entity::direction::LEFT);
                        paused = false;
                        break;
                    }
                    case sf::Keyboard::Right:
                    case sf::Keyboard::D: {
                        this->player->set_direction(Entity::direction::RIGHT);
                        paused = false;
                        break;
                    }

                    // unknown key
                    default: {
                        break;
                    }
                }
            }

            default: {
                break;
            }
        }
    }
}