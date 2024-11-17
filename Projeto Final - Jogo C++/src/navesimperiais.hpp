#pragma once
#include <raylib.h>

class Nave {
    public:
        Nave(int tipo, Vector2 position);
        // Construtor: inicializa a nave com um tipo específico e uma posição.

        void Update(int direcao);
        // Atualiza a posição da nave com base na direção especificada.
        // A direção é representada como um inteiro (ex.: -1 para esquerda, 1 para direita).

        void Draw();
        // Desenha a nave na tela utilizando a textura correspondente ao tipo.

        int PegarTipo();
        // Retorna o tipo da nave.

        static void DescarregarImagens();
        // Libera os recursos das texturas carregadas para as naves.

        Rectangle getRect();
        // Retorna o retângulo de colisão da nave com base na posição e dimensões da textura.

        static Texture2D naveImagens[3];
        // Array estático que armazena as texturas para os três tipos de naves.

        int tipo;
        // Identifica o tipo da nave (ex.: 0, 1, ou 2).

        Vector2 position;
        // Posição atual da nave na tela.

    private:
};