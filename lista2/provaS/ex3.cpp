#include <stdio.h>
#include <stdlib.h>

int a[100005];

int comparaMaior(const void *n1, const void *n2) 
{
    int valor1 = *(const int *)n1;
    int valor2 = *(const int *)n2;
    
    if (valor1 < valor2) return 1;
    if (valor1 > valor2) return -1;
    return 0;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    
    qsort(a, n, sizeof(int), comparaMaior);
    printf("%d\n", a[k - 1]);

    return 0;
}