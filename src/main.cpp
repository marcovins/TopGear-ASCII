#include "Fases/Fase1.hpp"
#include "Fases/Fase2.hpp"

int main() {
    
    SpriteBuffer screen(300, 77);
    Sprite background("rsc/Fase1/jogo/background.img", COR::AZUL);
    Fase1 fase1 = Fase1(background);
    fase1.run(screen);

    /*SpriteBuffer screen(300, 77);
    Sprite background("rsc/Fase2/background/ceu.img", COR::AZUL);
    Fase2 fase2 = Fase2(background);
    fase2.run(screen);*/
  
    return 0;
}