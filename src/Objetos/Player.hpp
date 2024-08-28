#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

class Player : public ObjetoDeJogo{
    private:
        

    public:

        Player(std::string nome, const SpriteBase &desenho, int linha, int coluna) : ObjetoDeJogo(nome, desenho, linha, coluna) {};

};     

#endif