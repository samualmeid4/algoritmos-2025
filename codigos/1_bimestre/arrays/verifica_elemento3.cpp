#include <iostream>
using  namespace  std;

int maior_elemento2(int array[], int n){
    
    for (int i = 0; i < n; i++){
        if (array[i] == 9){
            array[i] = 20;
        }
    }


    int maior = array[0];


    for (int c = 0; c < n; c++){
        if (array[c] > maior){
            maior = array[c];
        }
    }


    // for (int j = 0; j<n; j++){
    //     cout << array[j] << " "<<endl;
    // }

    return maior;

}


int main(){
    int n;
    cin >> n;

    int array[n];

    for (int i=0; i<n; i++){
        cin >> array[i];
    }

    cout << maior_elemento2(array, n)<<endl;
    return 0;
}