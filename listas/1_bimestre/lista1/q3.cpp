#include <iostream>
using namespace std;

int main(){
    int a, b, taxa_a, taxa_b, anos;

    taxa_a = a*1,03
    taxa_b = b*1,015
    
    cin >> a >> b;
    
    anos = 0
    while (b < a){
        a = a * taxa_a;
        b = b * taxa_b;
        anos += 1;
    }
    return cout << "a = "<<a<<endl<<"b = "<<b<<endl<<"anos"<<anos<<endl;
    
    

    return 0;
}