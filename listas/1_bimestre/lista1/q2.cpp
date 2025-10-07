#include <iostream>
using namespace std;

int main(){
    int a;
    a = 11;

    while (a < 0 or a > 10){
        cin >> a;
        if (a < 0 or a > 10){
        cout << "Digite um numero entre 0 e 10" << endl;
        }

    }   cout << "Tudo certo!" << endl;

    

    return 0;
}