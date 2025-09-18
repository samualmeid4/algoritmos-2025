#include <iostream>
using namespace std;
#include <iomanip>

int main(){
    int a, b;
    double c;
    cin >> a >> b;
    c = (a+b)/2.0;
    cout << fixed << setprecision(2) << c << endl;

    return 0;
}