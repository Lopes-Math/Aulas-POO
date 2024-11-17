#pragma once
#include <raylib.h>

// Classe que representa o projétil disparado pela nave (Laser).
class Laser {
    public:
        // Construtor: inicializa a posição e a velocidade do laser.
        Laser(Vector2 position, int speed);

        // Atualiza a posição do laser com base na sua velocidade.
        void Update();

        // Desenha o laser na tela.
        void Draw();

        // Retorna o retângulo de colisão do laser.
        Rectangle getRect();

        // Indica se o laser está ativo (ainda em movimento ou visível).
        bool ativo;

    private:
        // Posição atual do laser na tela.
        Vector2 position;

        // Velocidade de deslocamento vertical do laser.
        int speed;
};