//
// Created by zaha on 5/16/23.
//

#ifndef PACMAN_TEXTUREHANDLER_HPP
#define PACMAN_TEXTUREHANDLER_HPP


#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "../Position.hpp"
#include "../../../config.hpp"


template<typename Identifier>
class TextureHandler : public ResourceHolder<sf::Texture, Identifier> {
private:
    std::map<Identifier, sf::Sprite> sprites;

public:
    TextureHandler() = default;

    TextureHandler(const TextureHandler &other) = delete;

    TextureHandler &operator=(const TextureHandler &other) = delete;

    ~TextureHandler() = default;

    void load(Identifier id, const std::string &path) override {
        ResourceHolder<sf::Texture, Identifier>::load(id, path);
        sf::Sprite sprite;

        sprite.setTexture(this->get(id));
        sprite.setScale(conf::DISPLAY_SCALE, conf::DISPLAY_SCALE);

        this->sprites.insert(std::make_pair(id, sprite));
    }

    void select_cell(Identifier id, size_t x, size_t y) {
        sf::Sprite &sprite = this->sprites.at(id);
        sprite.setTextureRect(sf::IntRect(x * conf::CELL_SIZE, y * conf::CELL_SIZE, conf::CELL_SIZE, conf::CELL_SIZE));
    }

    void set_position(Identifier id, const Position &pos) {
        sf::Sprite &sprite = this->sprites.at(id);
        sprite.setPosition(pos.get_x() * conf::CELL_SIZE_SCALED, pos.get_y() * conf::CELL_SIZE_SCALED);
    }

    void render(Identifier id, std::shared_ptr<sf::RenderTarget> target) {
        target->draw(this->sprites.at(id));
    }
};


#endif //PACMAN_TEXTUREHANDLER_HPP
