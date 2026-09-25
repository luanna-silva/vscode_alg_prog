#include <iostream> // cout (imprimir) e cin (ler)

using namespace std; //ler frases 

int* inserir_inicio(int* arr, int tam, int valor) // criando a função 
{
    int* novo = new int[tam + 1]; //criando o novo array dinamico com new

    novo[0] = valor; //posicao 1 do array recebe o valor digitado

    for(int i = 0; i < tam; i++)
    {
        novo[i + 1] = arr[i]; //desloca 1 pra frente
    }

    delete[] arr; //deleta array antiga q nn usamos mais
    return novo; // retorna nova array
}

int main()
{
    int v;
    int tam = 0;
    cout << "Insira tamanho:";
    cin >> tam;

    int *arr = new int[tam]; // aloca espaço para a array

    for(int i = 0; i < tam; i++) //le o valor de cada posicao 
    {
        cout << "Insira valores: ";
        cin >> arr[i];
    }

    cout << "Insira novo valor: "; //le o novo primeiro valor [0]
    cin >> v;

    arr = inserir_inicio(arr, tam++, v); //chama funcao e passa parametros

    for(int j = 0; j < tam; j++) // imprime
    {
        cout << arr[j] << " ";
    }
    delete[] arr; // limpa

    return 0; 

}