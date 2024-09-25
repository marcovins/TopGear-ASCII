#ifndef FASE2_HPP
#define FASE2_HPP

#include <iostream>
#include <string>
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include <thread>
#include <chrono>
#include <atomic>
#include <windows.h>
#include <SFML/Audio.hpp>
#include "../Objetos/Dirigivel.hpp"
#include "../Objetos/Player.hpp"
#include "../ASCII_Engine/Fase.hpp"

class Fase2 : public Fase {
private:
    atomic<bool> flag;
    bool escape;
    SpriteBuffer screen;
    sf::Music musica;
    Sprite * gameover;
    Sprite * pontilhado;

    ObjetoDeJogo *pista;
    ObjetoDeJogo *pista_left;
    ObjetoDeJogo *pista_right;

    ObjetoDeJogo *grass;
    ObjetoDeJogo *predio_direito;
    ObjetoDeJogo *predio_esquerdo;

    Player *hero;
    Dirigivel *dirigivel;

    Enemy *enemies[3];
    

    void init();

    // Desabilita o construtor de cópia e o operador de atribuição
    Fase2(const Fase2&) = delete;
    Fase2& operator=(const Fase2&) = delete;

public:
    Fase2() : Fase("Fase - 2", Sprite("rsc/Fase2/background/ceu.img", COR::AZUL)) {this->init();};

    ~Fase2();

    void pausar(int milissegundos);

    void capturarTecla();

    int curva_esquerda(int);

    int curva_direita(int);

    unsigned run(SpriteBuffer &screen);

    void enemiesLogic()const;

    void enemyCreator();

    bool haInimigos()const;

    void gameOver();

}; 


#endif