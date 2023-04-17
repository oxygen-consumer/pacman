//
// Created by zaha on 3/5/23.
//

#include "Game.hpp"

Game::Game() {
    this->window = new sf::RenderWindow(this->video_mode, "Pacman", sf::Style::Titlebar | sf::Style::Close);
    this->window->setVerticalSyncEnabled(true);
}

Game::~Game() {
    delete this->window;
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
}

void Game::render() {
    this->window->clear(sf::Color(255, 255, 0)); // test purposes
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