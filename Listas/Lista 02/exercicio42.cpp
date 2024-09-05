//------------------------------------------------------------------------------
// Exercício 42: Números de 1 a 20
//
// Escreva um programa que imprima na tela os números de 1 a 20, um abaixo do
// outro. Depois modifique o programa para que ele mostre os números um ao lado
// do outro.
//
//------------------------------------------------------------------------------

#include<iostream>
#include<clocale>

//------------------------------------------------------------------------------
//                              Função Principal
//------------------------------------------------------------------------------

int main() {

    // Define uma variável para armazenar a escolha do usuário:
    int opcao;

    // Configura a língua como PT-BR:
    std::setlocale(LC_ALL, "portuguese");

    // Exibe o menu do programa:
    std::cout << "=================================================\n";
    std::cout << "                 exercicio42.cpp                 \n";
    std::cout << "=================================================\n\n";

    // Exibe o menu de opções para o usuário:
    std::cout << "Escolha como deseja exibir os números de 1 a 20:\n";
    std::cout << "1 - Um abaixo do outro\n";
    std::cout << "2 - Um ao lado do outro\n\n";
    std::cout << ">> Digite sua escolha (1 ou 2): ";
    std::cin >> opcao;

    std::cout << "\n";

    // Verifica a escolha do usuário e exibe os números conforme selecionado:
    if (opcao == 1) {
        // Imprime os números de 1 a 20, um abaixo do outro:
        std::cout << "Números de 1 a 20, um abaixo do outro:\n";
        for (int i = 1; i <= 20; i++) {
            std::cout << i << "\n";
        }
    } else if (opcao == 2) {
        // Imprime os números de 1 a 20, um ao lado do outro:
        std::cout << "Números de 1 a 20, um ao lado do outro:\n";
        for (int i = 1; i <= 20; i++) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    } else {
        // Caso o usuário digite uma opção inválida:
        std::cout << "Opção inválida. Tente novamente.\n";
    }

    // Finaliza o programa:
    std::cout << "\n\n=> Tecle <Enter> para encerrar o programa... ";
    std::cin.get();
    return 0;
}
