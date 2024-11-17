#include "navesimperiais.hpp"

// Inicializa o array de texturas das naves como vazio.
Texture2D Nave::naveImagens[3] = {};

Nave::Nave(int tipo, Vector2 position) {
    // Define o tipo e a posição da nave.
    this->tipo = tipo;
    this->position = position;

    // Verifica se a textura correspondente ao tipo ainda não foi carregada.
    if (naveImagens[tipo - 1].id == 0) {
        // Carrega a textura apropriada com base no tipo da nave.
        switch (tipo) {
            case 1:
                naveImagens[0] = LoadTexture("./Graphics/tiefighter.png");
                break;
            case 2:
                naveImagens[1] = LoadTexture("./Graphics/vadertie.png");
                break;
            case 3:
                naveImagens[2] = LoadTexture("./Graphics/destroyer.png");
                break;
            default:
                naveImagens[0] = LoadTexture("./Graphics/tiefighter.png");
                break;
        }
    }
}

void Nave::Draw() {
    // Desenha a nave usando a textura do tipo correspondente.
    DrawTextureV(naveImagens[tipo - 1], position, WHITE);
}

int Nave::PegarTipo() {
    // Retorna o tipo da nave.
    return tipo;
}

void Nave::DescarregarImagens() {
    // Libera a memória de todas as texturas carregadas.
    for (int i = 0; i < 3; i++) {
        UnloadTexture(naveImagens[i]);
    }
}

Rectangle Nave::getRect() {
    // Retorna o retângulo de colisão da nave, com base na posição e nas dimensões da textura.
    return {position.x, position.y,
            float(naveImagens[tipo - 1].width),
            float(naveImagens[tipo - 1].height)};
}

void Nave::Update(int direcao) {
    // Atualiza a posição horizontal da nave com base na direção especificada.
    position.x += direcao;
}