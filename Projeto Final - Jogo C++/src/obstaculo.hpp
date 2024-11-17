#pragma once
#include <vector>
#include "bloco.hpp"

class Obstaculo {
    public:
        Obstaculo(Vector2 position);
        // Construtor: inicializa o obstáculo na posição especificada.

        void Draw();
        // Desenha o obstáculo e seus blocos na tela.

        Vector2 position;
        // Posição do obstáculo na tela.

        std::vector<Bloco> blocos;
        // Vetor que armazena os blocos que compõem o obstáculo.

        static std::vector<std::vector<int>> tabela;
        // Tabela estática usada para definir a estrutura ou padrão dos blocos no obstáculo.

    private:
};