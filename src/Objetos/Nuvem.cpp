#include "Nuvem.hpp"

int Nuvem::cont = 0;

void Nuvem::update() {
    this->cont++;
    if (this->getPosC() <= 1)
        this->lado = true;
    else if(this->getPosC() >= 219)
        this->lado  = false;

    if(cont % this->velocidade == 0){
        if (this->lado)
            this->moveRight(1);
        else
            this->moveLeft(1);
    }
    
}