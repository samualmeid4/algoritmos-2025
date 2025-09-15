#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_TITULO = 100;
const int MAX_LIVROS = 50;

void lerLivros(char* nomeArquivo, char titulos[][MAX_TITULO], int* codigos, int* emprestimos, int* numLivros) {
    ifstream entrada(nomeArquivo);
    if (!entrada.is_open()) {
        cout << "Erro ao abrir arquivo: " << nomeArquivo << endl;
        exit(1);
    }

    *numLivros = 0;
    while (entrada >> codigos[*numLivros]) {
        entrada.ignore(); // Ignora o espaço após o código
        entrada.getline(titulos[*numLivros], MAX_TITULO);
        emprestimos[*numLivros] = 0;
        (*numLivros)++;
    }
    entrada.close();
}

int buscarLivro(int codigoBusca, int* codigos, int numLivros) {
    for (int i = 0; i < numLivros; i++) {
        if (codigos[i] == codigoBusca) {
            return i;
        }
    }
    return -1; // Não encontrado
}

void registrarEmprestimo(int indice, int* emprestimos) {
    emprestimos[indice]++;
}

void imprimirLivros(char titulos[][MAX_TITULO], int* codigos, int* emprestimos, int numLivros) {
    cout << "\n===== Livros na Biblioteca =====\n";
    for (int i = 0; i < numLivros; i++) {
        cout << codigos[i] << " - " << titulos[i] << " (" << emprestimos[i] << " emprestimos)" << endl;
    }
    cout << "===============================\n\n";
}

int main() {
    char titulos[MAX_LIVROS][MAX_TITULO];
    int codigos[MAX_LIVROS];
    int emprestimos[MAX_LIVROS];
    int numLivros;
    char nomeArquivo[] = "livros.txt";

    lerLivros(nomeArquivo, titulos, codigos, emprestimos, &numLivros);
    imprimirLivros(titulos, codigos, emprestimos, numLivros);

    char continuar;
    do {
        int codigoBusca;
        cout << "Digite o codigo do livro para emprestar: ";
        cin >> codigoBusca;

        int indice = buscarLivro(codigoBusca, codigos, numLivros);

        if (indice == -1) {
            cout << "Livro nao encontrado.\n";
        } else {
            registrarEmprestimo(indice, emprestimos);
            cout << "Emprestimo registrado para: " << titulos[indice] << endl;

            ofstream saida("emprestimos.txt", ios::app);
            if (saida.is_open()) {
                saida << codigos[indice] << " - " << titulos[indice] << endl;
                saida.close();
            } else {
                cout << "Erro ao abrir arquivo de emprestimos.\n";
            }
        }

        imprimirLivros(titulos, codigos, emprestimos, numLivros);
        cout << "Deseja registrar outro emprestimo (s/n)? ";
        cin >> continuar;

    } while (continuar != 'n');

    return 0;
}
