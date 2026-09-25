#include <iostream>
#include <string>
#include <cassert>

using namespace std;

struct Produto
{
    int codigo;
    std::string nome;
    float preco;
    int quantidade;
};

int indice_mais_caro (Produto* produtos , int tam ) 
{
    assert(produtos != nullptr && tam > 0);
    float maior_preco = 0.0;
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(produtos[i].preco > maior_preco)
        {
            indice = i;
            maior_preco = produtos[i].preco;
        }
    }
    return indice;
}

int main()
{
    int tam;

    cout << "Quantidade de produtos: ";
    cin >> tam;

    Produto* cadastro = new Produto[tam];

    for(int i = 0; i < tam; i++)
    {
        cout << "Produto " << (i + 1) << endl;
        cout << "Nome: ";
        cin >> cadastro[i].nome;
        // cin.ignore(); // Limpa o buffer do teclado (o 'Enter' deixado pelo cin anterior)
        // getline(cin, cadastro[i].nome);

        cout << "Codigo: ";
        cin >> cadastro[i].codigo;

        cout << "Preco: ";
        cin >> cadastro[i].preco;

        cout << "Quantidade: ";
        cin >> cadastro[i].quantidade;
    }

    int mais_caro = indice_mais_caro(cadastro, tam);

    cout << "O Produto mais caro e:" << endl;
        cout << "Nome: " << cadastro[mais_caro].nome << endl;
        cout << "Preco: " << cadastro[mais_caro].preco << endl;

        delete[] cadastro;

        return 0;
}