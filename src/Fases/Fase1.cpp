#include "Fase1.hpp"
#include "../excecoes/MusicaNaoEncontrada.hpp"

using namespace std;

// Função para pausar a execução por um determinado intervalo em milissegundos
void Fase1::pausar(int milissegundos) {
    this_thread::sleep_for(chrono::milliseconds(milissegundos));
}

// Função para capturar teclas enquanto o programa está sendo executado
void Fase1::capturarTecla() {
    while (this->flag.load()) {
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
            this->hero->moveTo(65, 121);
        
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
            this->hero->moveTo(65, 155);
        
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            this->flag.store(false); // Sinaliza para a main que o programa deve encerrar
            break;
        }

        // Adicionar mais condições conforme necessário para outras teclas
        //pausar(50);
    }
}

int Fase1::curva_esquerda(int velocidade) {
    
    system("cls");

    // desativando montanhas do cenario normal
    this->montanha_direita->desativarObj();
    this->montanha_esquerda->desativarObj();

    // ativando montanhas para simular curva
    this->montanha_direita_curva_esquerda->ativarObj();
    this->montanha_esquerda_curva_esquerda->ativarObj();

    // desativando pista reta
    this->pista->desativarObj();
    
    // ativando pista curva
    this->pista_left->ativarObj();

    for (int i = 0; i < 100 && flag.load(); i++) {
        this->update();
        this->draw(this->screen);
        this->show(this->screen);
        pausar(velocidade);
        system("cls");
    }

    // revertendo o cenario de montanhas
    this->montanha_direita_curva_esquerda->desativarObj();
    this->montanha_esquerda_curva_esquerda->desativarObj();
    this->montanha_direita->ativarObj();
    this->montanha_esquerda->ativarObj();
    
    //revertendo pistas
    this->pista->ativarObj();
    this->pista_left->desativarObj();

    return 0;
}

int Fase1::curva_direita(int velocidade){

    system("cls");

    // desativando montanhas do cenario normal
    this->montanha_direita->desativarObj();
    this->montanha_esquerda->desativarObj();

    // ativando montanhas para simular curva
    this->montanha_direita_curva_direita->ativarObj();
    this->montanha_esquerda_curva_direita->ativarObj();

    // desativando pista reta
    this->pista->desativarObj();
    
    // ativando pista curva
    this->pista_right->ativarObj();

    for (int i = 0; i < 100 && flag.load(); i++) {
        this->update();
        this->draw(this->screen);
        this->show(this->screen);
        pausar(velocidade);
        system("cls");
    }

    // revertendo o cenario de montanhas
    this->montanha_direita_curva_direita->desativarObj();
    this->montanha_esquerda_curva_direita->desativarObj();
    this->montanha_direita->ativarObj();
    this->montanha_esquerda->ativarObj();
    
    //revertendo pistas
    this->pista->ativarObj();
    this->pista_right->desativarObj();

    return 0;
}

