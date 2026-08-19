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


int main()
{
    int tam = 3;

    Produto* produtos = new Produto[tam];

    produtos[0] = {1, "Camiseta", 50.00, 10};
    produtos[1] = {2, "Calca", 75.00, 5};
    produtos[2] = {3, "Sueter", 60.00, 4};

    int indice = indice_mais_caro(produtos, tam);

    cout << "Produto mais caro: " << produtos[indice].nome << endl; // endl pula uma linha na tela e limpa o armazenamento temporário de dados

    Produto* encontrado = buscar_por_codigo(produtos, tam, 2);

    if(encontrado != nullptr)
    {
        cout << "Produto encontrado: " << encontrado->nome << endl;
        cout << "Preco: " << encontrado->preco << endl;
    }
    else
    {
        cout << "Produto nao encontrado." << endl;
    }

    delete[] produtos;

    return 0;
}

