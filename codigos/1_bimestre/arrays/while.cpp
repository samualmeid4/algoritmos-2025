#include <iostream>
using  namespace  std;

int contar_divs(int n){
    int i=1, qtd=1;
    while (i!=n){
        if ((n%i) == 0){
            qtd++;
            }
        i++;
        }
    return qtd;
}


int  main(){
    int a;
    cin >> a;
    cout << contar_divs(a) << endl;
    return  0 ;
}