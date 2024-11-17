#pragma once
#include <raylib.h>

class Bloco {
    public:
        // Construtor da classe Bloco, que recebe a posição inicial do bloco
        Bloco(Vector2 position);
        
        // Método para desenhar o bloco na tela
        void Draw();
        
        // Método para retornar o retângulo de colisão do bloco
        Rectangle getRect();

    private:
        // Variável que armazena a posição do bloco na tela
        Vector2 position;
};