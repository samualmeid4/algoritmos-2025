#include <iostream>
using namespace std;

int main (){
    int a,b;
    double c;
    cin >> a >> b;

    c=static_cast<double>(a/b);
    
    cout << a << "/" << b << "=" << c << endl;
}
