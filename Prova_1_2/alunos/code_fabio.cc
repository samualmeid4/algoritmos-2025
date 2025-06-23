#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_TITULO = 100;
const int MAX_LIVROS = 50;

void lerLivros(int codigos[], char titulos[][MAX_TITULO], int emprestimos[], int* numLivros) {
    ifstream arquivo("livros.txt");
    *numLivros = 0;

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo livros.txt" << endl;
        exit(1);
    }

    while (arquivo >> codigos[*numLivros]) {
        arquivo.get(); // Consome o espaço após o código
        arquivo.getline(titulos[*numLivros], MAX_TITULO);
        emprestimos[*numLivros] = 0;
        (*numLivros)++;
    }

    arquivo.close();
}

int buscarLivro(int codigos[], int numLivros, int codigoBusca) {
    for (int i = 0; i < numLivros; i++) {
        if (codigos[i] == codigoBusca) return i;
    }
    return -1;
}

void registrarEmprestimo(int emprestimos[], int indice) {
    emprestimos[indice]++;
}

void imprimirLivros(int codigos[], char titulos[][MAX_TITULO], int emprestimos[], int numLivros) {
    cout << "\n===== LIVROS ATUALIZADOS =====\n";
    for (int i = 0; i < numLivros; i++) {
        cout << codigos[i] << " - " << titulos[i]
             << " | Emprestimos: " << emprestimos[i] << endl;
    }
    cout << "==============================\n";
}

int main() {
    char titulos[MAX_LIVROS][MAX_TITULO];
    int codigos[MAX_LIVROS];
    int emprestimos[MAX_LIVROS];
    int numLivros;
    char nomeArquivo[] = "livros.txt";

    lerLivros(codigos, titulos, emprestimos, &numLivros);
    imprimirLivros(codigos, titulos, emprestimos, numLivros);

    char continuar;
    do {
        int codigoBusca, indice;
        cout << "\nDigite o codigo do livro para emprestar: ";
        cin >> codigoBusca;

        indice = buscarLivro(codigos, numLivros, codigoBusca);

        if (indice == -1) {
            cout << "Livro nao encontrado.\n";
        } else {
            registrarEmprestimo(emprestimos, indice);
            cout << "Emprestimo registrado para: " << titulos[indice] << endl;

            ofstream saida("emprestimos.txt", ios::app);
            if (saida.is_open()) {
                saida << codigos[indice] << " - " << titulos[indice] << endl;
                saida.close();
            }
        }

        imprimirLivros(codigos, titulos, emprestimos, numLivros);
        cout << "\nDeseja registrar outro emprestimo (s/n)? ";
        cin >> continuar;

    } while (continuar != 'n' && continuar != 'N');

    cout << "Programa encerrado. Até logo!\n";
    return 0;
}
