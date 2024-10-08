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
            this->escape = true; // Sinaliza para a main que a tecla escape foi pressionada
            break;
        }

        if(haInimigos()) {
            if(this->hero->colideCom(this->enemies[2])){
                this->flag.store(false);
                this->enemies[2]->desativarEnemy();
                break;
            }
        }
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
        this->escape = false;
        this->screen = SpriteBuffer(300, 77);
        // Carrega o arquivo de música
        if (!musica.openFromFile("src/Songs/Top Gear_ Vegas.mp3")) {
            throw MusicaNaoEncontrada("src/Songs/Top Gear_ Vegas.mp3"); // Se não conseguir carregar o arquivo, sai do programa
        }
        this->musica.setLoop(true);
        this->musica.setVolume(100);
        this->pista =  new ObjetoDeJogo("pista_reta", SpriteAnimado("rsc/Fase1/pistas/pista_reta.anm", 1, COR::AMARELA), 47, 90);
        this->pista_right = new ObjetoDeJogo("pista_direita", SpriteAnimado("rsc/Fase1/pistas/pista_direita.anm", 1, COR::AMARELA),48,85);
        this->pista_left = new ObjetoDeJogo("pista_esquerda", SpriteAnimado("rsc/Fase1/pistas/pista_esquerda.anm", 1, COR::AMARELA),48,85);
        this->gameover = new Sprite("rsc/Game/GameOver.img", COR::BRANCA);
        this->pontilhado = new Sprite("rsc/Menu/background.img", COR::VERMELHA);

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

        // inicializando array de inimigos
        this->enemies[0] = nullptr;
        this->enemies[1] = nullptr;
        this->enemies[2] = nullptr;

        
    }

Fase1::~Fase1() {
    
    // Deletando inimigos, verificando se não são nullptr
    for (int i = 0; i < 3; i++) {
        if (enemies[i] != nullptr) {
            delete enemies[i];
            enemies[i] = nullptr; // Limpa o ponteiro para evitar acessos inválidos
        }
    }

    // Deletando sprites auxiliares
    delete gameover;
    delete pontilhado;

}


void Fase1::enemyCreator(){

    if (this->objs.size() > 14) {
    // Limpando lista de inimigos corretamente
    for (int i = 0; i < 3; i++) {
        if (this->enemies[i] != nullptr) {
            delete this->enemies[i];
            this->enemies[i] = nullptr;
        }
    }

    // Remove os inimigos da lista objs
    while (this->objs.size() > 14) {
        this->objs.pop_back();
        }
    }
    
    // Inicializando Enemy
    int numero = RandomNumberGenerator::getInstance().getRandomNumber();
    auto cor = COR::PADRAO;

    switch (numero)
    {
    case 1:
        cor = COR::VERMELHA;
        break;
    
    case 2:
        cor = COR::VERDE;
        break;

    case 3:
        cor = COR::ROSA;
        break;
    
    case 4:
        cor = COR::MAGENTA;
        break;

    default:
        cor = COR::PADRAO;
        break;
    }
    this->enemies[0] = new Enemy("enemy1", Sprite("rsc/Fase1/inimigos/enemy1_pequeno.img", cor ), 46, ( (RandomNumberGenerator::getInstance().getRandomNumber() % 2 != 0)? 133 : 155) );
    this->enemies[1] = new Enemy("enemy2", Sprite("rsc/Fase1/inimigos/enemy1_medio.img", cor ), 55, ( (RandomNumberGenerator::getInstance().getRandomNumber() % 2 != 0)? 121 : 155 ) );
    this->enemies[2] = new Enemy("enemy3", Sprite("rsc/Fase1/inimigos/enemy1_grande.img", cor ), 65, this->enemies[1]->getPosC() );

    this->enemies[0]->desativarEnemy();
    this->enemies[1]->desativarEnemy();
    this->enemies[2]->desativarEnemy();

    this->objs.push_back(enemies[0]);
    this->objs.push_back(enemies[1]);
    this->objs.push_back(enemies[2]);
}

void Fase1::enemiesLogic()const {
    if(this->enemies[0]->getActive()){
        this->enemies[0]->desativarEnemy();
        this->enemies[1]->ativarEnemy();
        if (RandomNumberGenerator::getInstance().getRandomNumber() % 2 == 0){
            if (this->enemies[1]->getPosC() == 121){
                this->enemies[1]->moveTo(this->enemies[1]->getPosL(), 155);
                this->enemies[2]->moveTo(this->enemies[2]->getPosL(), 155);
            }
        else if(this->enemies[1]->getPosC() == 155){
            this->enemies[1]->moveTo(this->enemies[1]->getPosL(), 121);
            this->enemies[2]->moveTo(this->enemies[2]->getPosL(), 121);
        }

        }
        return;
    }

    else if(this->enemies[1]->getActive()){
        this->enemies[1]->desativarEnemy();
        this->enemies[2]->ativarEnemy();
        
        return;
    }

    else if (this->enemies[2]->getActive()){
    this->enemies[2]->desativarEnemy();
    return;
    }

    else{
        this->enemies[0]->ativarEnemy();
        return;
    }
}

bool Fase1::haInimigos()const{
    return (
        (this->enemies[0] != nullptr && this->enemies[0]->getActive()) 
        ||
        (this->enemies[1] != nullptr && this->enemies[1]->getActive()) 
        ||
        (this->enemies[2] != nullptr && this->enemies[2]->getActive()));
}

void Fase1::gameOver(){
    this->pontilhado->draw(this->screen, 0,0);
    this->gameover->draw(this->screen, 36, 109);
    cout << this->screen << endl;
    pausar(5000);
}


unsigned Fase1::run(SpriteBuffer &screen) {
    this->screen = screen;
    this->flag.store(true);
    system("cls");

    int velocidade = 150;

    musica.play();

    // Crie uma thread para capturar entradas
    thread tecladoFase1(capturarTecla, this);
    
    int cont = 0;

    while(this->flag.load()) {
        cont++;
        /* if (i == 10) {
            this->curva_esquerda(velocidade);
            continue;
        }

        if (i == 20) {
            this->curva_direita(velocidade);
            continue;
        }*/

        int numeroaleatorio = RandomNumberGenerator::getInstance().getRandomNumber();

        if (!(haInimigos())) {
            enemyCreator();
        }

        if(cont % 10 == 0){
            enemiesLogic();
        }

        this->update();
        this->draw(this->screen);
        this->show(this->screen);
        pausar(velocidade);

        system("cls");
        if(velocidade > 80) velocidade--;
    }
    
    tecladoFase1.join(); // Espera a thread do teclado terminar


    musica.stop();
    this->screen.clear();

    if(!this->escape){
        this->gameOver();
        return 0;
    }
    return -1;
}
