#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct No {
    char dado;
    struct No *anterior;
    struct No *proximo;
};

struct Lista {
    struct No *inicio;
    struct No *fim;
};

void inicializar(struct Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void inserirFim(struct Lista *lista, char caractere) {
    struct No *novo;

    novo = malloc(sizeof(struct No));

    if (novo == NULL) {
        return;
    }

    novo->dado = caractere;
    novo->anterior = lista->fim;
    novo->proximo = NULL;

    if (lista->fim == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
}

int ehPalindromo(struct Lista *lista) {
    struct No *esquerda = lista->inicio;
    struct No *direita = lista->fim;

    while (esquerda != NULL && direita != NULL) {
        if (esquerda->dado != direita->dado) {
            return 0;
        }

        if (esquerda == direita) {
            break;
        }

        if (esquerda->proximo == direita) {
            break;
        }

        esquerda = esquerda->proximo;
        direita = direita->anterior;
    }

    return 1;
}

void liberarLista(struct Lista *lista) {
    struct No *atual = lista->inicio;
    struct No *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->fim = NULL;
}

int main() {
    char linha[1001];
    int i;
    struct Lista lista;

    while (fgets(linha, 1001, stdin) != NULL) {
        inicializar(&lista);

        for (i = 0; linha[i] != '\0'; i++) {
            if (!isspace((unsigned char) linha[i])) {
                inserirFim(&lista, tolower((unsigned char) linha[i]));
            }
        }

        if (ehPalindromo(&lista)) {
            printf("PALINDROMO\n");
        } else {
            printf("NAO PALINDROMO\n");
        }

        liberarLista(&lista);
    }

    return 0;
}
