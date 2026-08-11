#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

#define MAX 5

struct Produto {
    int codigo;
    char nome[200];
    float preco;
};

// Função para buscar o índice do produto pelo código
int busca(struct Produto* lista, int n_elementos, int codigo) {
    for (int i = 0; i < n_elementos; i++) {
        if(lista[i].codigo == codigo) {
            return i;
        }
    }
    return -1; // Retorna -1 se não encontrar o produto
}

int main() {
    struct Produto pl[MAX];
    int n_produtos = 0;
    int opcao; // Mudado de char para int para facilitar a leitura do menu

    while (true) {
        printf("\n0 - finalizar | 1 - inserir | 2 - remover | 3 - buscar | 4 - imprimir\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // Lendo como inteiro

        if (opcao == 0) {
            printf("Saindo do programa...\n");
            break;
        }
        else if (opcao == 1) {
            if (n_produtos == MAX) {
                printf("Array cheio!\n");
                continue;
            }      

            struct Produto aux;
            printf("Digite o codigo, nome e preco (separados por espaco): ");
            // Corrigida a formatação e ordem do scanf ( %d para int, %s para string, %f para float)
            scanf("%d %199s %f", &aux.codigo, aux.nome, &aux.preco);
            
            pl[n_produtos++] = aux;
            printf("Produto cadastrado com sucesso!\n");
        }
        else if(opcao == 2) {
            int codigo;
            printf("Digite o codigo do produto a ser removido: ");
            scanf("%d", &codigo);
            
            int pos = busca(pl, n_produtos, codigo);
            
            if(pos != -1) {
                // Corrigido o limite do loop e a sintaxe dos colchetes
                for (int i = pos; i < n_produtos - 1; i++) {
                    pl[i] = pl[i + 1];
                }
                n_produtos--;
                printf("Produto removido!\n");
            } else {
                printf("Erro: Produto nao encontrado.\n");
            }
        }
        else if (opcao == 3) {
            int codigo;
            printf("Digite o codigo do produto para buscar: ");
            scanf("%d", &codigo);
            
            int pos = busca(pl, n_produtos, codigo);
            
            if(pos != -1) {
                printf(">> Produto Encontrado: Codigo: %d | Nome: %s | Preco: R$ %.2f\n", 
                       pl[pos].codigo, pl[pos].nome, pl[pos].preco);
            } else {
                printf("Erro: Produto nao encontrado.\n");
            }
        }
        else if (opcao == 4) {
            if (n_produtos == 0) {
                printf("A lista de produtos esta vazia.\n");
            } else {
                printf("\n--- Lista de Produtos ---\n");
                for (int i = 0; i < n_produtos; i++) {
                    printf("Codigo: %d | Nome: %s | Preco: R$ %.2f\n", 
                           pl[i].codigo, pl[i].nome, pl[i].preco);
                }
                printf("-------------------------\n");
            }
        }
        else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }            
    return 0;
}