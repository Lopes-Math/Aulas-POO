#include "game.hpp"
#include <iostream>
#include <fstream>

// Construtor: carrega a música de fundo, o som de explosão e inicia o jogo.
Game::Game() {
    music = LoadMusicStream("./Sounds/music.ogg");  // Carrega a música de fundo.
    somexplosao = LoadSound("./Sounds/explosion.ogg");  // Carrega o som da explosão.
    PlayMusicStream(music);  // Começa a tocar a música de fundo.
    InicGame();  // Inicializa o estado do jogo.
}

// Destruidor: libera recursos quando o jogo é finalizado.
Game::~Game() {
    Nave::DescarregarImagens();  // Libera imagens usadas pelas naves.
    UnloadMusicStream(music);  // Libera a música.
    UnloadSound(somexplosao);  // Libera o som da explosão.
}

// Atualiza o estado do jogo, movendo elementos e verificando colisões.
void Game::Update() {
    if(run) {
        double tempoAtual = GetTime();  // Obtém o tempo atual do jogo.
        
        // Verifica se a Estrela da Morte deve ser spawnada.
        if(tempoAtual - tempoDoUltimoSpawn > intervaloSpawnEstrelaDaMorte) {
            estreladamorte.Spawn();
            tempoDoUltimoSpawn = GetTime();  // Atualiza o tempo do último spawn.
            intervaloSpawnEstrelaDaMorte = GetRandomValue(10, 20);  // Define um novo intervalo aleatório para o próximo spawn.
        }

        // Atualiza os lasers da X-Wing.
        for(auto& laser: xwing.lasers){
            laser.Update();
        }

        MoverNaves();  // Atualiza a movimentação das naves inimigas.
        NaveAtirarLaser();  // Faz as naves inimigas atirarem lasers.

        // Atualiza os lasers disparados pelas naves inimigas.
        for(auto& laser: naveLasers){
            laser.Update();
        };

        DeletarLasersInativos();  // Remove lasers que não estão mais ativos.
        estreladamorte.Update();  // Atualiza o estado da Estrela da Morte.

        ChecarColisoes();  // Verifica colisões entre objetos.
    } else {
        if(IsKeyDown(KEY_ENTER)){
            Reiniciar();  // Reinicia o jogo se o ENTER for pressionado.
            InicGame();  // Re-inicia o jogo com o estado inicial.
        }
    }
}

// Desenha os elementos do jogo na tela.
void Game::Draw() {
    xwing.Draw();  // Desenha a nave do jogador.

    // Desenha os lasers disparados pela X-Wing.
    for(auto& laser: xwing.lasers){
        laser.Draw();
    };

    // Desenha os obstáculos no jogo.
    for(auto& obstaculo: obstaculos){
        obstaculo.Draw();
    };

    // Desenha as naves inimigas.
    for(auto& nave: naves){
        nave.Draw();
    };

    // Desenha os lasers disparados pelas naves inimigas.
    for(auto& laser: naveLasers){
        laser.Draw();
    };

    estreladamorte.Draw();  // Desenha a Estrela da Morte.
}

// Trata a entrada do jogador para movimentação e disparo.
void Game::HandleInput() {
    if(run) {
        // Movimenta a nave para a esquerda ou direita.
        if(IsKeyDown(KEY_LEFT)) {
            xwing.MoverEsquerda();
        } else if (IsKeyDown(KEY_RIGHT)){
            xwing.MoverDireita();
        } else if(IsKeyDown(KEY_SPACE)){
            xwing.AtirarLaser();  // Dispara um laser.
        }
    }
}

// Deleta lasers inativos (aqueles que saíram da tela ou colidiram).
void Game::DeletarLasersInativos() {
    // Deleta lasers disparados pela X-Wing.
    for(auto it = xwing.lasers.begin(); it != xwing.lasers.end();){
        if(!it -> ativo) {
            it = xwing.lasers.erase(it);  // Remove laser inativo.
        } else {
            ++it;
        }
    };
    
    // Deleta lasers disparados pelas naves inimigas.
    for(auto it = naveLasers.begin(); it != naveLasers.end();){
        if(!it -> ativo) {
            it = naveLasers.erase(it);  // Remove laser inativo.
        } else {
            ++it;
        }
    }
}

