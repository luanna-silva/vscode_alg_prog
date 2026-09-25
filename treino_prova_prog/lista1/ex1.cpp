#include <iostream>

using namespace std;

int* inserir_inicio(int* arr, int tam, int valor)
{
    int *novo = new int[tam +1];
    novo[0] = valor;

    for(int i = 0; i < tam; i++)
    {
        novo[i + 1] = arr[i];
    }

    delete[] arr;
    return novo;


}