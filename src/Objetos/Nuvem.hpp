#ifndef NUVENS_HPP
#define NUVENS_HPP

#include <string>
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"

using namespace std;

class Nuvem : public ObjetoDeJogo{
    private:
        bool lado = false;
        int velocidade;
    public:
        static int cont;
        	Nuvem(std::string nome, const SpriteBase &desenho, int linha, int coluna, int velocidade = 1) : ObjetoDeJogo(nome, desenho, linha, coluna), velocidade(velocidade) {};

        void update();

    
};


#endif