#include <iostream>
using namespace std;

int main(){
    int a, b, anos;
    float taxa_a = 0.03;  // 3% de crescimento
    float taxa_b = 0.015;


    
    
    cin >> a >> b;
    
    anos = 0;
    while(b < a){
        a = a + a * taxa_a;
        b = b + b * taxa_b;
        anos++;anos += 1;

        if (b>=a){
            break;
    }
}
    cout << "Depois de " << anos << " anos, os habitantes serão:\n";
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    

    return 0;
}