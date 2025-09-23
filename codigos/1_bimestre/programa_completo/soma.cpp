#include <iostream>
using  namespace  std;

int soma(int a, int b){
    return a+b;
}


int  main(){
    int a, b, c;
    cin >> a >> b;
    c = soma(a,b);
    cout << c << endl;
    return  0 ;
}