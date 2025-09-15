#include <iostream>
#include <fstream>
using namespace std;

void lerLivros(){
        ifstream nomeArquivo("livros.txt"); 
}

void buscarLivro(int codigos, int codigo, int resultado){
    resultado = -1;
    for(int i = 0; i < codigos; ++i){
        if (codigos[i] == codigo){
            resultado = i;
        }
    //return resultado;
    }
}

void registrarEmprestimo(int codigos, int codigo){
    auto it = find(codigos.begin(), codigos.end(), codigo);
    for(int i = 0; i < it; ++i){
        "emprestimos.txt" << '\n';
    "emprestimos.txt" << 1;
    }
}

void imprimirLivros(char nomeArquivo, string texto){
    while (getline(nomeArquivo, texto)){
    cout << texto;
    }
}

int main(){
    string texto;
    char titulos[MAX_LIVROS][MAX_TITULO];
    int codigos[MAX_LIVROS], codigo;
    int emprestimos[MAX_LIVROS];
    int numLivros;
    char nomeArquivo[] = "livros.txt";

    lerLivros();
    imprimirLivros(nomeArquivo, texto);

    char continuar;
    do{
        int codigoBusca, indice;
        cout << "Digite o codigo do livro para emprestar: ";
        cin >> codigoBusca;

        indice << buscarLivro(codigos, codigo);
        if(indice == -1){
            cout << "Livro nao encontrado.\n";
        } else {
            registrarEmprestimo(codigos, codigo);
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