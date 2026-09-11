#include <stdio.h>

char pilha[1000];

int temPar(char a, char f) 
{
    if (a == '(' && f == ')') return 1;
    if (a == '[' && f == ']') return 1;
    if (a == '{' && f == '}') return 1;
    return 0;
}

int main() 
{
    char linha[1000];

    while (scanf("%s", linha) != EOF) 
    {
        int topo = 0;
        int erro = 0;

        for (int i = 0; linha[i] != '\0'; i++) 
        {
            char c = linha[i];

            if (c == '(' || c == '[' || c == '{') 
            {
                pilha[topo++] = c;
            } 
            else 
            {
                if (topo == 0 || !temPar(pilha[--topo], c)) 
                {
                    erro = 1;
                    break;
                }
            }
        }

        if (!erro && topo == 0) 
        {
            printf("OK\n");
        } 
        else 
        {
            printf("ERRO\n");
        }
    }

    return 0;
}