#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Subalgoritmo É-Sufixo
bool EhSufixo(const string& P, int m, const string& T, int k) {
    int l = m;
    while (l >= 1 && P[l - 1] == T[k - m + l - 1]) {
        l--;
    }
    if (l >= 1)
        return false;
    else
        return true;
}

// Algoritmo Inocente
void Inocente(const string& P, int m, const string& T, int n) {
    for (int k = m; k <= n; ++k) {
        if (EhSufixo(P, m, T, k)) {
            cout << "Ocorrencia em posicao final k = " << k << endl;
        }
    }
}

// Exemplo de uso
int main() {
    string T = "eefgfgfgee";
    string P = "fgfg";
    int n = T.size();
    int m = P.size();

    Inocente(P, m, T, n);

    return 0;
}
