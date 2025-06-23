#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_TITULO = 100;
const int MAX_LIVROS = 50;

void lerLivros(int* codigos, string* titulos, bool* emprestado) {
    codigos[0] = 101;
    titulos[0] = "O Pequeno Príncipe";
    emprestado[0] = false;

    codigos[1] = 102;
    titulos[1] = "Dom Quixote";
    emprestado[1] = false;

    codigos[2] = 103;
    titulos[2] = "1984";
    emprestado[2] = false;
}

int buscarLivro(int* codigos, string* titulos, bool* emprestado, int tamanho, int codigoBuscar) {
    for (int i = 0; i < tamanho; i++) {
        if (*(codigos + i) == codigoBuscar) {
            cout << "Livro encontrado!\n";
            cout << "Título: " << *(titulos + i) << "\n";
            cout << "Status: " << (*(emprestado + i) ? "Emprestado" : "Disponível") << "\n";
            return i;
        }
    }
    return -1;
}

void registrarEmprestimo(bool* emprestado, int indice) {
    if (!emprestado[indice]){
        emprestado[indice] = true;
        cout << "emprestimo resgistrado com sucesso.\n";
    }else {
        cout << "livro já esta eprestado";
    }
}

void imprimirLivros(int* codigos, string* titulos, bool* emprestado, int tamanho) {
    cout << "\nLista de livros:\n";
    for (int i = 0; i< tamanho; i++) {
        cout << "Codigo: " << codigos[i]
        << " Titulo: " <<titulos[i]
        << " Emprestimos: " <<(emprestado[i] ? "Emprestado" : "Disponivel") <<"\n";
    }
}

int main() {
    string titulos[MAX_LIVROS];
    int codigos[MAX_LIVROS];
    bool emprestimos[MAX_LIVROS];
    int numLivros =3;
    char nomeArquivo[] = "livros.txt";

    lerLivros(codigos, titulos, emprestimos);
    imprimirLivros(codigos, titulos, emprestimos, numLivros);

    char continuar;
    do {
        int codigoBusca, indice;
        cout << "Digite o codigo do livro para emprestar: ";
        cin >> codigoBusca;

        indice = buscarLivro(codigos, titulos, emprestimos, numLivros, codigoBusca);

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
        cout << "Deseja registrar outro emprestimo (s/n)? ";
        cin >> continuar;

    } while (continuar != 'n');

    return 0;
}