void Fase1::init() {
        this->flag = true;
        this->screen = SpriteBuffer(300, 77);
        this->musica.setLoop(true);
        // Carrega o arquivo de música
        if (!musica.openFromFile("src/Songs/Top Gear_ Vegas.mp3")) {
            throw MusicaNaoEncontrada("src/Songs/Top Gear_ Vegas.mp3"); // Se não conseguir carregar o arquivo, sai do programa
        }
        this->musica.setVolume(100);
        this->pista =  new ObjetoDeJogo("pista_reta", SpriteAnimado("rsc/Fase1/pistas/pista_reta.anm", 1, COR::AMARELA), 47, 90);
        this->pista_right = new ObjetoDeJogo("pista_direita", SpriteAnimado("rsc/Fase1/pistas/pista_direita.anm", 1, COR::AMARELA),48,85);
        this->pista_left = new ObjetoDeJogo("pista_esquerda", SpriteAnimado("rsc/Fase1/pistas/pista_esquerda.anm", 1, COR::AMARELA),48,85);

        // Inicializando heroi
        this->hero = new Player("hero1", Sprite("rsc/Fase1/jogo/hero1.img", COR::VERMELHA), 65, 121);

        // Inicializando nuvens
        this->nuvem1 = new Nuvem("nuvem1", Sprite("rsc/Fase1/nuvens/nuvem1.img", COR::BRANCA), 4, 219, 10);
        this->nuvem2 = new Nuvem("nuvem2", Sprite("rsc/Fase1/nuvens/nuvem2.img", COR::BRANCA), 12, 1, 5);
        this->nuvem3 = new Nuvem("nuvem3", Sprite("rsc/Fase1/nuvens/nuvem3.img", COR::BRANCA), 20, 150, 4);
        this->grass = new ObjetoDeJogo("Grama", Sprite("rsc/Fase1/jogo/grass.img", COR::VERDE), 48, 0);

        //Montanhas do cenario
        this->montanha_direita = new ObjetoDeJogo("Montanha direita", Sprite("rsc/Fase1/montanhas/montanha_direita.img", COR::MARROM), 20, 177);
        this->montanha_esquerda = new ObjetoDeJogo("Montanha esquerda", Sprite("rsc/Fase1/montanhas/montanha_esquerda.img", COR::MARROM), 28, 0);
        this->montanha_esquerda_curva_direita = new ObjetoDeJogo("Montanha esquerda da curva direita", Sprite("rsc/Fase1/montanhas/montanha_esquerda_curva_direita.img", COR::MARROM), 20, 0);
        this->montanha_esquerda_curva_esquerda = new ObjetoDeJogo("Montanha esquerda da curva esquerda", Sprite("rsc/Fase1/montanhas/montanha_esquerda_curva_esquerda.img", COR::MARROM), 27, 0);
        this->montanha_direita_curva_direita = new ObjetoDeJogo("Montanha direita da curva direita", Sprite("rsc/Fase1/montanhas/montanha_direita_curva_direita.img", COR::MARROM), 29, 186);
        this->montanha_direita_curva_esquerda = new ObjetoDeJogo("Montanha direita da curva esquerda", Sprite("rsc/Fase1/montanhas/montanha_direita_curva_esquerda.img", COR::MARROM), 18, 124);

        // desativando objs
        this->pista_right->desativarObj();
        this->pista_left->desativarObj();
        this->montanha_esquerda_curva_direita->desativarObj();
        this->montanha_esquerda_curva_esquerda->desativarObj();
        this->montanha_direita_curva_direita->desativarObj();
        this->montanha_direita_curva_esquerda->desativarObj();

        // adicionando objs a lista gerenciadora
        this->objs.push_back(montanha_direita);
        this->objs.push_back(montanha_esquerda);
        this->objs.push_back(montanha_esquerda_curva_direita);
        this->objs.push_back(montanha_esquerda_curva_esquerda);
        this->objs.push_back(montanha_direita_curva_direita);
        this->objs.push_back(montanha_direita_curva_esquerda);
        this->objs.push_back(grass);
        this->objs.push_back(pista);
        this->objs.push_back(pista_right);
        this->objs.push_back(pista_left);
        this->objs.push_back(hero);
        this->objs.push_back(nuvem1);
        this->objs.push_back(nuvem2);
        this->objs.push_back(nuvem3);
    }

unsigned Fase1::run(SpriteBuffer &screen) {
    this->screen = screen;
    system("cls");

    auto time = chrono::system_clock::now();

    int velocidade = 150;

    musica.play();

    // Crie uma thread para capturar entradas
    thread teclado(capturarTecla, this);

    for (int i = 0; i < 1000 && flag.load(); i++) {
        /* if (i == 10) {
            this->curva_esquerda(velocidade);
            continue;
        }

        if (i == 20) {
            this->curva_direita(velocidade);
            continue;
        }*/

        this->update();
        this->draw(this->screen);
        this->show(this->screen);
        pausar(velocidade);

        system("cls");
        if(velocidade > 80) velocidade--;
    }

    teclado.join(); // Espera a thread do teclado terminar
    return 0;
}
