#include <stdio.h>
#include <stdlib.h>

struct Trabalho
{
    int id;
    int numPaginas;
    int prioridade;
    int ordemChegada;
};

int comparar(const void *a, const void *b)
{
    //ponteiros tipo Trabalho
    struct Trabalho *t1 = (struct Trabalho *)a;
    struct Trabalho *t2 = (struct Trabalho *)b;

    //define a ordem de pioridade - a maior vem primeiro (2, 1 0)
    if (t1->prioridade != t2->prioridade)
    {
        return t2->prioridade - t1->prioridade;
    }// se prioridades igual quem cehgou primerio vai na frente
    return t1->ordemChegada - t2->ordemChegada;// crescente
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Trabalho trabalhos[1000];//vetor estatico para armazenar até mil conforme pedido na atv
    int tempo = 0;
    
    for(int i = 0; i < n; i++)//laço para ler cada dado dos trabalhos
    {
        scanf("%d %d %d", &trabalhos[i].id, &trabalhos[i].numPaginas, &trabalhos[i].prioridade);
        trabalhos[i].ordemChegada = i; //momento em que o trabalho foi lido 
        tempo += trabalhos[i].numPaginas; //cada pag um segundo
    }

    qsort(trabalhos, n, sizeof(struct Trabalho), comparar); //ordena o veotr de trabalhos usando a regra da função comparar

    for(int i = 0; i < n; i++)
    {
        printf("%d", trabalhos[i].id);
        if(i < n - 1)
        {
            printf(" ");
        }
    }

    printf("\n");

    printf("%d\n", tempo);

    return 0;
}