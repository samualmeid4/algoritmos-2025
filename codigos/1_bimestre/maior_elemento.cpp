#include <iostream>
using namespace std;

int maior_array(int a[], int tamanho){
    int maior = a[0];
    for (int i = 1; i < tamanho; i++)
        if (a[i] > maior)
            maior = a[i];
    return maior;
}



int main(){
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    int maior = maior_array(a,n);
    cout << maior << endl;
   

    return 0;
}