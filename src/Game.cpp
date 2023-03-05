//
// Created by zaha on 3/5/23.
//

#include "Game.hpp"

Game *Game::_instance = nullptr;

Game *Game::get_instance() {
    if (_instance == nullptr) {
        _instance = new Game;
    }

    return _instance;
}

Game::Game() {
    // TODO: This should not be hardcoded like this
    this->_video_mode.height = 600;
    this->_video_mode.width = 400;

    this->_window = new sf::RenderWindow(this->_video_mode, "Pacman", sf::Style::Titlebar | sf::Style::Close);
    this->_window->setVerticalSyncEnabled(true);
}

Game::~Game() {
    delete this->_window;
}

void Game::run() {
    while (this->_window->isOpen()) {
        while (this->_window->pollEvent(this->_ev)) {
            switch (this->_ev.type) {
                case sf::Event::Closed:
                    this->_window->close();
                    break;
                case sf::Event::KeyPressed:
                    switch (this->_ev.key.code) {
                        case sf::Keyboard::Escape:
                            this->_window->close();
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
    }
}
