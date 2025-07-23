#include <iostream>  

int main () {
    char s[10] = "bola";
    std::cout << s << std::endl;
    s[2] = '\0';
    std::cout << s << std::endl;
    s[2] = 't';
    std::cout << s << std::endl;
    return 0;
}
