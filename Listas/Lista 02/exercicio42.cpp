//------------------------------------------------------------------------------
// Exerc�cio 42: N�meros de 1 a 20
//
// Escreva um programa que imprima na tela os n�meros de 1 a 20, um abaixo do
// outro. Depois modifique o programa para que ele mostre os n�meros um ao lado
// do outro.
//
//------------------------------------------------------------------------------

#include<iostream>
#include<clocale>

//------------------------------------------------------------------------------
//                              Fun��o Principal
//------------------------------------------------------------------------------

int main() {

    // Define uma vari�vel para armazenar a escolha do usu�rio:
    int opcao;

    // Configura a l�ngua como PT-BR:
    std::setlocale(LC_ALL, "portuguese");

    // Exibe o menu do programa:
    std::cout << "=================================================\n";
    std::cout << "                 exercicio42.cpp                 \n";
    std::cout << "=================================================\n\n";

    // Exibe o menu de op��es para o usu�rio:
    std::cout << "Escolha como deseja exibir os n�meros de 1 a 20:\n";
    std::cout << "1 - Um abaixo do outro\n";
    std::cout << "2 - Um ao lado do outro\n\n";
    std::cout << ">> Digite sua escolha (1 ou 2): ";
    std::cin >> opcao;

    std::cout << "\n";

    // Verifica a escolha do usu�rio e exibe os n�meros conforme selecionado:
    if (opcao == 1) {
        // Imprime os n�meros de 1 a 20, um abaixo do outro:
        std::cout << "N�meros de 1 a 20, um abaixo do outro:\n";
        for (int i = 1; i <= 20; i++) {
            std::cout << i << "\n";
        }
    } else if (opcao == 2) {
        // Imprime os n�meros de 1 a 20, um ao lado do outro:
        std::cout << "N�meros de 1 a 20, um ao lado do outro:\n";
        for (int i = 1; i <= 20; i++) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    } else {
        // Caso o usu�rio digite uma op��o inv�lida:
        std::cout << "Op��o inv�lida. Tente novamente.\n";
    }

    // Finaliza o programa:
    std::cout << "\n\n=> Tecle <Enter> para encerrar o programa... ";
    std::cin.get();
    return 0;
}
