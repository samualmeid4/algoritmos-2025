#include <iostream>
using  namespace  std;

int maior_elemento2(int array[], int n){
    //int maior = array[0];
    for (int i = 0; i < n; i++){
        if (array[i] == 9){
            array[i] = 20;
        }
    }


    for (int j = 0; j<n; j++){
        cout << array[j] << " ";
    }

    return 0;

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