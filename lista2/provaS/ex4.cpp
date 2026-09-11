#include <stdio.h>

int max_heap[100000];
int min_heap[100000];
int tam_max = 0, tam_min = 0;

void insere_max(int x) 
{
    max_heap[++tam_max] = x;
    int i = tam_max;
    while (i > 1 && max_heap[i] > max_heap[i / 2]) 
    {
        int t = max_heap[i]; max_heap[i] = max_heap[i / 2]; max_heap[i / 2] = t;
        i /= 2;
    }
}

int remove_max() 
{
    int topo = max_heap[1];
    max_heap[1] = max_heap[tam_max--];
    int i = 1;
    while (2 * i <= tam_max) 
    {
        int m = 2 * i;
        if (m + 1 <= tam_max && max_heap[m + 1] > max_heap[m]) m++;
        if (max_heap[i] >= max_heap[m]) break;
        int t = max_heap[i]; max_heap[i] = max_heap[m]; max_heap[m] = t;
        i = m;
    }
    return topo;
}

void insere_min(int x) 
{
    min_heap[++tam_min] = x;
    int i = tam_min;
    while (i > 1 && min_heap[i] < min_heap[i / 2]) 
    {
        int t = min_heap[i]; min_heap[i] = min_heap[i / 2]; min_heap[i / 2] = t;
        i /= 2;
    }
}

int remove_min() 
{
    int topo = min_heap[1];
    min_heap[1] = min_heap[tam_min--];
    int i = 1;
    while (2 * i <= tam_min) 
    {
        int m = 2 * i;
        if (m + 1 <= tam_min && min_heap[m + 1] < min_heap[m]) m++;
        if (min_heap[i] <= min_heap[m]) break;
        int t = min_heap[i]; min_heap[i] = min_heap[m]; min_heap[m] = t;
        i = m;
    }
    return topo;
}

int main() 
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        int num;
        scanf("%d", &num);

        if (tam_max == 0 || num <= max_heap[1]) 
        {
            insere_max(num);
        } 
        else 
        {
            insere_min(num);
        }

        if (tam_max > tam_min + 1) 
        {
            insere_min(remove_max());
        } 
        else if (tam_min > tam_max) 
        {
            insere_max(remove_min());
        }

        if (tam_max > tam_min) 
        {
            printf("%d\n", max_heap[1]);
        } 
        else 
        {
            long long soma = (long long)max_heap[1] + min_heap[1];
            if (soma % 2 == 0) 
            {
                printf("%lld\n", soma / 2);
            } 
            else 
            {
                printf("%.1f\n", soma / 2.0);
            }
        }
    }

    return 0;
}