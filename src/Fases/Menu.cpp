#include "Menu.hpp"
#include "../excecoes/MusicaNaoEncontrada.hpp"

// Função para pausar a execução por um determinado intervalo em milissegundos
void Menu::pausar(int milissegundos) {
    this_thread::sleep_for(chrono::milliseconds(milissegundos));
}

void Menu::capturarTecla() {
    while (this->flag.load()) {
        pausar(100);
        if ((GetAsyncKeyState(VK_UP) & 0x8000) && (this->escolhaFase > 0)) { 
            this->seta->moveTo(this->seta->getPosL() - 10, this->seta->getPosC());
            this->escolhaFase -= 1;
        }

        else if ((GetAsyncKeyState(VK_UP) & 0x8000) && (this->escolhaFase == 0)) { 
            this->seta->moveTo(this->seta->getPosL() + 20, this->seta->getPosC());
            this->escolhaFase = 2;
        }

        else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && (this->escolhaFase < 2)) { 
            this->seta->moveTo(this->seta->getPosL() + 10, this->seta->getPosC());
            this->escolhaFase += 1;
        }

        else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && (this->escolhaFase == 2)) { 
            this->seta->moveTo(this->seta->getPosL() - 20, this->seta->getPosC());
            this->escolhaFase = 0;
        }

        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            this->flag.store(false); // Sinaliza para a main que o programa deve encerrar
            this->escolhaFase = 4;
            break;
        }

        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
            this->flag.store(false); // Sinaliza para a main que o programa deve encerrar
            break;
        }
    }
}


void Menu::init(){
    this->flag.store(true);
    this->screen = SpriteBuffer(300, 77);

    this->titulo = new ObjetoDeJogo("Titulo", Sprite("rsc/Menu/Titulo.img", COR::AMARELA), 10,80 );
    this->fase1 = new ObjetoDeJogo("Fase1", Sprite("rsc/Menu/Fase1.img", COR::AMARELA), 40 , 111);
    this->fase2 = new ObjetoDeJogo("Fase2", Sprite("rsc/Menu/Fase2.img", COR::AMARELA), 50 , 111);
    this->fechar = new ObjetoDeJogo("Fase4", Sprite("rsc/Menu/Encerrar.img", COR::AMARELA),60, 111);
    this->seta = new ObjetoDeJogo("Seta", Sprite("rsc/Menu/seta.img", COR::BRANCA), 38, 88);

    this->objs.push_back(titulo);
    this->objs.push_back(fase1);
    this->objs.push_back(fase2);
    this->objs.push_back(fechar);
    this->objs.push_back(seta);
}

unsigned Menu::run(SpriteBuffer &screen){
    this->flag.store(true);
    this->seta->moveTo(38,88);
    this->escolhaFase = 0;
    // Crie uma thread para capturar entradas
    thread tecladoMenu(capturarTecla, this);

    while (this->flag.load())
    {
        this->update();
        this->draw(this->screen);
        this->show(this->screen);
        cout << this->escolhaFase << endl;

        pausar(200);

        system("cls");
    }

    tecladoMenu.join();
    return this->escolhaFase;
    
}