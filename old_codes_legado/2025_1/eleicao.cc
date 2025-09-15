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

    for (int i=0; i<numCandidatos; i++){
        cout << cand[i].numero << " " << cand[i].nome << endl;
    }

    bool encerra = false;

    // Simula a contagem de votos
    ofstream votos("votos.txt");
    if (!votos.is_open()) {
        cout << "Erro ao abrir arquivo " << arquivoSaida << endl;
        exit(0);
    }

    while(encerra!=true){
        cout << "Digite o numero do candidato ou 0 para encerrar: " << endl;
        int voto;
        int nulo = 0;
        cin >> voto;
        if (voto == 0) {
            nulo++;
            encerra = false;
            cout << "Voce votou nulo: " << nulo << endl;
        }else {
            bool candidatoEncontrado = false;
            for (int i = 0; i < numCandidatos; i++) {
                if (cand[i].numero == voto) {
                    cand[i].votos++;
                    candidatoEncontrado = true;
                    cout << "Voto registrado para " << cand[i].nome << endl;
                    votos << cand[i].numero << " " << cand[i].nome << endl;
                    
                    break;
                }
            }
            if (!candidatoEncontrado) {
                nulo++;
                cout << "Candidato nao encontrado. Voto nulo: " << nulo << endl;   
            }
            
        }
        cout << "Deseja encerrar a votacao? (s/n): ";
        char resposta;
        cin >> resposta;
        if (resposta == 's' || resposta == 'S') {
            encerra = true;
        } else {
            encerra = false;
        }

              
    }

     for (int i=0; i<numCandidatos; i++){
        cout << cand[i].numero << " " << cand[i].nome << ", Votos: "<<cand[i].votos << endl;
    }
    // Cálculo do vencedor
    int vencedor = 0;
    for (int i = 1; i < numCandidatos; i++) {
        if (cand[i].votos > cand[vencedor].votos) {
            vencedor = i;
        }
    }

    cout << "O candidato vencedor foi " << cand[vencedor].nome << endl;
    votos.close();

    return 0;
}