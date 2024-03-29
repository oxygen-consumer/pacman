//
// Created by zaha on 3/5/23.
//

#ifndef PACMAN_PACMAN_HPP
#define PACMAN_PACMAN_HPP


#include "Entity.hpp"
#include "../interface/Interface.hpp"


class Pacman : Entity {
private:
    std::shared_ptr<Interface> interface;

    // animation stuff
    short animation_timer;
    const short animation_stages = 6;
    // this will be used later
    // const short death_animation_stages = 12;

    unsigned short current_direction;
    unsigned short next_direction;

    // Returns true if the move was successful
    bool move(unsigned short direction);

    explicit Pacman(const std::string &texture_path, const Position &pos) : Entity(texture_path, pos) {
        this->texture_handler.load("pacman", this->texture_path);

        this->animation_timer = 0;

        this->current_direction = direction::DOWN;
        this->next_direction = direction::DOWN;

        this->update_texture();

        this->interface = Interface::get_instance();
    }

public:
    inline static std::shared_ptr<Pacman> get_instance() {
        static std::shared_ptr<Pacman> instance(new Pacman("assets/Images/Pacman.png", Position{9, 15}));
        return instance;
    }

    void update() override;

    void update_texture();

    void render(std::shared_ptr<sf::RenderTarget> target) override;

    void set_direction(short direction);
};


#endif //PACMAN_PACMAN_HPP
