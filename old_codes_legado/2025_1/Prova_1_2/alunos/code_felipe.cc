#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_TITULO = 100;
const int MAX_LIVROS = 50;

void carregarLivros(int codigos[], char titulos[][MAX_TITULO], int emprestimos[], int& numLivros) {
    ifstream arquivo("livros.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir arquivo de livros." << endl;
        numLivros = 0;
        return;
    }

    numLivros = 0;
    while (numLivros < MAX_LIVROS && arquivo >> codigos[numLivros]) {
        arquivo.ignore();
        arquivo.getline(titulos[numLivros], MAX_TITULO);
        emprestimos[numLivros] = 0;
        numLivros++;
    }
    arquivo.close();
}

void carregarEmprestimos(int codigosEmp[], char datas[][11], int matriculas[], int& numEmp) {
    ifstream arquivo("emprestimos.txt");
    if (!arquivo.is_open()) {
        numEmp = 0;
        return;
    }

    numEmp = 0;
    while (numEmp < MAX_LIVROS && arquivo >> codigosEmp[numEmp] >> datas[numEmp] >> matriculas[numEmp]) {
        numEmp++;
    }
    arquivo.close();
}

void salvarEmprestimos(int codigosEmp[], char datas[][11], int matriculas[], int numEmp) {
    ofstream arquivo("emprestimos.txt");
    for (int i = 0; i < numEmp; i++) {
        arquivo << codigosEmp[i] << " " << datas[i] << " " << matriculas[i] << endl;
    }
    arquivo.close();
}

void listarLivros(int codigos[], char titulos[][MAX_TITULO], int emprestimos[], int numLivros) {
    cout << "\n=== Livros Disponíveis ===" << endl;
    cout << "Código\tTítulo\t\tEmpréstimos" << endl;
    for (int i = 0; i < numLivros; i++) {
        cout << codigos[i] << "\t" << titulos[i] << "\t" << emprestimos[i] << endl;
    }
}

bool registrarEmprestimo(int codigos[], char titulos[][MAX_TITULO], int emprestimos[], int numLivros,
                         int codigosEmp[], char datas[][11], int matriculas[], int& numEmp) {
    int codigo, matricula;
    char data[11];
    char resposta;
    do {
        cout << "Digite o código do livro: ";
        cin >> codigo;

        bool encontrado = false;
        for (int i = 0; i < numLivros; i++) {
            if (codigos[i] == codigo) {
                encontrado = true;
                cout << "Livro Selecionado: " << titulos[i] << endl;
                cout << "Data do Empréstimo (YYYY-MM-DD): ";
                cin >> data;
                cout << "Matrícula do Aluno: ";
                cin >> matricula;
                codigosEmp[numEmp] = codigo;
                strcpy(datas[numEmp], data);
                matriculas[numEmp] = matricula;
                numEmp++;
                emprestimos[i]++;
                cout << "Empréstimo registrado com sucesso!" << endl;
                break;
            }
        }
        if (!encontrado) {
            cout << "Código de livro não encontrado ou inválido!" << endl;
        }
        cout << "Deseja registrar outro empréstimo? (s/n): ";
        cin >> resposta;
    } while (resposta == 's' || resposta == 'S');
    return true;
}

int main() {
    int codigos[MAX_LIVROS];
    char titulos[MAX_LIVROS][MAX_TITULO];
    int emprestimos[MAX_LIVROS] = {0};
    int numLivros;
    int codigosEmp[MAX_LIVROS];
    char datas[MAX_LIVROS][11];
    int matriculas[MAX_LIVROS];
    int numEmp = 0;
    
    carregarLivros(codigos, titulos, emprestimos, numLivros);
    carregarEmprestimos(codigosEmp, datas, matriculas, numEmp);
    char opcao;
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Listar livros" << endl;
        cout << "2. Registrar empréstimo" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case '1':
                listarLivros(codigos, titulos, emprestimos, numLivros);
                break;
            case '2':
                registrarEmprestimo(codigos, titulos, emprestimos, numLivros,
                                  codigosEmp, datas, matriculas, numEmp);
                break;
            case '3':
                salvarEmprestimos(codigosEmp, datas, matriculas, numEmp);
                cout << "Dados salvos. Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != '3');

    return 0;
}