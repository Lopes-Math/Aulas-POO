#include <raylib.h>
#include "game.hpp"
#include <string>

// Função auxiliar para formatar números com zeros à esquerda até atingir um tamanho específico.
std::string FormatarZerosAEsquerda(int numero, int width) {
    std::string numeroTexto = std::to_string(numero); // Converte o número para string.
    int zerosAEsquerda = width - numeroTexto.length(); // Calcula a quantidade de zeros necessários.
    return numeroTexto = std::string(zerosAEsquerda, '0') + numeroTexto; // Adiciona os zeros à esquerda.
}

int main() 
{
    // Definição de cores personalizadas.
    Color cinza = {29, 29, 27, 255}; // Cor de fundo da janela.
    Color vermelho = {255, 0, 0, 255}; // Cor dos elementos de destaque.

    // Parâmetros da janela.
    int offset = 50; // Margem ao redor da janela.
    int janelaLargura = 750; // Largura da janela.
    int janelaAltura = 700; // Altura da janela.

    // Inicialização da janela e do dispositivo de áudio.
    InitWindow(janelaLargura + offset, janelaAltura + 2 * offset, "Star Wars com Raylib C++");
    InitAudioDevice();

    // Carregamento de fontes e texturas.
    Font font = LoadFontEx("./Font/monogram.ttf", 64, 0, 0); // Carrega a fonte personalizada.
    Texture2D xwingImage = LoadTexture("./Graphics/xwing.png"); // Carrega a textura do X-Wing.

    SetTargetFPS(60); // Define o FPS alvo para 60.

    Game game; // Instancia o objeto principal do jogo.

    // Loop principal do jogo.
    while (WindowShouldClose() == false) {
        UpdateMusicStream(game.music); // Atualiza o stream da música de fundo.
        game.HandleInput(); // Processa a entrada do jogador.
        game.Update(); // Atualiza o estado do jogo.

        BeginDrawing(); // Inicia o desenho na tela.
        ClearBackground(cinza); // Limpa o fundo com a cor cinza.

        // Desenha elementos decorativos, como bordas e linhas.
        DrawRectangleRoundedLines({10, 15, 780, 775}, 0.18f, 20, 2, vermelho);
        DrawLineEx({25, 730}, {775, 730}, 3, vermelho);

        // Verifica se o jogo está em execução.
        if (game.run) {
            DrawTextEx(font, "NIVEL 01", {570, 740}, 34, 2, vermelho); // Exibe o nível atual.
        } else {
            DrawTextEx(font, "FIM DE JOGO", {550, 740}, 34, 2, vermelho); // Exibe o texto de fim de jogo.
        }

        // Desenha as vidas do jogador como naves na parte inferior da tela.
        float x = 50.0;
        for (int i = 0; i < game.vidas; i++) {
            DrawTextureV(xwingImage, {x, 745}, WHITE);
            x += 50; // Incrementa a posição horizontal para cada nave.
        }

        // Exibe a pontuação do jogador.
        DrawTextEx(font, "PONTUACAO", {50, 15}, 34, 2, vermelho);
        std::string scoreText = FormatarZerosAEsquerda(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, vermelho);

        // Exibe o recorde do jogo.
        DrawTextEx(font, "RECORDE", {618, 15}, 34, 2, vermelho);
        std::string highscoreText = FormatarZerosAEsquerda(game.highscore, 5);
        DrawTextEx(font, highscoreText.c_str(), {655, 40}, 34, 2, vermelho);

        game.Draw(); // Chama a função para desenhar elementos do jogo.

        EndDrawing(); // Finaliza o desenho na tela.
    }

    // Fecha a janela e libera os recursos de áudio.
    CloseWindow();
    CloseAudioDevice();
}