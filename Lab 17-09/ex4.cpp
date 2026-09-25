#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista encadeada
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Função recursiva para calcular a soma de todos os elementos
int somaLista(No* inicio) {
    if (inicio == NULL) {
        return 0; // Caso base: fim da lista
    }
    return inicio->valor + somaLista(inicio->proximo);
}

// Função recursiva para contar elementos maiores que X
int contaMaiores(No* inicio, int x) {
    if (inicio == NULL) {
        return 0; // Caso base: fim da lista
    }
    
    // Verifica se o valor atual é maior que X (retorna 1 se verdadeiro, 0 se falso)
    int ehMaior = (inicio->valor > x) ? 1 : 0;
    
    return ehMaior + contaMaiores(inicio->proximo, x);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    No* inicio = NULL;
    No* fim = NULL;
    
    // Leitura dos elementos e construção da lista encadeada
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = val;
        novo->proximo = NULL;
        
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->proximo = novo;
            fim = novo;
        }
    }
    
    int x;
    scanf("%d", &x);
    
    // Chamadas das funções recursivas
    int somaTotal = somaLista(inicio);
    int totalMaiores = contaMaiores(inicio, x);
    
    // Impressão dos resultados conforme o formato de saída
    printf("%d\n", somaTotal);
    printf("%d\n", totalMaiores);
    
    // Liberação da memória alocada para evitar vazamentos (memory leaks)
    No* atual = inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    
    return 0;
}