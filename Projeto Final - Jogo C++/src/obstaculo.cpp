#include "obstaculo.hpp"

// Inicializa a tabela estática que define a forma do obstáculo.
// Cada "1" representa um bloco, e "0" representa espaços vazios.
std::vector<std::vector<int>> Obstaculo::tabela = {
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1}
};

Obstaculo::Obstaculo(Vector2 position) {
    this->position = position; 
    // Define a posição inicial do obstáculo.

    // Itera sobre a tabela estática para criar os blocos correspondentes.
    for (unsigned int linha = 0; linha < tabela.size(); ++linha) {
        for (unsigned int coluna = 0; coluna < tabela[0].size(); ++coluna) {
            if (tabela[linha][coluna] == 1) {
                // Calcula a posição do bloco baseado na linha, coluna e posição inicial do obstáculo.
                float pos_x = position.x + coluna * 3; // Espaçamento de 3 pixels por coluna.
                float pos_y = position.y + linha * 3;  // Espaçamento de 3 pixels por linha.
                Bloco bloco = Bloco({pos_x, pos_y});   // Cria o bloco na posição calculada.
                blocos.push_back(bloco);              // Adiciona o bloco ao vetor.
            }
        }
    }
}

void Obstaculo::Draw() {
    // Desenha todos os blocos que compõem o obstáculo.
    for (auto& bloco : blocos) {
        bloco.Draw();
    }
}