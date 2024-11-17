#pragma once
#include "xwing.hpp"
#include "laser.hpp"
#include "obstaculo.hpp"
#include "navesimperiais.hpp"
#include "estreladamorte.hpp"

// Classe principal do jogo, que controla o fluxo do jogo e os elementos que interagem com o jogador.
class Game {
    public:
        // Construtor: inicializa o jogo, configura variáveis e carrega recursos.
        Game();

        // Destruidor: libera recursos alocados quando o jogo termina.
        ~Game();

        // Método para desenhar todos os elementos do jogo na tela.
        void Draw();

        // Método para atualizar o estado do jogo (movimentação, disparos, etc).
        void Update();

        // Método para tratar a entrada do jogador (teclado, etc).
        void HandleInput();

        // Variáveis do jogo:
        bool run;           // Indica se o jogo está em execução.
        int vidas;          // Número de vidas do jogador.
        int score;          // Pontuação atual do jogador.
        int highscore;      // Melhor pontuação do jogador.
        Music music;        // Música de fundo do jogo.

    private:
        // Métodos privados:
        // Deleta lasers que não estão mais ativos (fora da tela ou colidiram com algo).
        void DeletarLasersInativos();

        // Cria obstáculos na tela.
        std::vector<Obstaculo> CriarObstaculos();

        // Cria as naves inimigas no jogo.
        std::vector<Nave> CriarNaves();

        // Move as naves inimigas.
        void MoverNaves();

        // Move as naves inimigas para baixo em uma determinada distância.
        void MoverNavesAbaixo(int distancia);

        // Faz a nave (Xwing) disparar lasers.
        void NaveAtirarLaser();

        // Verifica colisões entre as naves, lasers, obstáculos e a nave do jogador.
        void ChecarColisoes();

        // Método chamado quando o jogador perde o jogo (game over).
        void GameOver();

        // Reinicia o jogo para uma nova partida.
        void Reiniciar();

        // Inicializa os recursos e o estado do jogo no começo.
        void InicGame();

        // Verifica se a pontuação atual bateu o recorde.
        void checaHighscore();

        // Salva o highscore no arquivo para persistência.
        void salvaHighscoreNoArquivo(int highscore);

        // Carrega o highscore de um arquivo.
        int carregaHighscoreDoArquivo();

        // Variáveis privadas:
        Xwing xwing;                        // Nave do jogador.
        std::vector<Obstaculo> obstaculos;   // Lista de obstáculos no jogo.
        std::vector<Nave> naves;            // Lista de naves inimigas.
        int direcaoNaves;                   // Direção para a movimentação das naves inimigas.
        std::vector<Laser> naveLasers;      // Lista de lasers disparados pela nave do jogador.
        
        // Intervalo de tempo mínimo entre disparos da nave do jogador.
        constexpr static float naveLaserIntervaloTiro = 0.35;

        // Tempo desde o último tiro da nave.
        float tempoUltimoTiroNave;

        EstrelaDaMorte estreladamorte;       // A Estrela da Morte, um inimigo especial.
        float intervaloSpawnEstrelaDaMorte;  // Intervalo de tempo entre os spawns da Estrela da Morte.
        float tempoDoUltimoSpawn;           // Tempo desde o último spawn da Estrela da Morte.

        // Som da explosão, tocado quando há uma colisão ou destruição.
        Sound somexplosao;
};