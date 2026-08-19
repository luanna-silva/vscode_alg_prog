#include <iostream>
#include <string>
#include <cassert> //permite testar se um condição é verdadeira em tempo de execução

using namespace std;

struct  Produto
{
    int codigo;
    string nome;
    float preco;
    int quantidade;
};

//A)

int indice_mais_caro(Produto* produtos, int tam)
{
    assert(produtos != nullptr && tam > 0); //cassert

    int indice = 0;

    for(int i = 1; i < tam; i++)
    {
        if(produtos[i].preco > produtos[indice].preco)
        {
            indice = i;
        }
    }

    return indice;
}

//B)

Produto* buscar_por_codigo(Produto* produtos, int tam, int codigo)
{
    assert(produtos != nullptr && tam > 0);

    for(int i = 0; i < tam; i++)
    {
        if(produtos[i].codigo == codigo)
        {
            return &produtos[i];
        }
    }

    return nullptr;
}
