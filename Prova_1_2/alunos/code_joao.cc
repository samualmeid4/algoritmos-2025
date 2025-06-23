#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int MAX_TITULO = 100;
const int MAX_LIVROS = 50;

void lerLivros(ifstream& arquivo, char (*titulo)[MAX_TITULO],int* codigos, int& numLivros) {
    numLivros = 0;
    while(arquivo >> codigos[numLivros]){
        arquivo.ignore();
        arquivo.getline(titulo[numLivros],MAX_TITULO);
        numLivros++;
    }
}

void buscarLivro(int codigo_busca, int* codigos, int& numLivros) {
   for (int i=0; i< numLivros; i++){
        if (codigo_busca == codigos[i]){
            cout << "Livro encontrado."
        }
   }
}

void registrarEmprestimo() {

}

void imprimirLivros(int& numLivros, char (*titulo)[MAX_TITULO], int* codigos) {
    for (int i = 0;i< numLivros;i++){
        cout << titulo[i] << " " << codigos[i] << endl;
    }
}

int main() {
    char* titulo[MAX_TITULO];
    int* codigos[MAX_LIVROS];
    int emprestimos[MAX_LIVROS];
    int numLivros;
    char nomeArquivo[] = "livros.txt";
    ifstream arquivo("livros.txt");
    if (!arquivo){
        cout << "Nao foi possivel ler" << endl;
        exit(1);
    } 

    lerLivros(arquivo,&titulo[MAX_TITULO],&codigos,numLivros);
    imprimirLivros(numLivros,*titulo[MAX_TITULO],*codigo );

    char continuar;
    do {
        int codigoBusca, indice;
        cout << "Digite o codigo do livro para emprestar: ";
        cin >> codigoBusca;

        buscarLivro(codigoBusca, *codigos,numLivros);

        if (indice == -1) {
            cout << "Livro nao encontrado.\n";
        } else {
            registrarEmprestimo();
            cout << "Emprestimo registrado para: " << titulo[indice] << endl;

            ofstream saida("emprestimos.txt", ios::app);
            if (saida.is_open()) {
                saida << codigos[indice] << " - " << titulo[indice] << endl;
                saida.close();
            }
        }

        imprimirLivros(numLivros, *titulo[MAX_TITULO], *codigos);
        cout << "Deseja registrar outro emprestimo (s/n)? ";
        cin >> continuar;

    } while (continuar != 'n');