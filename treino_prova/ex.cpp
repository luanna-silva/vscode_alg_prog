#include <stdio.h> 

int filaP[1000]; //array do tamanho da fila p
int filaN[1000]; // array do tamanho da fila n

int main()
{
    int n;
    int atendimento = 0;
    scanf("%d", &n);

    int tamP = 0;
    int tamN = 0;

    for(int i = 0; i < n; i++)
    {
        char tipo;
        int senha;
        
        scanf(" %c %d", &tipo, &senha);

        if(tipo == 'P')
        {
            filaP[tamP++] = senha; // filaP[tamP] = senha guarda a senha na posicao livre atual e adiciona +1
        }
        else
        {
            filaN[tamN++] = senha;
        }
    }

    int posP  = 0;
    int posN = 0;

    while(atendimento < n)
    {
        for(int i = 0; i < 2; i++)
        {
            if(posP < tamP)
            {
                printf("%d ", filaP[posP++]);
                atendimento++;
            }
        }

        if(posN < tamN)
        {
            printf("%d ", filaN[posN++]);
            atendimento++;
        }
    }
    return 0;
    
}