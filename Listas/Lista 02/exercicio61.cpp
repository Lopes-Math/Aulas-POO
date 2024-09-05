//------------------------------------------------------------------------------
// Exercício 61: Votação
//
// Neste ano teremos uma eleição para escolher o prefeito da cidade, onde 5
// candidatos estão concorrendo:
//
// 1. Chuck Norris
// 2. Van Damme
// 3. Walter Paraíba
// 4. Relíquia
// 5. João Bombadão
//
// Escreva um programa que solicite a entrada do número total de eleitores. Em
// seguida, peça que cada eleitor vote. O programa deve apresentar um resultado,
// exibindo o número de votos obtido por cada candidato. Considere que o eleitor
// também pode votar em branco ou anular seu voto.
//
//------------------------------------------------------------------------------

#include<iostream>
#include<clocale>

//------------------------------------------------------------------------------
//                              Função Principal
//------------------------------------------------------------------------------

int main() {

    // Declara as variáveis para Total de Eleitores, para os votos nos
    // candidatos, votos brancos, e votos nulos:
    int totalEleitores;
    int votosChuck = 0, votosVan = 0, votosParaiba = 0, votosReliquia = 0, votosBombadao = 0;
    int votosBrancos = 0, votosNulos = 0;
    int voto;

    // Configura a língua como PT-BR:
    std::setlocale(LC_ALL, "portuguese");

    // Exibe o menu do programa:
    std::cout << "=================================================\n";
    std::cout << "                 exercicio61.cpp                 \n";
    std::cout << "=================================================\n\n";

    // Solicita o número total de eleitores:
    std::cout << ">> Digite o número total de eleitores: ";
    std::cin >> totalEleitores;

    // Solicita a entrada do voto de cada um dos eleitores:
    for (int i = 1; i <= totalEleitores; i++) {
        std::cout << "\n* Eleitor " << i << ", vote em um candidato (1-5), \nbranco (6) ou nulo (7):\n\n";
        std::cout << "1. Chuck Norris\n";
        std::cout << "2. Van Damme\n";
        std::cout << "3. Walter Paraíba\n";
        std::cout << "4. Relíquia\n";
        std::cout << "5. João Bombadão\n";
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
                std::cout << "Voto inválido!\n";
                break;
        }
    }

    // Exibe os resultados da votação com singular/plural:
    std::cout << "\nResultado da votação:\n\n";

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
        std::cout << "3. Walter Paraíba: " << votosParaiba << " voto\n";
    } else {
        std::cout << "3. Walter Paraíba: " << votosParaiba << " votos\n";
    }

    if (votosReliquia == 1) {
        std::cout << "4. Relíquia: " << votosReliquia << " voto\n";
    } else {
        std::cout << "4. Relíquia: " << votosReliquia << " votos\n";
    }

    if (votosBombadao == 1) {
        std::cout << "5. João Bombadão: " << votosBombadao << " voto\n";
    } else {
        std::cout << "5. João Bombadão: " << votosBombadao << " votos\n";
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
