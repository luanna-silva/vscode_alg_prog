#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int busca_binaria_rastreamento(int arr[], int esq, int dir, int x, int nivel = 0) {
    if (esq > dir) return -1; 
    
    cout << setw(nivel * 4) << ""; 
    
    cout << "Buscando " << x << " no intervalo [" << esq << ", " << dir << "]: [";
    for (int i = esq; i <= dir; i++) {
        cout << arr[i] << (i < dir ? " " : "");
    }
    cout << "]\n";

    int meio = esq + (dir - esq) / 2;

    if (arr[meio] == x) return meio;
    if (arr[meio] > x) return busca_binaria_rastreamento(arr, esq, meio - 1, x, nivel + 1);
    
    return busca_binaria_rastreamento(arr, meio + 1, dir, x, nivel + 1);
}

int busca_binaria_comparacoes(int arr[], int esq, int dir, int x, int& comparacoes) {
    if (esq > dir) return -1;
    
    int meio = esq + (dir - esq) / 2;
    
    comparacoes++;
    if (arr[meio] == x) return meio;
    
    comparacoes++; 
    if (arr[meio] > x) return busca_binaria_comparacoes(arr, esq, meio - 1, x, comparacoes);
    
    return busca_binaria_comparacoes(arr, meio + 1, dir, x, comparacoes);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int alvo = 7;

    cout << "A e B\n";
    int posicao = busca_binaria_rastreamento(arr, 0, n - 1, alvo);
    if (posicao != -1) cout << "Encontrado na posicao " << posicao << "!\n\n";

    cout << "C\n";
    int comparacoes_reais = 0;
    busca_binaria_comparacoes(arr, 0, n - 1, alvo, comparacoes_reais);
    
    int comparacoes_teoricas = floor(log2(n)) + 1;
    
    cout << "Numero de comparacoes realizadas: " << comparacoes_reais << "\n";
    cout << "valor teorico: " << comparacoes_teoricas << "\n";

    return 0;
}