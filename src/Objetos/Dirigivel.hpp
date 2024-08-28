#ifndef DIRIGIVEL_HPP
#define DIRIGIVEL_HPP

#include <string>
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"

using namespace std;

class Dirigivel : public ObjetoDeJogo{
    private:
        bool lado = false;
        int velocidade;
    public:
            static int cont;
        	Dirigivel(std::string nome, const SpriteBase &desenho, int linha, int coluna, int velocidade = 1) : ObjetoDeJogo(nome, desenho, linha, coluna), velocidade(velocidade) {};

        void update();

    
};


#endif