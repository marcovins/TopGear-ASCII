#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "enemy.hpp"
class Player : public ObjetoDeJogo{
    private:
        

    public:

        Player(std::string nome, const SpriteBase &desenho, int linha, int coluna) : ObjetoDeJogo(nome, desenho, linha, coluna) {};
        bool colideCom(const Enemy *objeto) const {
    return (
        (this->getPosC() == objeto->getPosC())
        && 
        (this->getPosL() == objeto->getPosL())
        &&
        (objeto->getActive())
    );
}


};

#endif