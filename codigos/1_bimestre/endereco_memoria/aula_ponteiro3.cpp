#include <iostream>

int main(){

int *data, size=0, capacity=10, x; 

data = new int[capacity]; 

while (std::cin >> x, x!=-1){
    if (size==capacity)
    /* Aumenta capacidade do array*/ 
    data[size++]=x;
}

delete [] data; 

return 0;

}
