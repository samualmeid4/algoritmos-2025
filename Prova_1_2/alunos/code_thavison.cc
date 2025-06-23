#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_TITULO = 100;
const int MAX_LIVROS = 50;

void lerLivros() {
    ifstream livros("livros.txt");
}

void buscarLivro() {

}

void registrarEmprestimo() {

}

void imprimirLivros() {

}

int main() {
    char titulos[MAX_LIVROS][MAX_TITULO];
    int codigos[MAX_LIVROS];
    int emprestimos[MAX_LIVROS];
    int numLivros;
    char nomeArquivo[] = "livros.txt";

    lerLivros();
    imprimirLivros();

    char continuar;
    do {
        int codigoBusca, indice;
        cout << "Digite o codigo do livro para emprestar: ";
        cin >> codigoBusca;

        buscarLivro();

        if (indice == -1) {
            cout << "Livro nao encontrado.\n";
        } else {
            registrarEmprestimo();
            cout << "Emprestimo registrado para: " << titulos[indice] << endl;

            ofstream saida("emprestimos.txt", ios::app);
            if (saida.is_open()) {
                saida << codigos[indice] << " - " << titulos[indice] << endl;
                saida.close();
            }
        }

        imprimirLivros();
        cout << "Deseja registrar outro emprestimo (s/n)? ";
        cin >> continuar;

    } while (continuar != 'n');

    return 0;
}