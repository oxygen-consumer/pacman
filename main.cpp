#include <stdexcept>
#include <iostream>
#include "src/Game.hpp"

#ifdef __linux__

#include <X11/Xlib.h>

#endif

int main() {

#ifdef __linux__
    XInitThreads();
#endif

    try {
        Game &game = Game::get_instance();
        game.run();
    } catch (const std::exception &e) {
        std::cerr << e.what();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}