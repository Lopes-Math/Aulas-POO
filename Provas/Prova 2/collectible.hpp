#ifndef COLLECTIBLE_HPP
#define COLLECTIBLE_HPP

#include <raylib.h>
#include "player.hpp"

// Classe que representa itens coletáveis
class Collectible {
    public:
        // Construtor: carrega a textura e define a posição inicial
        Collectible();

        // Destrutor: libera os recursos
        ~Collectible();

        // Desenha o item na tela
        void Draw() const;

        // Atualiza o item
        void Update();

        // Verifica colisão com o jogador
        bool checkCollision(const Player& player) const;

    private:
        Texture2D texture; // Textura do item
        Vector2 position;  // Posição do item na tela
        float radius;      // Raio do círculo de colisão
};

#endif
