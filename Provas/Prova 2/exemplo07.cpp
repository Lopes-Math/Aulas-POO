#include <raylib.h>
#include "player.hpp"
#include "enemy.hpp"
#include "collectible.hpp" // Incluímos a classe Collectible
#include <vector>
#include <memory>
#include <algorithm>

// Diretório da aplicação
const char *appDir = GetApplicationDirectory();

// Função principal
int main() {
    // Define a janela da aplicação
    InitWindow(800, 600, "Programa 07");

    // Inicializa o dispositivo de áudio
    InitAudioDevice();

    // Delta Time
    float deltaTime;

    // Framerate
    SetTargetFPS(60);

    // Instanciamento do player
    Player player;

    // ------------------------------------------------------------------------

    // Vetor para armazenar os inimigos como ponteiros exclusivos
    std::vector<std::unique_ptr<Enemy>> enemies;

    // Loop para instanciamento dos inimigos
    for (int i = 0; i < 10; i++)
        enemies.emplace_back(std::unique_ptr<Enemy>(new Enemy()));

    // ------------------------------------------------------------------------

    // Vetor para armazenar os collectibles como ponteiros exclusivos
    std::vector<std::unique_ptr<Collectible>> collectibles;

    // Loop para instanciamento dos collectibles
    for (int i = 0; i < 5; i++)
        collectibles.emplace_back(std::unique_ptr<Collectible>(new Collectible()));

    // Variável para armazenar o score do jogador
    int playerScore = 0;

    // ------------------------------------------------------------------------

    // Carrega a música de fundo
    Music music = LoadMusicStream(TextFormat("%s/assets/music/music.mp3", appDir));

    // Toca a música em loop
    PlayMusicStream(music);

    // ------------------------------------------------------------------------

    // Game loop
    while (!WindowShouldClose()) {
        // Atualiza o stream da música
        UpdateMusicStream(music);

        // Retorna o tempo em segundos que o último frame levou para ser processado
        deltaTime = GetFrameTime();

        // Atualiza o player
        player.Update(deltaTime);

        // Atualização da posição de todos os inimigos
        for (auto& enemy : enemies)
            enemy->Update(deltaTime);

        // Remove os inimigos que colidiram com o player
        enemies.erase(
            std::remove_if(enemies.begin(), enemies.end(),
                [&](const std::unique_ptr<Enemy>& enemy) {
                    if (enemy->checkCollision(player)) {
                        player.takeDamage(10); // Dano ao player
                        return true; // Marca o inimigo para remoção
                    }
                    return false; // Mantém o inimigo
                }),
            enemies.end()
        );

        // Atualização da posição de todos os collectibles
        for (auto& collectible : collectibles)
            collectible->Update();

        // Remove os collectibles que foram coletados pelo jogador
        collectibles.erase(
            std::remove_if(collectibles.begin(), collectibles.end(),
                [&](const std::unique_ptr<Collectible>& collectible) {
                    if (collectible->checkCollision(player)) {
                        playerScore += 10; // Incrementa o score
                        return true; // Marca o item para remoção
                    }
                    return false; // Mantém o item
                }),
            collectibles.end()
        );

        // Início da renderização dos objetos do jogo
        BeginDrawing();

            // Define a cor de fundo
            ClearBackground(BLACK);

            // Renderiza o player
            player.Draw();

            // Renderiza todos os inimigos
            for (const auto& enemy : enemies)
                enemy->Draw();

            // Renderiza todos os collectibles
            for (const auto& collectible : collectibles)
                collectible->Draw();

            // Renderiza o texto com o total de inimigos
            DrawText(
                TextFormat("Enemies: %d", Enemy::getEnemyCount()),
                GetScreenWidth() - 130.0f,
                20.0f,
                22,
                WHITE
            );

            // Renderiza o texto com a saúde do player
            DrawText(
                TextFormat("Grogu: %d %%", 100 * player.getHealth() / 100),
                GetScreenWidth() - 150.0f,
                50.0f,
                22,
                WHITE
            );

            // Renderiza o texto com o score do jogador
            DrawText(
                TextFormat("Score: %d", playerScore),
                GetScreenWidth() - 150.0f,
                80.0f,
                22,
                WHITE
            );

        // Fim da renderização dos objetos do jogo
        EndDrawing();
    }

    // ------------------------------------------------------------------------

    // Libera a memória utilizada pela música de fundo
    UnloadMusicStream(music);

    // Fecha o dispositivo de áudio
    CloseAudioDevice();

    // Fecha a janela e limpa recursos do Raylib
    CloseWindow();

    return 0;
}