// Cria obstáculos no jogo.
std::vector<Obstaculo> Game::CriarObstaculos() {
    int larguraObstaculo = Obstaculo::tabela[0].size() * 3;
    float espaco = (GetScreenWidth() - (4 * larguraObstaculo)) / 5;

    for(int i = 0; i < 4; i++){
        float offsetX = (i + 1) * espaco + i * larguraObstaculo;
        obstaculos.push_back(Obstaculo({offsetX, float(GetScreenHeight() - 200)}));
    }

    return obstaculos;
}

// Cria as naves inimigas no jogo.
std::vector<Nave> Game::CriarNaves() {
    std::vector<Nave> naves;
    for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 11; coluna++){
            int tipoNave;
            if(linha == 0){
                tipoNave = 3;  // Nave mais forte.
            } else if(linha == 1 || linha == 2){
                tipoNave = 2;  // Nave intermediária.
            } else {
                tipoNave = 1;  // Nave mais fraca.
            }

            float x = 75 + coluna * 55;
            float y = 110 + linha * 55;
            naves.push_back(Nave(tipoNave, {x, y}));  // Cria a nave com o tipo e a posição.
        }
    }
    return naves;
}

// Move as naves inimigas.
void Game::MoverNaves() {
    for(auto& nave: naves){
        if(nave.position.x + nave.naveImagens[nave.tipo - 1].width > GetScreenWidth() - 25){
            direcaoNaves = -1;  // Troca direção para a esquerda.
            MoverNavesAbaixo(4);  // Move as naves para baixo.
        }
        if(nave.position.x < 25){
            direcaoNaves = 1;  // Troca direção para a direita.
            MoverNavesAbaixo(2);  // Move as naves para baixo.
        }

        nave.Update(direcaoNaves);  // Atualiza a posição da nave.
    }
}

// Move as naves para baixo.
void Game::MoverNavesAbaixo(int distancia) {
    for(auto& nave: naves){
        nave.position.y += distancia;
    }
}

// As naves inimigas disparam lasers.
void Game::NaveAtirarLaser() {
    double tempoAtual = GetTime();
    if(tempoAtual - tempoUltimoTiroNave >= naveLaserIntervaloTiro && !naves.empty()){
        int naveRandom = GetRandomValue(0, naves.size() - 1);  // Escolhe uma nave aleatória.
        Nave& nave = naves[naveRandom];
        naveLasers.push_back(Laser({nave.position.x + nave.naveImagens[nave.tipo - 1].width / 2, 
                                    nave.position.y + nave.naveImagens[nave.tipo - 1].height}, 6));  // Cria um laser disparado pela nave.
        tempoUltimoTiroNave = GetTime();  // Atualiza o tempo do último tiro.
    }
}

