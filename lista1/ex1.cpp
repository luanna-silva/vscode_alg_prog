#include <iostream> //entrada e saida de dados

using namespace std; 

int*  inserir_inicio(int* arr, int tam, int valor)
{
    int* novo = new int[tam + 1];

    novo[0] = valor;

    for(int i = 0; i < tam; i++)
    {
        novo[i + 1] = arr[i];
    }

    delete[] arr; //libera array antigo

    return novo; // retorna ponteiro do nv array
}

int main()
{
    int tam = 0;
    int* arr = nullptr;

    arr =  inserir_inicio(arr, tam++, 10);
    arr =  inserir_inicio(arr, tam++, 20);
    arr =  inserir_inicio(arr, tam++, 30);

    for(int i = 0; i < tam; i++)
    {
        cout << arr[i] << " "; //saida array separada por espaço
    }

    delete[] arr; //libera a memória

    return 0;
}