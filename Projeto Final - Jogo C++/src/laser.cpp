#include "laser.hpp"
#include <iostream>

// Implementação do construtor da classe Laser.
Laser::Laser(Vector2 position, int speed)
{
    this->position = position; // Inicializa a posição do laser.
    this->speed = speed;       // Define a velocidade de deslocamento.
    ativo = true;              // Define o laser como ativo inicialmente.
}

// Método para desenhar o laser na tela.
void Laser::Draw() {
    if (ativo) { 
        // Desenha um retângulo vermelho na posição do laser, se estiver ativo.
        DrawRectangle(position.x, position.y, 4, 15, {255, 0, 0, 255});
    }
}

// Método para obter o retângulo de colisão do laser.
Rectangle Laser::getRect()
{
    Rectangle rect;
    rect.x = position.x;     // Define a coordenada x do retângulo.
    rect.y = position.y;     // Define a coordenada y do retângulo.
    rect.width = 4;          // Largura fixa do laser.
    rect.height = 15;        // Altura fixa do laser.
    return rect;             // Retorna o retângulo.
}

// Método para atualizar a posição do laser e verificar seu status.
void Laser::Update() {
    position.y += speed; // Atualiza a posição vertical com base na velocidade.

    if (ativo) { 
        // Verifica se o laser saiu da área ativa da tela.
        if (position.y > GetScreenHeight() - 100 || position.y < 25) {
            ativo = false; // Desativa o laser se estiver fora dos limites.
        }
    }
}