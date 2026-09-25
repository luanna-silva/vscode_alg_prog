#include <stdio.h>

int filaP[1000];
int filaN[1000];

int main() {
    int total;
    scanf("%d", &total);

    int tamP = 0;
    int tamN = 0;
    
    for (int i = 0; i < total; i++) 
    {
        char tipo;
        int senha;
        
        scanf(" %c %d", &tipo, &senha);

        if (tipo == 'P') 
        {
            filaP[tamP++] = senha;
        } else 
        {
            filaN[tamN++] = senha;
        }
    }

    int posP = 0;
    int posN = 0;
    int contP = 0; 

   
    while (posP < tamP || posN < tamN) {
        if (posP < tamP && (contP < 2 || posN >= tamN)) {
            printf("%d\n", filaP[posP++]);
            contP++;
        } 
       
       else if (posN < tamN) {
            printf("%d\n", filaN[posN++]);
            contP = 0; 
           
       }
    }

    return 0;
}