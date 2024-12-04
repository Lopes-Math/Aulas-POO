#include "collectible.hpp"

// Diretório da aplicação
extern char *appDir;

// Construtor: carrega a textura e define a posição inicial
Collectible::Collectible() {
    texture = LoadTexture(TextFormat("%s/assets/images/coin.png", appDir));
    position.x = GetRandomValue(0, GetScreenWidth() - texture.width);
    position.y = GetRandomValue(0, GetScreenHeight() - texture.height);
    radius = 20.0f; // Define o raio do círculo de colisão
}

// Destrutor: libera os recursos
Collectible::~Collectible() {
    UnloadTexture(texture);
}

// Desenha o item na tela
void Collectible::Draw() const {
    DrawTexture(texture, position.x, position.y, WHITE);

    // Renderiza o círculo de colisão (para debug)
    /*
    DrawCircle(
        position.x + texture.width / 2.0f,
        position.y + texture.height / 2.0f,
        radius,
        {0, 255, 0, 100}
    );
    */
}

// Atualiza o item
void Collectible::Update() {
    // Os itens podem ter uma lógica adicional no futuro
}

// Verifica colisão com o jogador
bool Collectible::checkCollision(const Player& player) const {
    return CheckCollisionCircles(
        {position.x + texture.width / 2.0f, position.y + texture.height / 2.0f},
        radius,
        player.getPosition(),
        player.getRadius()
    );
}