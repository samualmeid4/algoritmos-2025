#include <iostream>

int main() { 
    int *n, t, i; std::cin >> t;
    n =  new(std::nothrow) int[t];
if (n == nullptr) {
    std::cerr << "ERRO ao alocar memória" << std::endl; exit(1);
}
for (i=0; i<t; i++) {
std::cin >> n[i];
}
for (i=0; i<t; i++){
     std::cout << n[i] << " ";
}
std::cout << std::endl;

return 0;
}
