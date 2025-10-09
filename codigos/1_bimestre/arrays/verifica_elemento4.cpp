#include <iostream>
using  namespace  std;

int maior_elemento2(int array[], int n){
    
    //imprime o array 1----------------------------------------------------------------
    cout <<"array original"<<endl;
    for (int a = 0; a<n; a++){
        cout << array[a] << " ";
    }
    cout<<"\n";



    //imprime o array 1
    for (int i = 0; i < n; i++){
        if (array[i] == 9){
            array[i] = 20;
        }
    }


    //array 2 ----------------------------------------------------------------
    cout <<"array copia 1 (a)"<<endl;
    int maior = array[0];


    for (int c = 0; c < n; c++){
        if (array[c] > maior){
            maior = array[c];
        }
    }
    

    //imprime o array 2
    for (int j = 0; j<n; j++){
        cout << array[j] << " ";
    }cout<<"\n";


    //imprime o array 3----------------------------------------------------------------
    cout <<"array copia 2 (b)"<<endl;
    for (int b = 0; b<n; b++){
        cout << array[b] << " ";
    }
    cout<<"\n";




    

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