#include <iostream>
using namespace std;

// Função para trocar dois elementos
void troca(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função de ordenação Insertion Sort
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && v[j] < v[j - 1]) {
            troca(v[j], v[j - 1]);
            j = j - 1;
        }
    }
}

// Função para imprimir o vetor
void imprimeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void checkDuplicates(int v[], int n) {
    bool hasDuplicates = false;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            hasDuplicates = true;
            break;
        }
    }
    if (hasDuplicates) {
        cout << "O vetor possui elementos duplicados." << endl;
    } else {
        cout << "O vetor não possui elementos duplicados." << endl;
    }
}

int countDiffrentElements(int v[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (v[i] == v[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            count++;
        }
    }
    return count; //cout << "Número de elementos diferentes: " << count << endl;
}

void createArraydynamic(int* &v, int n) {
    v = new int[n]; // Aloca memória dinamicamente para o vetor
    
    if (v == nullptr) {
        cout << "Erro ao alocar memória." << endl;
        exit(1); // Encerra o programa se a alocação falhar
    }
}

// Função principal
int main() {
    
    //int v[] = {5, 2, 9, 1, 5, 6};
    int* v;
    //int n = sizeof(v) / sizeof(v[0]);
    int n;
   
    cout << "Insira o tamanho do vetor (array): ";
    cin >> n; // Lê o tamanho do vetor

    v= new int[n];
        
    for(int i=0;i<n;i++){
      v[i]=rand()%10000;  //Generate number between 0 to 99
    }
    
    //cout << "Insira os valores do vetor: ";
    //for (int i = 0; i < n; i++) {
     //   cin >> v[i]; // Lê os demais elementos do vetor
    //}
    cout << "Vetor antes da ordenação: ";
    imprimeVetor(v, n);

    insertionSort(v, n);

    checkDuplicates(v, n);

    int count = countDiffrentElements(v, n);
    cout << "Número de elementos diferentes: " << count << endl;

    cout << "Vetor após a ordenação: ";
    imprimeVetor(v, n);

    return 0;
}
