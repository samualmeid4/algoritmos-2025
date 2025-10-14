#include <iostream>
using namespace std;

int soma(int vetor[], int n){
    int sum = 0;
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 1, sum = vetor[0]; j <= i; j++ ) {
            sum += vetor[j];
        cout << "A soma do sub-vetores de 0 até " << j <<" é "<< sum << endl;
        }
    }
}

int main(){
    int n;
    cin >> n;

    int vetor[n];
    for (int i = 0; i <= n; i++){
        cin >> vetor[i];
    }

    cout << soma(vetor, n) << endl;
}