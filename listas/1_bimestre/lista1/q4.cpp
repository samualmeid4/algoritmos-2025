#include <iostream>
using namespace std;

int main() {
    float a, b; 
    int anos = 0;
    float taxa_a,  taxa_b;

    cout << "A = " <<endl;
    cin >> a;
    cout << "B = ";
    cin >> b;

    cout << "taxa de a = " <<endl;
    cin >> taxa_a;
    cout << "taxa de b = ";
    cin >> taxa_b;

    taxa_a = taxa_a/100;
    taxa_b = taxa_b/100;

    cout << taxa_a<<endl;
    cout << taxa_b<<endl;

    while (a < b) { 
        a = a + a * taxa_a;
        b = b + b * taxa_b;
        anos++;
    }

    cout << "Depois de " << anos << " anos, os habitantes serão:\n";
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";



    return 0;
}
