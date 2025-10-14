#include <iostream>
using namespace std;

int soma(int vetor[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            sum += vetor[j];
        }
        cout << "A soma do sub-vetor de 0 até " << i << " é " << sum << endl;
        sum = 0;  // zera a soma para o próximo i
    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    int vetor[100]; // tamanho fixo, por simplicidade

    for (int i = 0; i < n; i++) {  // corrigido: i < n, não i <= n
        cin >> vetor[i];
    }

    soma(vetor, n);

    return 0;
}
