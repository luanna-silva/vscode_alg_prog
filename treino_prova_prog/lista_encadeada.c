#include <stdio.h>
#include <stdlib.h>

struct No {
    char dado;
    struct No *anterior;
    struct No *proximo;
};

struct Lista {
    struct No *inicio;
    struct No *fim;
};

struct No *criarNo(char caractere) {
    struct No *novo = malloc(sizeof(struct No));

    if (novo == NULL) {
        return NULL;
    }

    novo->dado = caractere;
    novo->anterior = NULL;
    novo->proximo = NULL;

    return novo;
}

void inicializar(struct Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void inserirFim(struct Lista *lista, char caractere) {
    struct No *novo = criarNo(caractere);

    if (novo == NULL) {
        return;
    }

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->anterior = lista->fim;
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
}

void imprimirInicioFim(struct Lista *lista) {
    struct No *atual = lista->inicio;

    while (atual != NULL) {
        printf("%c ", atual->dado);
        atual = atual->proximo;
    }

    printf("\n");
}

void imprimirFimInicio(struct Lista *lista) {
    struct No *atual = lista->fim;

    while (atual != NULL) {
        printf("%c ", atual->dado);
        atual = atual->anterior;
    }

    printf("\n");
}

int main() {
    struct Lista lista;

    inicializar(&lista);

    inserirFim(&lista, 'A');
    inserirFim(&lista, 'B');
    inserirFim(&lista, 'C');

    imprimirInicioFim(&lista);
    imprimirFimInicio(&lista);

    return 0;
}
