#ifndef GAME_HPP
#define GAME_HPP

#include "../ASCII_Engine/Fase.hpp"
#include "../Fases/Fase1.hpp"
#include "../Fases/Fase2.hpp"
#include "../Fases/Menu.hpp"

class Game : public Fase{

    private:

        SpriteBuffer screen;
        Fase1 *fase1;
        Fase2 *fase2;
        Menu *menu;

        int estado;

        void init();

    // Desabilita o construtor de cópia e o operador de atribuição
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;

    public:
    
        Game() : Fase("Game", Sprite("rsc/Game/Gamebackground.img", COR::PADRAO)) {this->init();} 

        ~Game();

        void pausar(int milissegundos);

        unsigned run(SpriteBuffer &screen);

};


#endif