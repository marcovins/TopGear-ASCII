#include "Game.hpp"

void Game::init(){
    this->fase1 = new Fase1();
    this->fase2 = new Fase2();
    this->menu = new Menu();
}

unsigned Game::run(SpriteBuffer &screen){

    this->screen = screen;
    
    int escolha = this->menu->run(screen);

    switch (escolha)
    {
    case 0: {
        this->fase1->run(screen);
        break;
    }
    case 1: {
        this->fase2->run(screen);
        break;
    }
    default:
        return 0;
    }

    return 0;
}
