#pragma once
#include <raylib.h>

// Classe que representa a Estrela da Morte no jogo
class EstrelaDaMorte {
    public:
        // Construtor da classe EstrelaDaMorte
        EstrelaDaMorte(); 
        // Destruidor da classe EstrelaDaMorte
        ~EstrelaDaMorte();
        
        // Método de atualização da Estrela da Morte
        void Update();
        
        // Método de renderização (desenho) da Estrela da Morte
        void Draw();
        
        // Método para fazer a Estrela da Morte aparecer no jogo (spawn)
        void Spawn();
        
        // Método que retorna o retângulo da Estrela da Morte (usado para checar colisões)
        Rectangle getRect();
        
        // Atributo que indica se a Estrela da Morte está viva ou destruída
        bool viva;

    private:
        // Posição da Estrela da Morte no jogo
        Vector2 position;
        
        // Imagem da Estrela da Morte
        Texture2D image;
        
        // Velocidade de movimento da Estrela da Morte
        int velocidade;
};