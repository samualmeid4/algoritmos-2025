#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

const int MAXNOME = 100;
const int MAXCANDIDATO = 20;

struct Candidato {
    char nome[MAXNOME];
    int numero;
    int votos;
};

int main() {
    Candidato cand[MAXCANDIDATO];
    char arquivoEntrada[] = "candidatos.txt";
    char arquivoSaida[] = "votos.txt";

    // Simula leCandidatos()
    ifstream entrada(arquivoEntrada);
    if (!entrada.is_open()) {
        cout << "Erro ao abrir arquivo " << arquivoEntrada << endl;
        exit(0);
    }

    int numCandidatos = 0;
    while (entrada >> cand[numCandidatos].numero) {
        entrada.getline(cand[numCandidatos].nome, MAXNOME);
        cand[numCandidatos].votos = 0;
        numCandidatos++;
    }
    entrada.close();

    for (int i = 0; i < numCandidatos; i++) {
        cout << cand[i].numero << " " << cand[i].nome << endl;
    }
    cout << endl;

    char encerra;
    int n;
    int votosValidos = 0;
    int totalVotos = 0;

    do {
        cout << "Digite o numero do candidato: ";
        cin >> n;

        // Simula buscaCandidato()
        int iCandidato = -1;
        for (int i = 0; i < numCandidatos; i++) {
            if (cand[i].numero == n) {
                iCandidato = i;
                break;
            }
        }

        Candidato c;
        c.numero = n;
        if (iCandidato == -1) {
            strcpy(c.nome, "Nulo");
        } else {
            strcpy(c.nome, cand[iCandidato].nome);
            cand[iCandidato].votos++;
            votosValidos++;
        }
        totalVotos++;

        cout << "Voce votou em " << c.nome << endl;

        // Simula gravaVoto()
        ofstream saida(arquivoSaida, ios::app);
        if (!saida.is_open()) {
            cout << "Erro ao abrir arquivo " << arquivoSaida << endl;
            exit(0);
        }
        saida << c.numero << " " << c.nome << endl;
        saida.close();

        // Simula imprimeResultado()
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
        for (int i = 0; i < numCandidatos; i++) {
            cout << cand[i].numero << ". " << cand[i].nome << ": " << cand[i].votos << " votos " << endl;
        }
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << endl;

        cout << "Encerra votacao (s/n)? ";
        cin >> encerra;
    } while (encerra != 's');

    // Cálculo do vencedor
    int vencedor = 0;
    for (int i = 1; i < numCandidatos; i++) {
        if (cand[i].votos > cand[vencedor].votos) {
            vencedor = i;
        }
    }

    cout << "O candidato vencedor foi " << cand[vencedor].nome << endl;

    return 0;
}
