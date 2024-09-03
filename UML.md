# Diagrama de Classes UML - TopGear - ASCII

```mermaid
classDiagram

    class ASCII_Engine{
        <<Engine>>
    }

    class Fase{
        <<Abstract>>
        # std::string name;
        # SpriteBase* background;
        # std::list<ObjetoDeJogo*> objs;

        virtual void init() = 0
        virtual unsigned run(SpriteBuffer &screen) = 0
    }

    class ObjetoDeJogo{
        - std::string name;
        - int posL, posC;
        - SpriteBase* pSprite;

        + virtual void update()
    }

    class Fase1{
        - Player player;
        - Nuvem nuvem1;
        - Nuvem nuvem2;
        - Nuvem nuvem3;
        - vector<Enemy> enemies;

        + void init()
        + unsigned run(SpriteBuffer &screen)
    }

    class Fase2{
        - Player player;
        - vector<Enemy> enemies;
        - Dirigivel dirigivel;

        + void init()
        + unsigned run(SpriteBuffer &screen)
    }

    class Fase3{
        - Player player;
        - vector<Enemy> enemies;

        + void init()
        + unsigned run(SpriteBuffer &screen)
    }

    class Player{
        + void update()
    }

    class Enemy{
        + getActive() const
        + desativarEnemy()
        + ativarEnemy()
    }

    class Nuvem{
        + void update()
    }

    class Dirigivel{
        + void update()
    }

    class MusicaNaoEncontrada{
        - string filename_;

        + explicit MusicaNaoEncontrada(const string& filename)
        + const char* what() const noexcept override
        + string getFilename() const
    }

    ASCII_Engine <|-- Fase
    ObjetoDeJogo --|> ASCII_Engine

    Fase <|-- Fase1
    Fase <|-- Fase2
    Fase <|-- Fase3

    Player <|-- ObjetoDeJogo
    Enemy <|-- ObjetoDeJogo
    Nuvem <|-- ObjetoDeJogo
    Dirigivel <|-- ObjetoDeJogo

    runtime_error <|-- MusicaNaoEncontrada