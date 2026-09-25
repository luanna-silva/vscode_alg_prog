#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", &t);

    while (t--) 
    {
        int n, k;
        scanf("%d %d", &n, &k);

        int s = 0;
        
        for (int i = 2; i <= n; i++) {
            s = (s + k) % i;
        }

        printf("%d\n", s + 1);
    }

    return 0;
}