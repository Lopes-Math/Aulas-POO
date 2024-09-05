//------------------------------------------------------------------------------
// Exerc�cio 61: Vota��o
//
// Neste ano teremos uma elei��o para escolher o prefeito da cidade, onde 5
// candidatos est�o concorrendo:
//
// 1. Chuck Norris
// 2. Van Damme
// 3. Walter Para�ba
// 4. Rel�quia
// 5. Jo�o Bombad�o
//
// Escreva um programa que solicite a entrada do n�mero total de eleitores. Em
// seguida, pe�a que cada eleitor vote. O programa deve apresentar um resultado,
// exibindo o n�mero de votos obtido por cada candidato. Considere que o eleitor
// tamb�m pode votar em branco ou anular seu voto.
//
//------------------------------------------------------------------------------

#include<iostream>
#include<clocale>

//------------------------------------------------------------------------------
//                              Fun��o Principal
//------------------------------------------------------------------------------

int main() {

    // Declara as vari�veis para Total de Eleitores, para os votos nos
    // candidatos, votos brancos, e votos nulos:
    int totalEleitores;
    int votosChuck = 0, votosVan = 0, votosParaiba = 0, votosReliquia = 0, votosBombadao = 0;
    int votosBrancos = 0, votosNulos = 0;
    int voto;

    // Configura a l�ngua como PT-BR:
    std::setlocale(LC_ALL, "portuguese");

    // Exibe o menu do programa:
    std::cout << "=================================================\n";
    std::cout << "                 exercicio61.cpp                 \n";
    std::cout << "=================================================\n\n";

    // Solicita o n�mero total de eleitores:
    std::cout << ">> Digite o n�mero total de eleitores: ";
    std::cin >> totalEleitores;

    // Solicita a entrada do voto de cada um dos eleitores:
    for (int i = 1; i <= totalEleitores; i++) {
        std::cout << "\n* Eleitor " << i << ", vote em um candidato (1-5), \nbranco (6) ou nulo (7):\n\n";
        std::cout << "1. Chuck Norris\n";
        std::cout << "2. Van Damme\n";
        std::cout << "3. Walter Para�ba\n";
        std::cout << "4. Rel�quia\n";
        std::cout << "5. Jo�o Bombad�o\n";
        std::cout << "6. Branco\n";
        std::cout << "7. Nulo\n";
        std::cout << ">> Insira o seu voto: ";
        std::cin >> voto;
        std::cout << "================================================";

        // Contabiliza o voto para o candidato escolhido ou branco/nulo:
        switch (voto) {
            case 1:
                votosChuck++;
                break;
            case 2:
                votosVan++;
                break;
            case 3:
                votosParaiba++;
                break;
            case 4:
                votosReliquia++;
                break;
            case 5:
                votosBombadao++;
                break;
            case 6:
                votosBrancos++;
                break;
            case 7:
                votosNulos++;
                break;
            default:
                std::cout << "Voto inv�lido!\n";
                break;
        }
    }

    // Exibe os resultados da vota��o com singular/plural:
    std::cout << "\nResultado da vota��o:\n\n";

    if (votosChuck == 1) {
        std::cout << "1. Chuck Norris: " << votosChuck << " voto\n";
    } else {
        std::cout << "1. Chuck Norris: " << votosChuck << " votos\n";
    }

    if (votosVan == 1) {
        std::cout << "2. Van Damme: " << votosVan << " voto\n";
    } else {
        std::cout << "2. Van Damme: " << votosVan << " votos\n";
    }

    if (votosParaiba == 1) {
        std::cout << "3. Walter Para�ba: " << votosParaiba << " voto\n";
    } else {
        std::cout << "3. Walter Para�ba: " << votosParaiba << " votos\n";
    }

    if (votosReliquia == 1) {
        std::cout << "4. Rel�quia: " << votosReliquia << " voto\n";
    } else {
        std::cout << "4. Rel�quia: " << votosReliquia << " votos\n";
    }

    if (votosBombadao == 1) {
        std::cout << "5. Jo�o Bombad�o: " << votosBombadao << " voto\n";
    } else {
        std::cout << "5. Jo�o Bombad�o: " << votosBombadao << " votos\n";
    }

    // Votos em Branco e Nulos
    if (votosBrancos == 1) {
        std::cout << "Votos em Branco: " << votosBrancos << " voto\n";
    } else {
        std::cout << "Votos em Branco: " << votosBrancos << " votos\n";
    }

    if (votosNulos == 1) {
        std::cout << "Votos Nulos: " << votosNulos << " voto\n";
    } else {
        std::cout << "Votos Nulos: " << votosNulos << " votos\n";
    }

    // Finaliza o programa:
    std::cout << "\n\n=> Tecle <Enter> para encerrar o programa... ";
    std::cin.ignore();
    std::cin.get();
    return 0;
}
