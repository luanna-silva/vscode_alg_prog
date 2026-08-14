#include <stdio.h>

void contagem(int n)
{
    if (n == 0)
    {
        printf("Fogo!\n");
    }
    else
    {
        printf("%d...", n);
        contagem(n-1);
    }
}
