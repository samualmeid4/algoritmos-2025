#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_TITULO = 100;
const int MAX_LIVROS = 50;

void lerLivros(const char *arquivoEntrada, char (*titulos)[MAX_TITULO], int *codigos, int *emprestimos, int *numLivros) {
    ifstream entrada(arquivoEntrada);
    if (!entrada.is_open()) {
        cout << "Erro ao abrir arquivo " << arquivoEntrada << endl;
        exit(1);
    }

    *numLivros = 0;

    while (entrada >> codigos[*numLivros]) {
        entrada.ignore();  
        entrada.getline(titulos[*numLivros], MAX_TITULO);
        emprestimos[*numLivros] = 0; 
        (*numLivros)++;

    }

    entrada.close();
}


int buscarLivro(int codigoBusca, int *codigos, int numLivros) {
    for (int i = 0; i < numLivros; i++) {
        if (codigos[i] == codigoBusca) {
            if (i == numLivros - 1) {
                return -1;
            }
            return i;
        }
    }
    return -1;
}

void registrarEmprestimo(int *emprestimos, int indice) {
    emprestimos[indice]++;
}

void imprimirLivros(char (*titulos)[MAX_TITULO], int *codigos, int *emprestimos, int numLivros) {
   for (int i = 0; i < numLivros; i++) {
        cout << codigos[i] << " " << titulos[i] << "" << emprestimos[i] << endl;
    }

    
}


int main() {
    char titulos[MAX_LIVROS][MAX_TITULO];
    int codigos[MAX_LIVROS];
    int emprestimos[MAX_LIVROS];
    int numLivros;
    char arquivoEntrada[] = "livros.txt";
    char arquivoSaida[] = "emprestimos.txt";


    lerLivros(arquivoEntrada, titulos, codigos, emprestimos, &numLivros);

    imprimirLivros(titulos, codigos, emprestimos, numLivros);


    char continuar;
    do {
        int codigoBusca, indice;
        cout << "Digite o codigo do livro para emprestar: ";
        cin >> codigoBusca;

        indice = buscarLivro(codigoBusca, codigos, numLivros);

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
        
        imprimirLivros(titulos, codigos, emprestimos, numLivros);

        cout << "Deseja registrar outro emprestimo (s/n)? ";
        cin >> continuar;

    } while (continuar != 'n');

    return 0;
}
