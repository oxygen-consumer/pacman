//
// Created by zaha on 11/05/23.
//

#include "Interface.hpp"

Interface::Interface() : score(0) {
    this->font_holder.load("font", "assets/Fonts/PublicPixel.ttf");

    this->score_text.setFont(this->font_holder.get("font"));
    this->score_text.setCharacterSize(conf::CELL_SIZE_SCALED);
    this->score_text.setPosition(0, Map::get_map_height() * conf::CELL_SIZE_SCALED);

    this->pause_text.setFont(this->font_holder.get("font"));
    this->pause_text.setCharacterSize(conf::CELL_SIZE_SCALED);
    this->pause_text.setString("Paused");
    this->pause_text.setPosition(
            (Map::get_map_width() - this->pause_text.getString().getSize()) * conf::CELL_SIZE_SCALED ,
            Map::get_map_height() * conf::CELL_SIZE_SCALED);
}

void Interface::update(bool paused_) {
    this->score_text.setString("Score: " + std::to_string(this->score));
    this->paused = paused_;
}

void Interface::render(const std::shared_ptr<sf::RenderTarget> &target) {
    target->draw(this->score_text);
    if (this->paused) {
        target->draw(this->pause_text);
    }
}

void Interface::add_score(size_t score_) {
    this->score += score_;
}