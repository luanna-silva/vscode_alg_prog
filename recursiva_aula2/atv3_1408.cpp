#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* buscarbinaria(int* v, int n, int x)
{
    if (n == 0) return NULL;

    int meio = n / 2;
    if(v[meio] == x)
        return v + meio;
    else{
        if(v[meio] > x)
            return buscarbinaria(v, n/2, x);
        else
            return buscarbinaria(v + n/2 + 1, n/2, x);
    }
}

int comp(const void* a, const void* b){ return *((int*)a) > *((int*)b); }

int main()
{
    int v[20];
    srand(time(NULL));

    for(int i = 0; i < 20; i++)
    {
        v[i] = rand() % 100;
    }

    qsort(v, 20, sizeof(int), comp);

    for(int i = 0; i < 20; i++)
    {
        printf("%4d", v[i]);
    }
    printf("\n");

    int x;
    while (1)
    {
        scanf("%d", &x);
        if(x == -1) break;

        int contador = 0;
       // int* elemento = buscarbinaria(v, 20, x, &contador);
        printf("Contador binária: %d\n", contador);
        //elemento = buscalinear fazer a função buscalinear

       // printf("Elemento encontrado %p : %d", elemento, *elemento);
    }
}