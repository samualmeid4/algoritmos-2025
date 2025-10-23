#include <iostream>
using namespace std;

int main(){
    int a = 20;
    int *p;
    p = &a;
    cout << "o endereco de *p: %d" << *p << endl;
    *p = 50;
    cout << "o valor de a: %d" << a << endl;

    return 0;
}