#include "estreladamorte.hpp"

// Construtor da classe EstrelaDaMorte
EstrelaDaMorte::EstrelaDaMorte() {
    // Carrega a textura da Estrela da Morte a partir do arquivo
    image = LoadTexture("./Graphics/deathstar.png");
    // Inicializa o estado da Estrela da Morte como 'viva' sendo falsa (não ativa no início)
    viva = false;
}

// Destruidor da classe EstrelaDaMorte
EstrelaDaMorte::~EstrelaDaMorte() {
    // Libera a memória da textura da Estrela da Morte
    UnloadTexture(image);
}

// Função que faz a Estrela da Morte aparecer na tela
void EstrelaDaMorte::Spawn() {
    // Define a posição inicial da Estrela da Morte na vertical
    position.y = 70;

    // Sorteia aleatoriamente se a Estrela da Morte aparecer à esquerda ou à direita
    int lado = GetRandomValue(0, 1);

    // Se lado for 0, ela aparece à esquerda
    if(lado == 0) {
        position.x = 25;
        velocidade = 3; // Move para a direita
    } 
    // Se lado for 1, ela aparece à direita
    else {
        position.x = GetScreenWidth() - image.width - 25;
        velocidade = -3; // Move para a esquerda
    }

    // Marca a Estrela da Morte como viva, ou seja, ela começa a se mover
    viva = true;
}

// Retorna o retângulo que representa a área ocupada pela Estrela da Morte
Rectangle EstrelaDaMorte::getRect() {
    // Se a Estrela da Morte estiver viva, retorna o retângulo que ocupa na tela
    if(viva){
        return {position.x, position.y, float(image.width), float(image.height)};
    } 
    // Se não estiver viva, retorna um retângulo com largura e altura 0
    else {
        return {position.x, position.y, 0, 0};
    }
}

// Atualiza a posição da Estrela da Morte a cada quadro
void EstrelaDaMorte::Update() {
    // Se a Estrela da Morte estiver viva, ela se move horizontalmente
    if(viva) {
        position.x += velocidade;

        // Verifica se a Estrela da Morte saiu da tela
        // Se saiu da tela (à esquerda ou à direita), marca como 'viva = false'
        if(position.x > GetScreenWidth() - image.width - 25 || position.x < 25) {
            viva = false;
        }
    }
}

// Desenha a Estrela da Morte na tela
void EstrelaDaMorte::Draw() {
    // Se a Estrela da Morte estiver viva, desenha a imagem dela
    if(viva) {
        DrawTextureV(image, position, WHITE);
    }
}