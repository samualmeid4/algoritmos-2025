#include <iostream>
using  namespace  std;

int maior_elemento(int array[], int n){
    int maior = array[0];
    for (int i = 0; i < n; i++){
        if (array[i] > maior){
            maior = array[i];
        }
    }
    return maior;
}


int main(){
    int n;
    cin >> n;

    int array[n];

    for (int i=0; i<n; i++){
        cin >> array[i];
    }

    cout << maior_elemento(array, n)<<endl;
    return 0;
}