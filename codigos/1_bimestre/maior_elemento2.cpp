#include <iostream>
using namespace std;

int maior_array2(int a[], int tamanho){
    int maior = a[0];
    for (int i = 1; i < tamanho; i++)
        if (a[i] > maior)
            maior = a[i];
        else if (a[i] == 10)
            a[i]= 100;
        
    return maior;
}



int main(){
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int j = 0; j <= n; j++)
        cout << a[j]<<" ";
    cout << ""<<endl;


    a = maior_array2(a,n);
    

    for (int c = 0; c <= n; c++)
        cout << a[c]<<" "<<endl;
   

    return 0;
}