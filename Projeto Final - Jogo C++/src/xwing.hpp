#pragma once
#include <raylib.h>
#include "laser.hpp"
#include <vector>

class Xwing {
    public:
        Xwing(); 
        // Construtor: inicializa o Xwing.

        ~Xwing(); 
        // Destrutor: limpa recursos alocados pela classe.

        void Draw(); 
        // Desenha o Xwing na tela.

        void MoverEsquerda(); 
        // Move o Xwing para a esquerda.

        void MoverDireita(); 
        // Move o Xwing para a direita.

        void AtirarLaser(); 
        // Cria e dispara um laser da posição do Xwing.

        Rectangle getRect(); 
        // Retorna o retângulo de colisão do Xwing.

        void Reiniciar(); 
        // Restaura o estado inicial do Xwing.

        std::vector<Laser> lasers; 
        // Vetor que armazena os lasers disparados.

    private:
        Texture2D image; 
        // Textura do Xwing.

        Vector2 position; 
        // Posição do Xwing.

        double tempoUltimoTiro; 
        // Tempo do último disparo, usado para controlar o intervalo entre tiros.

        Sound somlaser; 
        // Som associado ao disparo.
};