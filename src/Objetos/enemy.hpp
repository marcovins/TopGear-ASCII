#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include <windows.h>


class Enemy : public ObjetoDeJogo{
    private:
        int cont = 0;

    public:

        Enemy(std::string nome, const SpriteBase &desenho, int linha, int coluna) : ObjetoDeJogo(nome, desenho, linha, coluna) {};


        void update();
};     

#endif