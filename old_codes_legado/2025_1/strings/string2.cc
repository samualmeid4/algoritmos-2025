#include <iostream>
#include <cstring>
using namespace std;

int main () {
    char s[10];
    cin >> s;
    char copia[strlen(s)+1];
    strcpy(copia, s);
    if (strcmp(s, copia) == 0)
        cout << "Iguais" << endl;
    else
        cout << "Diferentes" << endl;
    strcat(s, "fim"); // Cabe em s?
    cout << s << endl;
     return 0;
}
