#include "xwing.hpp"

Xwing::Xwing() {
    // Carrega a textura do Xwing e inicializa sua posição na tela.
    image = LoadTexture("./Graphics/xwing.png");
    position.x = (GetScreenWidth() - image.width) / 2; // Centraliza horizontalmente.
    position.y = GetScreenHeight() - image.height - 100; // Define a posição vertical.
    tempoUltimoTiro = 0.0; // Inicializa o tempo do último tiro como 0.
    somlaser = LoadSound("./Sounds/laser.ogg"); // Carrega o som do disparo do laser.
}

Xwing::~Xwing() {
    // Libera a memória alocada para a textura e o som.
    UnloadTexture(image);
    UnloadSound(somlaser);
}

void Xwing::Draw() {
    // Desenha a textura do Xwing na tela na posição atual.
    DrawTextureV(image, position, WHITE);
}

void Xwing::MoverEsquerda() {
    // Move o Xwing para a esquerda.
    position.x -= 7;
    // Garante que o Xwing não saia da tela no lado esquerdo.
    if (position.x < 25) {
        position.x = 25;
    }
}

void Xwing::MoverDireita() {
    // Move o Xwing para a direita.
    position.x += 7;
    // Garante que o Xwing não saia da tela no lado direito.
    if (position.x > GetScreenWidth() - image.width - 25) {
        position.x = GetScreenWidth() - image.width - 25;
    }
}

void Xwing::AtirarLaser() {
    // Verifica se o intervalo mínimo entre disparos foi atingido.
    if (GetTime() - tempoUltimoTiro >= 0.35) {
        // Cria um novo laser na posição central superior do Xwing.
        lasers.push_back(Laser({position.x + image.width / 2 - 2, position.y}, -6));
        tempoUltimoTiro = GetTime(); // Atualiza o tempo do último tiro.
        PlaySound(somlaser); // Reproduz o som do laser.
    }
}

Rectangle Xwing::getRect() {
    // Retorna o retângulo de colisão do Xwing, baseado em sua posição e dimensões.
    return {position.x, position.y, float(image.width), float(image.height)};
}

void Xwing::Reiniciar() {
    // Restaura a posição inicial do Xwing.
    position.x = (GetScreenWidth() - image.width) / 2.0f;
    position.y = GetScreenHeight() - image.height - 100;
    lasers.clear(); // Remove todos os lasers disparados.
}