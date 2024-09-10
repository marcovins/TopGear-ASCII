#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Random.hpp"

using namespace std;

class Enemy : public ObjetoDeJogo{
    private:
        bool activeDerivada;
    public:

        Enemy(std::string nome, const SpriteBase &desenho, int linha, int coluna, int anim = 0) : ObjetoDeJogo(nome, desenho, linha, coluna), activeDerivada(false) {};

        virtual ~Enemy(){};

        inline int getActive() const {return this->activeDerivada; }

        inline void desativarEnemy() {
            this->activeDerivada = false;
            this->desativarObj();
        }

        inline void ativarEnemy(){
            this->activeDerivada = true;
            this->ativarObj();
        }
};     

#endif