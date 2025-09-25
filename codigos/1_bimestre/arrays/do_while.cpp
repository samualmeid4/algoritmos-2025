#include <iostream>
using  namespace  std;

int contar_divs(int n){
    int i, qtd=1;
    do{
        if ((n%i) == 0)
            qtd++;
    }   while (i!=n);
    
    return qtd;
}



int  main(){
    int a,c;
    cin >> a;
    //c = contar_divs(a);
    cout << contar_divs(a) << endl;
    return  0 ;
}