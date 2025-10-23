#include <iostream>

#include <cstdint>
using namespace std;
int main(){
    int a = 10, b=20,c;

    c= (a+b)/2;

    cout << "o endereco de a: " << reinterpret_cast <uintptr_t> (&a) << " (" << &a << " )" << endl;
    cout << "o endereco de b: " << reinterpret_cast <uintptr_t> (&b) << " (" << &b << " )" << endl;
    cout << "o endereco de c: " << reinterpret_cast <uintptr_t> (&c) << " (" << &c << " )" << endl;


    return 0;

}

