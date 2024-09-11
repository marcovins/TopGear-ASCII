#include "Game.hpp"

void Game::init() {
    this->fase1 = new Fase1();
    this->fase2 = new Fase2();
    this->menu = new Menu();
    this->estado = Fase::MENU; // Ajuste se `Fase::MENU` for o enum correto
}

unsigned Game::run(SpriteBuffer &screen) {
    this->screen = screen;

    while (this->estado != Fase::END_GAME) {
        int escolha = this->menu->run(screen);

        switch (escolha) {
        case 0:
            this->estado = Fase::LEVEL_1;
            if (this->fase1) {
                this->fase1->run(screen);
            }
            break;

        case 1:
            this->estado = Fase::LEVEL_2;
            if (this->fase2) {
                this->fase2->run(screen);
            }
            break;

        default:
            this->estado = Fase::END_GAME;
            return 0;
        }

        this->update();

    }

    return 0;
}
