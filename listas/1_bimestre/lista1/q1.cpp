#include <iostream>
using namespace std;

int main(){
    string a;
    cin >> a;

    if (a == "a" or a == "e" or a == "i" or a == "o" or a == "u"){
        cout << "Vogal" << endl;
    }
    else{
        cout << "Consoante" << endl;
    }
    

    return 0;
}