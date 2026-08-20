#include <iostream>

using namespace std;

int* remover_negativos(int* arr, int* tam)
{
    // Conta quantos elementos serão mantidos
    int novoTam = 0;

    for(int i = 0; i < *tam; i++)
    {
        if(arr[i] >= 0)
        {
            novoTam++;
        }
    }
    //Cria o novo vetor com o tamanho exato
    int* novo = new int[novoTam];

    int j = 0;

    //copia os elementos >=0
    for(int i = 0; i < *tam; i++)
    {
        if(arr[i] >= 0)
        {
            novo[j] = arr[i];
        j++;  
        }     
    }

    delete[] arr; // librera o vetor antigo
    *tam = novoTam; //atualiza tamanho

    return novo;
}

int main()
{
    int tam = 6;

    int* arr = new int[tam]{5, -3, 8, -1, 0, 7};

    arr = remover_negativos(arr, &tam);

    for (int i = 0; i < tam; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}