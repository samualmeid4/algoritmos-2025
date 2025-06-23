#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

const int MAX_TITULO = 100;
const int MAX_LIVROS = 50;

void lerLivros(int codigos[], char titulos[][MAX_TITULO], int &numLivros)
{
    ifstream arquivo("livros.txt");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo livros.txt" << endl;
        return;
    }

    for (int i = 0; i < numLivros; i++)
    {
        arquivo >> codigos[i];
        arquivo.ignore();
        arquivo.getline(titulos[i], MAX_TITULO);
        return;
    }
}

void buscarLivro(int indice, int codigos[], int* numLivros)
{
    ifstream arquivo("livros.txt");
    for (int i = 0; i < numLivros; i++)
    {
        if (indice == codigos[i])
        {
            return i;
        }
    }
}

void registrarEmprestimo(int codigo, const char titulo[])
{
    ofstream arquivo("emprestimos.txt");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    arquivo << codigo << "/ " << titulo << endl;
}
void imprimirLivros(int numLivros)
{
    ifstream arquivo("emprestimos.txt");

    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    cout << "Lista de emprestimos:\n";
    string linha;
    for (int i = 0; i < numLivros; i++)
    {
        cout << linha << endl;
    }
}

int main()
{
    char titulos[MAX_LIVROS][MAX_TITULO];
    int codigos[MAX_LIVROS];
    int emprestimos[MAX_LIVROS];
    int numLivros;
    char nomeArquivo[] = "livros.txt";

    lerLivros(codigos[], titulos[][MAX_TITULO], &numLivros);
    imprimirLivros(numlivros);

    char continuar;
    do
    {
        int codigoBusca, indice;
        cout << "Digite o codigo do livro para emprestar: ";
        cin >> codigoBusca;

        buscarLivro(codigoBusca, codigo, numLivros);

        if (indice == -1)
        {
            cout << "Livro nao encontrado.\n";
        }
        else
        {
            emprestimos[indice]++;
            registrarEmprestimo(codigoBusca, titulos);
            cout << "Emprestimo registrado para: " << titulos[indice] << endl;

            ofstream saida("emprestimos.txt", ios::app);
            if (saida.is_open())
            {
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
