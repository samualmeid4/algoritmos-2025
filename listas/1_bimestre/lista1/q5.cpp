#include <iostream>
using namespace std;

int main() {
    float litrosG, litrosA, preco = 0; 
    int  qtd;
    string opcao;
    

    cout << "Alcool ('A') ou Gasolina ('G')? = " <<endl;
    cin >> opcao;
    cout << "quantidade?";
    cin >> qtd;


    if (opcao == "A"){
        preco = qtd*1.9;
        if (qtd <= 20){
            preco *= 0.97;
        }
        else{
            preco *= 0.95;
        }
    }
    else{ 
        preco = qtd*2.5;

        if (qtd <= 20){
            preco *= 0.96;
        }
        else{
            preco *= 0.94;
        }

    }
    

    cout << "R$ " << preco<<"\n";




    if (a==b){
        return a;
    } 
    retorna b;



    return 0;
}
