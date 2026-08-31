#include <iostream>

using namespace std;

#define MAX 50

struct ListaSequencial
{
    int dados[MAX];
    int tamanho;
};

void inicializar(ListaSequencial *lista)
{
    lista->tamanho = 0;
}

void exibir(ListaSequencial *lista)
{
    if (lista->tamanho == 0)
    {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < lista->tamanho; i++)
    {
        cout << lista->dados[i] << (i < lista->tamanho - 1 ? ", " : "");
    }
    cout << "]\n";
}

ListaSequencial concatenar(ListaSequencial l1, ListaSequencial l2)
{
    ListaSequencial l3;
    inicializar(&l3);

    for (int i = 0; i < l1.tamanho; i++)
    {
        if (l3.tamanho < MAX)
        {
            l3.dados[l3.tamanho] = l1.dados[i];
            l3.tamanho++;
        }
    }

    for (int i = 0; i < l2.tamanho; i++)
    {
        if (l3.tamanho < MAX)
        {
            l3.dados[l3.tamanho] = l2.dados[i];
            l3.tamanho++;
        }
    }

    return l3;
}

ListaSequencial intercalar_ordenado(ListaSequencial *l1, ListaSequencial *l2)
{
    ListaSequencial l3;
    inicializar(&l3);
    
    int i = 0, j = 0;
    
    while (i < l1->tamanho && j < l2->tamanho && l3.tamanho < MAX)
    {
        if (l1->dados[i] < l2->dados[j])
        {
            l3.dados[l3.tamanho] = l1->dados[i];
            i++;
        }
        else
        {
            l3.dados[l3.tamanho] = l2->dados[j];
            j++;
        }
        l3.tamanho++;
    }
    
    while (i < l1->tamanho && l3.tamanho < MAX)
    {
        l3.dados[l3.tamanho] = l1->dados[i];
        i++;
        l3.tamanho++;
    }
    
    while (j < l2->tamanho && l3.tamanho < MAX)
    {
        l3.dados[l3.tamanho] = l2->dados[j];
        j++;
        l3.tamanho++;
    }
    
    return l3;
}

void remover_duplicatas(ListaSequencial *lista)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        for (int j = i + 1; j < lista->tamanho; j++)
        {
            if (lista->dados[i] == lista->dados[j])
            {
                for (int k = j; k < lista->tamanho - 1; k++)
                {
                    lista->dados[k] = lista->dados[k + 1];
                }
                lista->tamanho--;
                j--; 
            }
        }
    }
}

void rotacionar_direita(ListaSequencial *lista)
{
    if (lista->tamanho > 1)
    {
        int ultimo = lista->dados[lista->tamanho - 1];
        
        for (int i = lista->tamanho - 1; i > 0; i--)
        {
            lista->dados[i] = lista->dados[i - 1];
        }
        
        lista->dados[0] = ultimo;
    }
}

int main()
{
    ListaSequencial l1, l2;
    inicializar(&l1);
    inicializar(&l2);

    l1.dados[0] = 1; l1.dados[1] = 3; l1.dados[2] = 5; l1.tamanho = 3;
    l2.dados[0] = 2; l2.dados[1] = 4; l2.dados[2] = 6; l2.tamanho = 3;

    cout << "Concatenar:\n";
    ListaSequencial l3 = concatenar(l1, l2);
    exibir(&l3);

    cout << "Intercalar ordenado:\n";
    ListaSequencial l4 = intercalar_ordenado(&l1, &l2);
    exibir(&l4);

    ListaSequencial l5;
    inicializar(&l5);
    l5.dados[0] = 1; l5.dados[1] = 2; l5.dados[2] = 2; l5.dados[3] = 3; l5.tamanho = 4;
    
    cout << "Remover duplicatas (1, 2, 2, 3):\n";
    remover_duplicatas(&l5);
    exibir(&l5);

    cout << "Rotacionar a direita:\n";
    rotacionar_direita(&l1);
    exibir(&l1);

    return 0;
}