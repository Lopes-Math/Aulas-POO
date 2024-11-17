#include "bloco.hpp"

// Construtor da classe Bloco, que recebe a posição inicial do bloco
Bloco::Bloco(Vector2 position)
{
    this -> position = position;  // Inicializa a posição do bloco
}

// Método para desenhar o bloco na tela
void Bloco::Draw()
{
    // Desenha um retângulo azul representando o bloco com tamanho 3x3
    DrawRectangle(position.x, position.y, 3, 3, {73, 116, 255, 255});
}

// Método para retornar o retângulo de colisão do bloco
Rectangle Bloco::getRect()
{
    Rectangle rect;
    rect.x = position.x;    // Atribui a posição x do bloco
    rect.y = position.y;    // Atribui a posição y do bloco
    rect.width = 3;          // Atribui a largura do bloco (3)
    rect.height = 3;         // Atribui a altura do bloco (3)
    return rect;             // Retorna o retângulo de colisão
}