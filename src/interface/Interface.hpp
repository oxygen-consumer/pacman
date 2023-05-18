//
// Created by zaha on 11/05/23.
//

#ifndef PACMAN_INTERFACE_HPP
#define PACMAN_INTERFACE_HPP


#include "map/Map.hpp"


class Interface {
private:
    size_t score;
    bool paused = true;

    ResourceHolder<sf::Font, std::string> font_holder;
    sf::Text score_text;
    sf::Text pause_text;

    Interface();

public:
    static inline std::shared_ptr<Interface> get_instance() {
        static std::shared_ptr<Interface> instance(new Interface());
        return instance;
    }

    void update(bool paused_);

    void render(const std::shared_ptr<sf::RenderTarget>& target);

    void add_score(size_t score_);
};


#endif //PACMAN_INTERFACE_HPP
