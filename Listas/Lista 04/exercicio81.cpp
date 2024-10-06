//-----------------------------------------------------------------------------
// Exemplo 81: O Craps é um jogo de azar que não pode faltar em um cassino que
// se preze. Ele é considerado um dos mais clássicos jogos de mesa, sendo bem
// simples de ser entendido. Nesse jogo, os jogadores apostam nos resultados do
// lançamento de um par de dados. Existem muitos tipos de apostas possíveis no
// Craps. O vencedor da rodada é determinado pela soma dos resultados dos dados
// lançados, associados aos tipos de apostas possíveis. Um tipo de aposta é
// denominado de Aposta de Linha de Passe, ou Pass-Line. Quando um jogador faz
// uma aposta de linha de passe, ele está apostando que o resultado dos dados
// no lançamento inicial será 7 ou 11. Se isso ocorrer, cada jogador que tenha
// feito esta aposta receberá o dobro do valor apostado. Caso o valor dos dados
// lançados seja 2, 3 ou 12, significa que o jogador fez um Craps. Caso isso
// ocorra, ele perde. Se a soma dos dados for 4, 5, 6, 8, 9 ou 10, o jogador
// recebe 1 ponto e lança os dados novamente. Se o resultado for 7, ele vence;
// se for outro número, os outros jogadores ganham.

// Escreva um programa para implementar um jogo de Craps. O usuário jogará
// contra o computador. Ele deverá fornecer um valor que corresponde a sua
// banca inicial. Em seguida, o programa deve iniciar o jogo. Utilize uma
// estrutura de repetição para permitir que o jogador continue jogando até
// perder todo o seu dinheiro ou pressione uma tecla para parar de jogar.
//-----------------------------------------------------------------------------

#include<iostream>
#include<clocale>

//-----------------------------------------------------------------------------
//                          Declaração das Funções
//-----------------------------------------------------------------------------


// Lança dois dados e retorna a soma
int lancarDados() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

// Controla o fluxo do jogo, permitindo ao jogador fazer apostas até que a
// banca chegue a zero ou que decida sair
void jogoCraps(float &banca) {
    while (banca > 0) {
        std::cout << "Sua banca: $" << banca << std::endl;
        int aposta;
        std::cout << "\nDigite o valor da sua aposta (ou 0 para sair): ";
        std::cin >> aposta;

        if (aposta == 0) {
            std::cout << "Você saiu do jogo." << std::endl;
            break;
        } else if (aposta > banca) {
            std::cout << "Você não pode apostar mais do que tem na banca." << std::endl;
            continue;
        }

        int resultadoInicial = lancarDados();
        std::cout << "\nResultado do lançamento dos dados inicial: " << resultadoInicial << std::endl;

        if (resultadoInicial == 7 || resultadoInicial == 11) {
            std::cout << "Você venceu! Ganhou $" << aposta << "." << std::endl;
            banca += aposta * 2;
        } else if (resultadoInicial == 2 || resultadoInicial == 3 || resultadoInicial == 12) {
            std::cout << "Craps! Você perdeu $" << aposta << "." << std::endl;
            banca -= aposta;
        } else {
            int ponto = resultadoInicial;
            std::cout << "Ponto estabelecido: " << ponto << ". Lançando novamente..." << std::endl;

            while (true) {
                int resultado = lancarDados();
                std::cout << "\nResultado do novo lançamento dos dados: " << resultado << std::endl;

                if (resultado == 7) {
                    std::cout << "\nVocê venceu! Ganhou $" << aposta << "." << std::endl;
                    banca += aposta;
                    break;
                } else if (resultado != 7) {
                    std::cout << "Você perdeu! Perdeu $" << aposta << "." << std::endl;
                    banca -= aposta;
                    break;
                } else {
                    std::cout << "Resultado não decisivo. Lançando os dados novamente..." << std::endl;
                }
            }
        }
    }

    std::cout << "\nFim do jogo." << std::endl;
}

//-----------------------------------------------------------------------------
//                              Função Principal
//-----------------------------------------------------------------------------

int main() {
    float bancaInicial;

    std::setlocale(LC_ALL, "portuguese");

    std::cout << "======================================================\n";
    std::cout << "                 Bem Vindo ao Craps!!!                \n";
    std::cout << "======================================================\n";

    std::cout << "Digite sua banca inicial: ";
    std::cin >> bancaInicial;

    // Inicializa o gerador de números aleatórios
    srand(42); // Usando uma semente fixa para reprodução de resultados

    jogoCraps(bancaInicial);
    return 0;
}
