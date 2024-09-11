#include "Game/Game.hpp"

int main() {

    Game *game = new Game();
    SpriteBuffer screen(300, 77);
    game->run(screen);
}
