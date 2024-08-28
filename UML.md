# Diagrama de Classes UML - PacMan - ASCII

```mermaid
classDiagram

    class ASCII_Engine{
        <<Engine>>
    }

    class Game {
        <<Classe Principal>>

    }

    class Fase1{
        <<Fase 1>>
        - Screen background;
        - Player player;
        - Enemy enemies[];
    }

    class Fase2{
        <<Fase 2>>
        - Screen background;
        - Player player;
        - Enemy enemies[];
    }

    class Fase3{
        <<Fase 3>>
        - Screen background;
        - Player player;
        - Enemy enemies[];
    }

    

    ASCII_Engine ..|> Game

    Game ..|> Fase1
    Game ..|> Fase2
    Game ..|> Fase3

    Fase1 *-- Player1
    Fase2 *-- Player2
    Fase3 *-- Player3
    
    Fase1 *-- Enemy1
    Fase2 *-- Enemy2
    Fase3 *-- Enemy3

    Fase1 *-- Screen1
    Fase2 *-- Screen2
    Fase3 *-- Screen3
