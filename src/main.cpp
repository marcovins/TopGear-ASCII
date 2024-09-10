#include <iostream>
#include "Fases/Fase1.hpp"
#include "Fases/Fase2.hpp"
#include "Fases/Menu.hpp"

int main() {

    SpriteBuffer screen(300, 77);
    Sprite background("rsc/Menu/background.img", COR::VERMELHA);
    Menu menu = Menu(background);
    int escolha = menu.run(screen);

    switch (escolha)
    {
    case 0: {
        Sprite backgroundFase1("rsc/Fase1/jogo/background.img", COR::AZUL);
        Fase1 fase1 = Fase1(backgroundFase1);
        fase1.run(screen);
        break;
    }
    case 1: {
        Sprite backgroundFase2("rsc/Fase2/background/ceu.img", COR::AZUL);
        Fase2 fase2 = Fase2(backgroundFase2);
        fase2.run(screen);
        break;
    }
    default:
        return 0;
    }

    return 0;
}
