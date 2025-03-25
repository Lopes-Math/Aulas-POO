//------------------------------------------------------------------------------------------
//                                       Prova 1
//------------------------------------------------------------------------------------------

#include <iostream>
#include <clocale>
using namespace std;

int main() {
    // Habilita o português:
    setlocale(LC_ALL, "portuguese");

    // Define o vetor que receberá os dados e a variável para armazenar cada valor inserido:
    int dados[100]; // Limite de 100 valores
    int tamanho = 0;
    int dado;

    cout << ">> Início: Prova P1\n";
    cout << "\nInforme os dados: ";

    // O usuário insere os dados, separados por espaço, e aperta Enter ao final
    while (cin >> dado) {
        dados[tamanho] = dado;
        tamanho++;
        if (cin.peek() == '\n') break;
    }

    // Determina o total de colunas (o maior valor no vetor)
    int totalColunas = 0;
    for (int i = 0; i < tamanho; i++) {
        if (dados[i] > totalColunas) {
            totalColunas = dados[i];
        }
    }

    // Exibe os dados inseridos
    cout << "\nDados: [";
    for (int i = 0; i < tamanho; i++) {
        cout << dados[i];
        if (i < tamanho - 1) cout << ", ";
    }
    cout << "]\n";

    // Exibe o total de linhas e colunas
    cout << "\n*Total de linhas: " << tamanho << "\n";
    cout << "*Total de colunas: " << totalColunas << "\n";

    // Mostra o Histograma Horizontal
    cout << "\nHistograma Horizontal\n\n";
    for (int i = 0; i < tamanho; i++) {
        cout << i + 1 << "| ";
        for (int j = 0; j < dados[i]; j++) {
            if (j > 8){
                cout << "*  ";
            } else {
                cout << "* ";
            }
        }
        cout << "\n";
    }

    // Exibe a linha horizontal e os números das colunas abaixo dos traços
    cout << " + ";
    for (int i = 1; i <= totalColunas; i++) {
        if (i > 9){
            cout << "-- ";
        } else {
            cout << "- ";
        }
    }
    cout << "\n ";
    for (int i = 0; i <= totalColunas; i++) {
        cout << i << " ";
    }
    cout << "\n";

    cout << "\n>> Fim: Prova P1\n";
    return 0;
}
