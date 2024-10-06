//-----------------------------------------------------------------------------
// Exemplo 81: O Craps � um jogo de azar que n�o pode faltar em um cassino que
// se preze. Ele � considerado um dos mais cl�ssicos jogos de mesa, sendo bem
// simples de ser entendido. Nesse jogo, os jogadores apostam nos resultados do
// lan�amento de um par de dados. Existem muitos tipos de apostas poss�veis no
// Craps. O vencedor da rodada � determinado pela soma dos resultados dos dados
// lan�ados, associados aos tipos de apostas poss�veis. Um tipo de aposta �
// denominado de Aposta de Linha de Passe, ou Pass-Line. Quando um jogador faz
// uma aposta de linha de passe, ele est� apostando que o resultado dos dados
// no lan�amento inicial ser� 7 ou 11. Se isso ocorrer, cada jogador que tenha
// feito esta aposta receber� o dobro do valor apostado. Caso o valor dos dados
// lan�ados seja 2, 3 ou 12, significa que o jogador fez um Craps. Caso isso
// ocorra, ele perde. Se a soma dos dados for 4, 5, 6, 8, 9 ou 10, o jogador
// recebe 1 ponto e lan�a os dados novamente. Se o resultado for 7, ele vence;
// se for outro n�mero, os outros jogadores ganham.

// Escreva um programa para implementar um jogo de Craps. O usu�rio jogar�
// contra o computador. Ele dever� fornecer um valor que corresponde a sua
// banca inicial. Em seguida, o programa deve iniciar o jogo. Utilize uma
// estrutura de repeti��o para permitir que o jogador continue jogando at�
// perder todo o seu dinheiro ou pressione uma tecla para parar de jogar.
//-----------------------------------------------------------------------------

#include<iostream>
#include<clocale>

//-----------------------------------------------------------------------------
//                          Declara��o das Fun��es
//-----------------------------------------------------------------------------


// Lan�a dois dados e retorna a soma
int lancarDados() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

// Controla o fluxo do jogo, permitindo ao jogador fazer apostas at� que a
// banca chegue a zero ou que decida sair
void jogoCraps(float &banca) {
    while (banca > 0) {
        std::cout << "Sua banca: $" << banca << std::endl;
        int aposta;
        std::cout << "\nDigite o valor da sua aposta (ou 0 para sair): ";
        std::cin >> aposta;

        if (aposta == 0) {
            std::cout << "Voc� saiu do jogo." << std::endl;
            break;
        } else if (aposta > banca) {
            std::cout << "Voc� n�o pode apostar mais do que tem na banca." << std::endl;
            continue;
        }

        int resultadoInicial = lancarDados();
        std::cout << "\nResultado do lan�amento dos dados inicial: " << resultadoInicial << std::endl;

        if (resultadoInicial == 7 || resultadoInicial == 11) {
            std::cout << "Voc� venceu! Ganhou $" << aposta << "." << std::endl;
            banca += aposta * 2;
        } else if (resultadoInicial == 2 || resultadoInicial == 3 || resultadoInicial == 12) {
            std::cout << "Craps! Voc� perdeu $" << aposta << "." << std::endl;
            banca -= aposta;
        } else {
            int ponto = resultadoInicial;
            std::cout << "Ponto estabelecido: " << ponto << ". Lan�ando novamente..." << std::endl;

            while (true) {
                int resultado = lancarDados();
                std::cout << "\nResultado do novo lan�amento dos dados: " << resultado << std::endl;

                if (resultado == 7) {
                    std::cout << "\nVoc� venceu! Ganhou $" << aposta << "." << std::endl;
                    banca += aposta;
                    break;
                } else if (resultado != 7) {
                    std::cout << "Voc� perdeu! Perdeu $" << aposta << "." << std::endl;
                    banca -= aposta;
                    break;
                } else {
                    std::cout << "Resultado n�o decisivo. Lan�ando os dados novamente..." << std::endl;
                }
            }
        }
    }

    std::cout << "\nFim do jogo." << std::endl;
}

//-----------------------------------------------------------------------------
//                              Fun��o Principal
//-----------------------------------------------------------------------------

int main() {
    float bancaInicial;

    std::setlocale(LC_ALL, "portuguese");

    std::cout << "======================================================\n";
    std::cout << "                 Bem Vindo ao Craps!!!                \n";
    std::cout << "======================================================\n";

    std::cout << "Digite sua banca inicial: ";
    std::cin >> bancaInicial;

    // Inicializa o gerador de n�meros aleat�rios
    srand(42); // Usando uma semente fixa para reprodu��o de resultados

    jogoCraps(bancaInicial);
    return 0;
}
