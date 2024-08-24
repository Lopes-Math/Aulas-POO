//------------------------------------------------------------------------------
// Exercício 22: Cálculo de Média Escolar
//
// Escreva um programa que receba a entrada de duas notas parciais obtidas por
// um aluno em uma disciplina ao longo de um semestre e calcule a sua media.
// O programa deve exibir na tela as notas, a media, o conceito correspondente e
// a mensagem "APROVADO" se o conceito for A, B ou C ou "REPROVADO" se o
// conceito for D ou E. A atribuição de conceitos obedece aos dados apresentados
// abaixo.
//
//                       Média de Aproveitamento Conceito
//                          Entre 9.0 e 10.0	     A
//                          Entre 7.5 e 9.0	     B
//                          Entre 6.0 e 7.5	     C
//                          Entre 4.0 e 6.0	     D
//                          Entre 4.0 e zero	     E
//------------------------------------------------------------------------------

#include<iostream>
#include<iomanip>
#include<clocale>

//------------------------------------------------------------------------------
//                              Função Principal
//------------------------------------------------------------------------------

int main(void) {

    // Declaração de Variáveis:
    float n1, n2, media;
    char conceito;

    // Configura a língua como PT-BR:
    std::setlocale(LC_ALL, "portuguese");

    // Exibe o menu do programa
    std::cout << "=================================================\n";
    std::cout << "                 exercício22.cpp                 \n";
    std::cout << "=================================================\n\n";

    // Entrada das duas notas parciais obtidas pelo aluno:
    std::cout << "=> Insira a primeira nota parcial do aluno: ";
    std::cin >> n1;
    std::cin.ignore(80, '\n');

    std::cout << "=> Insira a segunda nota parcial do aluno.: ";
    std::cin >> n2;
    std::cin.ignore(80, '\n');

    std::cout << "\n";

    // Calculo da média com base nas notas informadas:
    media = (n1 + n2) / 2;

    // Atribuição do Conceito com base na média do aluno:
    if (media >= 9.0 && media <= 10.0) {
        conceito = 'A';
    } else if (media >= 7.5 && media < 9.0) {
        conceito = 'B';
    } else if (media >= 6.0 && media < 7.5) {
        conceito = 'C';
    } else if (media >= 4.0 && media < 6.0) {
        conceito = 'D';
    } else {
        conceito = 'E';
    }

    // Define duas casas decimais após o ponto flutuante e fixa o ponto:
    std::cout << std::setprecision(2);
    std::cout << std::fixed;

    // Exibição das notas, da média, do conceito correspondente :
    std::cout << "================================================\n\n";
    std::cout << "-> Nota Parcial 1...: " << n1 << "\n";
    std::cout << "-> Nota Parcial 2...: " << n2 << "\n";
    std::cout << "-> Média obtida.....: " << media << "\n";
    std::cout << "-> Conceito do aluno: " << conceito << "\n\n";
    std::cout << "=================================================\n\n";

    // Exibição da mensagem "APROVADO" ou "REPROVADO", de acordo com o
    // conceito:
    if (conceito == 'A' || conceito == 'B' || conceito == 'C') {
        std::cout << "-------------------- APROVADO -------------------\n";
    } else {
        std::cout << "-------------------- REPROVADO ------------------\n";
    }

    // Finaliza o programa:
    std::cout << "\n\n=> Tecle <Enter> para encerrar o programa... ";
    std::cin.get();
    return 0;
}
