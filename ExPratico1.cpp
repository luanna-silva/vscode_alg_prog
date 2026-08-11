#include <stdio.h>
#include <string>
#include <string.h> // == <string> != <string>

#define MAX 5

struct Produto{
    int codigo;
    char nome[200];
    float preco;
};

int busca(Produto* lista, int n_elementos, int codigo)
{
    for (int i = 0; i < n_elementos; i++)
        if(lista[i].codigo == codigo)
            return i;
}
int main (){

    Produto pl[MAX];

    int n_produtos = 0;
    char opcao;
    while (true)
    {
        Produto aux;

       // printf(" 0 - finalizar | 1 - inserir | 2 - remover | 3 - buscar | 4 - imprimir");
        scanf("%c", &opcao);

        if (opcao == 0)
        {
            break;
        }
        else if (opcao == 1)
        {
            if (n_produtos == MAX)
            {
                printf("Arrqay cheio!\n");
                continue;
            }      

            Produto aux;
            //digite o codigo nome preco
            scanf("%d %f", &(aux.codigo), aux.nome, &(aux.preco));
            pl[n_produtos++] = aux;
        }
        
        else if(opcao == 2)
        {
            int codigo;
            scanf("%d", &codigo);
            int pos = busca(pl, n_produtos, codigo);
            if(pos != -1)
            {
                for (int i  = pos; i < n_produtos; i++)
                    pl[i] = pl(i + 1);

                    n_produtos--;
            }
        }

        else if (opcao == 3)
        {
            int codigo;
            
        }
    }            
}