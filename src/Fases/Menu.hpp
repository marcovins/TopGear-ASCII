#ifndef MENU_HPP
#define MENU_HPP

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

using namespace std;

class Menu : public Fase{

private:
    atomic<bool> flag;
    SpriteBuffer screen;

    ObjetoDeJogo *titulo;

    ObjetoDeJogo * fase1;
    ObjetoDeJogo * fase2;
    ObjetoDeJogo * fechar;
    ObjetoDeJogo *seta;

    int escolhaFase;
    void init();

    // Desabilita o construtor de cópia e o operador de atribuição
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;

public:
    Menu() : Fase("Menu", Sprite("rsc/Menu/background.img", COR::VERMELHA)) {this->init();};

    void pausar(int milissegundos);

    unsigned run(SpriteBuffer &screen);

    void capturarTecla();

};

#endif