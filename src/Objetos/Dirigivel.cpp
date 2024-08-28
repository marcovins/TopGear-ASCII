#include "Dirigivel.hpp"

int Dirigivel::cont = 0;

void Dirigivel::update() {
    if (this->getPosC() <= 1){
        this->lado = true;
        ObjetoDeJogo::update();}
    else if(this->getPosC() >= 219){
        this->lado  = false;
        ObjetoDeJogo::update();}

    if(cont % this->velocidade == 0){
        if (this->lado)
            this->moveRight(1);
        else
            this->moveLeft(1);
    }
    
}