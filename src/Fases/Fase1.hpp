#ifndef FASE1_HPP
#define FASE1_HPP

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <atomic>
#include <windows.h>
#include <SFML/Audio.hpp>
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/TextSprite.hpp"
#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/Fase.hpp"
#include "../Objetos/Nuvem.hpp"
#include "../Objetos/Player.hpp"
#include "../objetos/enemy.hpp"
#include "../objetos/Random.hpp"

class Fase1 : public Fase {
private:
    atomic<bool> flag;
    bool escape;
    SpriteBuffer screen;
    sf::Music musica;
    Sprite * gameover;
    Sprite * pontilhado;
    // Montanhas
    ObjetoDeJogo *montanha_direita;
    ObjetoDeJogo *montanha_esquerda;
    ObjetoDeJogo *montanha_esquerda_curva_esquerda;
    ObjetoDeJogo *montanha_esquerda_curva_direita;
    ObjetoDeJogo *montanha_direita_curva_esquerda;
    ObjetoDeJogo *montanha_direita_curva_direita;

    // Pistas
    ObjetoDeJogo *pista;
    ObjetoDeJogo *pista_left;
    ObjetoDeJogo *pista_right;
    ObjetoDeJogo *grass;


    Player *hero;
    Enemy *enemies[3];

    // Nuvens
    Nuvem *nuvem1;
    Nuvem *nuvem2;
    Nuvem *nuvem3;


    void init();

    // Desabilita o construtor de cópia e o operador de atribuição
    Fase1(const Fase1&) = delete;
    Fase1& operator=(const Fase1&) = delete;

public:
    Fase1() : Fase("Fase - 1", Sprite("rsc/Fase1/jogo/background.img", COR::AZUL)) {this->init();};

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
