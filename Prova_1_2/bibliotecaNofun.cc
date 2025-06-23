#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_TITULO = 100;
const int MAX_LIVROS = 50;

int main() {
    char titulos[MAX_LIVROS][MAX_TITULO];
    int codigos[MAX_LIVROS];
    int emprestimos[MAX_LIVROS];
    int numLivros = 0;

    // Leitura dos livros a partir do arquivo
    ifstream entrada("livros.txt");
    if (!entrada.is_open()) {
        cout << "Erro ao abrir arquivo: livros.txt" << endl;
        exit(1);
    }

    while (entrada >> codigos[numLivros]) {
        entrada.ignore();  // Ignora espaço após o número
        entrada.getline(titulos[numLivros], MAX_TITULO);
        emprestimos[numLivros] = 0;
        numLivros++;
    }
    entrada.close();

    // Impressão inicial
    cout << "\n===== Livros na Biblioteca =====\n";
    for (int i = 0; i < numLivros; i++) {
        cout << codigos[i] << " - " << titulos[i] << " (" << emprestimos[i] << " emprestimos)" << endl;
    }
    cout << "===============================\n\n";

    // Laço para registrar empréstimos
    char continuar;
    do {
        int codigoBusca, indice = -1;
        cout << "Digite o codigo do livro para emprestar: ";
        cin >> codigoBusca;

        // Busca pelo código
        for (int i = 0; i < numLivros; i++) {
            if (codigos[i] == codigoBusca) {
                indice = i;
                break;
            }
        }

        if (indice == -1) {
            cout << "Livro nao encontrado.\n";
        } else {
            emprestimos[indice]++;
            cout << "Emprestimo registrado para: " << titulos[indice] << endl;

            // Gravação no arquivo de empréstimos
            ofstream saida("emprestimos.txt", ios::app);
            if (saida.is_open()) {
                saida << codigos[indice] << " - " << titulos[indice] << endl;
                saida.close();
            }
        }

        // Impressão atualizada dos livros
        cout << "\n===== Livros na Biblioteca =====\n";
        for (int i = 0; i < numLivros; i++) {
            cout << codigos[i] << " - " << titulos[i] << " (" << emprestimos[i] << " emprestimos)" << endl;
        }
        cout << "===============================\n\n";

        cout << "Deseja registrar outro emprestimo (s/n)? ";
        cin >> continuar;

    } while (continuar != 'n');

    return 0;
}
