//
// Created by zaha on 11/05/23.
//

#ifndef PACMAN_CONFIG_HPP
#define PACMAN_CONFIG_HPP


namespace conf {
    // Settings
    constexpr unsigned short DISPLAY_SCALE = 5; // adjust this to change the size of the window, I have a 4k monitor
    constexpr unsigned short FPS = 60; // this will also affect the speed of the game
    constexpr unsigned short ANIMATION_SPEED = 10; // lower is faster, based on FPS

    // DON'T CHANGE THESE
    constexpr unsigned short CELL_SIZE = 16;
    constexpr unsigned short CELL_SIZE_SCALED = CELL_SIZE * DISPLAY_SCALE; // not sure if needed
}


#endif //PACMAN_CONFIG_HPP
