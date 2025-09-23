#include <iostream>
#include <iomanip>
using  namespace  std;

int  main(){
    int a, b, c;
    cin >> a >> b;
    c = (a+b)/2.0;
    cout << fixed << setprecision(2) << c << endl;
    return  0;
}