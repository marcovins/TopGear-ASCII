#include <iostream>
#include <memory>
#include "Game/Game.hpp"

int main() {
    try {

        auto game = std::make_unique<Game>();

        SpriteBuffer screen(300, 77);

        game->run(screen);
    } catch (const std::exception &e) {
        std::cerr << "Ocorreu um erro: " << e.what() << std::endl;
        return -1;
    } catch (...) {
        std::cerr << "Ocorreu um erro desconhecido." << std::endl;
        return -1;
    }

    return 0;  
}
