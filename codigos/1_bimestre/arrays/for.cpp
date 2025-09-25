#include <iostream>
using  namespace  std;

int contar_divs(int n){
    int i, qtd=1;
    for (i=1; i<n; i++){
        if (n%i == 0){
            qtd++;
        }
    }
    return qtd;
}



int  main(){
    int a,c;
    cin >> a;
    //c = contar_divs(a);
    cout << contar_divs(a) << endl;
    return  0 ;
}