// Verifica colisões entre os objetos do jogo.
void Game::ChecarColisoes() {
    // Colisão dos lasers da X-Wing com as naves inimigas.
    for(auto& laser: xwing.lasers) {
        auto it = naves.begin();
        while(it != naves.end()){
            if(CheckCollisionRecs(it -> getRect(), laser.getRect())) {
                PlaySound(somexplosao);  // Toca o som de explosão.
                // Adiciona pontos dependendo do tipo da nave.
                if(it -> tipo == 1) {
                    score += 100;
                } else if (it -> tipo == 2) {
                    score += 200;
                } else if(it -> tipo == 3) {
                    score += 300;
                }
                checaHighscore();  // Checa se a pontuação bateu o recorde.

                it = naves.erase(it);  // Remove a nave destruída.
                laser.ativo = false;  // Desativa o laser.
            } else {
                ++it;
            }
        }
        
        // Colisão dos lasers com os obstáculos.
        for(auto& obstaculo: obstaculos){
            auto it = obstaculo.blocos.begin();
            while(it != obstaculo.blocos.end()){
                if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                    it = obstaculo.blocos.erase(it);  // Remove o bloco do obstáculo.
                    laser.ativo = false;  // Desativa o laser.
                } else {
                    ++it;
                }
            }
        }

        // Colisão do laser com a Estrela da Morte.
        if(CheckCollisionRecs(estreladamorte.getRect(), laser.getRect())) {
            estreladamorte.viva = false;  // Destrói a Estrela da Morte.
            laser.ativo = false;  // Desativa o laser.
            score += 500;  // Adiciona pontos.
            checaHighscore();  // Checa se a pontuação bateu o recorde.
            PlaySound(somexplosao);  // Toca o som de explosão.
        }
    }

    // Verifica colisões para os lasers disparados pelas naves inimigas.
    for(auto& laser: naveLasers) {
        if(CheckCollisionRecs(laser.getRect(), xwing.getRect())) {
            laser.ativo = false;  // Desativa o laser.
            vidas--;  // Perde uma vida.
            if(vidas == 0) {
                GameOver();  // Fim de jogo se as vidas chegarem a zero.
            }
        }

        // Colisão dos lasers com os obstáculos.
        for(auto& obstaculo: obstaculos){
            auto it = obstaculo.blocos.begin();
            while(it != obstaculo.blocos.end()){
                if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                    it = obstaculo.blocos.erase(it);  // Remove o bloco do obstáculo.
                    laser.ativo = false;  // Desativa o laser.
                } else {
                    ++it;
                }
            }
        }
    }

    // Verifica colisão das naves com obstáculos e com a X-Wing.
    for(auto& nave: naves) {
        for(auto& obstaculo: obstaculos) {
            auto it = obstaculo.blocos.begin();
            while(it != obstaculo.blocos.end()) {
                if(CheckCollisionRecs(it -> getRect(), nave.getRect())) {
                    it = obstaculo.blocos.erase(it);  // Remove o bloco do obstáculo.
                } else {
                    it++;
                }
            }
        }

        if(CheckCollisionRecs(nave.getRect(), xwing.getRect())) {
            GameOver();  // Fim de jogo se a nave colidir com a X-Wing.
        }
    }
}

// Finaliza o jogo (Game Over).
void Game::GameOver() {
    run = false;  // Para o jogo.
}

// Inicializa o jogo, configurando todos os parâmetros e elementos.
void Game::InicGame()
{
    obstaculos = CriarObstaculos();  // Cria obstáculos.
    naves = CriarNaves();  // Cria as naves inimigas.
    direcaoNaves = 1;  // Define a direção das naves.
    tempoUltimoTiroNave = 0.0;  // Define o tempo do último tiro.
    tempoDoUltimoSpawn = 0;  // Define o tempo do último spawn da Estrela da Morte.
    vidas = 3;  // Define o número inicial de vidas.
    score = 0;  // Define a pontuação inicial.
    highscore = carregaHighscoreDoArquivo();  // Carrega o recorde de pontos.
    run = true;  // Inicia o jogo.
    intervaloSpawnEstrelaDaMorte = GetRandomValue(10, 20);  // Intervalo aleatório para o spawn da Estrela da Morte.
}

// Checa se a pontuação bateu o recorde.
void Game::checaHighscore()
{
    if(score > highscore) {
        highscore = score;  // Atualiza o recorde.
        salvaHighscoreNoArquivo(highscore);  // Salva o novo recorde.
    }
}

// Salva o recorde no arquivo.
void Game::salvaHighscoreNoArquivo(int highscore)
{
    std::ofstream highscoreArquivo("highscore.txt");
    if(highscoreArquivo.is_open()) {
        highscoreArquivo << highscore;  // Grava o recorde no arquivo.
        highscoreArquivo.close();
    } else {
        std::cerr << "Erro ao salvar o highscore no Arquivo." << std::endl;
    }
}

// Carrega o recorde do arquivo.
int Game::carregaHighscoreDoArquivo() {
    int highscoreCarregado = 0;
    std::ifstream highscoreArquivo("highscore.txt");
    if(highscoreArquivo.is_open()) {
        highscoreArquivo >> highscoreCarregado;  // Lê o recorde do arquivo.
        highscoreArquivo.close();
    } else {
        std::cerr << "Erro ao salvar o highscore no Arquivo." << std::endl;
    }
    return highscoreCarregado;
}

// Reinicia o jogo, resetando os elementos principais.
void Game::Reiniciar() {
    xwing.Reiniciar();  // Reinicia a nave do jogador.
    naves.clear();  // Limpa as naves inimigas.
    naveLasers.clear();  // Limpa os lasers das naves inimigas.
    obstaculos.clear();  // Limpa os obstáculos.
}