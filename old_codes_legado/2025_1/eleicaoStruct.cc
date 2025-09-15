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

int leCandidatos (char nomeArquivo[], Candidato cand[]) {
	ifstream entrada(nomeArquivo);

	if (!entrada.is_open()) {
		cout << "Erro ao abrir arquivo " << nomeArquivo << endl;
		exit(0);
	}

	int i = 0;
	while (entrada >> cand[i].numero) {
		entrada.getline(cand[i].nome, MAXNOME);
		cand[i].votos = 0;
		i = i + 1;
	}

	entrada.close();
	return i;
}

int buscaCandidato (int n, Candidato cand[], int numCand) {
	for (int i=0; i<numCand; i++) {
		if (cand[i].numero == n)
			return i;
	}
	return -1;
}

void imprimeResultado (Candidato cand[], int numCand) {
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	for (int i=0; i<numCand; i++) {
		cout << cand[i].numero << ". " << cand[i].nome << ": " << cand[i].votos << " votos " << endl;
	}
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << endl;
}


void gravaVoto (char nomeArquivo[], Candidato cand) {
	ofstream saida(nomeArquivo, ios::app);

	if (!saida.is_open()) {
		cout << "Erro ao abrir arquivo " << nomeArquivo << endl;
		exit(0);
	}

	saida << cand.numero << " " << cand.nome << endl;
	saida.close();
}


int main () {
	Candidato cand[MAXCANDIDATO];
	char arquivoEntrada[] = "candidatos.txt";
	char arquivoSaida[] = "votos.txt";
	
	int numCandidatos = leCandidatos(arquivoEntrada, cand);

	for (int i=0; i<numCandidatos; i++) {
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
		int i = buscaCandidato(n, cand, numCandidatos);
		Candidato c;

		c.numero = n;
		if (i == -1) {
			strcpy(c.nome, "Nulo");
		}
		else {
			strcpy(c.nome, cand[i].nome);
			cand[i].votos++;
			votosValidos++;
		}
		totalVotos++;

		cout << "Voce votou em " << c.nome << endl;
		gravaVoto(arquivoSaida, c);	
		imprimeResultado(cand, numCandidatos);	
	
		cout << "Encerra votacao (s/n)? ";
		cin >> encerra; 
	} while (encerra != 's');

	
	int vencedor = 0;
	for (int i=1; i<numCandidatos; i++) {
		if (cand[i].votos > cand[vencedor].votos) {
			vencedor = i;
		}
	}

	cout << "O candidato vencedor foi " << cand[vencedor].nome << endl;

	return 0;
}
