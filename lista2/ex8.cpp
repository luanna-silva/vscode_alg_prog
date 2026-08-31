#include <iostream>

using namespace std;

struct No
{
    int dado;
    No *proximo;
};

struct ListaEncadeada
{
    No *cabeca;
    No *cauda; 
    int tamanho;
};

void inicializar(ListaEncadeada *lista)
{
    lista->cabeca = nullptr;
    lista->cauda = nullptr;
    lista->tamanho = 0;
}

void inserir_inicio(ListaEncadeada *lista, int valor)
{
    No *novo_no = new No;
    novo_no->dado = valor;
    novo_no->proximo = lista->cabeca;
    
    lista->cabeca = novo_no;
    
    if (lista->tamanho == 0)
    {
        lista->cauda = novo_no;
    }
    
    lista->tamanho++;
}

void inserir_fim(ListaEncadeada *lista, int valor)
{
    No *novo_no = new No;
    novo_no->dado = valor;
    novo_no->proximo = nullptr;
    
    if (lista->tamanho == 0)
    {
        lista->cabeca = novo_no;
        lista->cauda = novo_no;
    }
    else
    {
        lista->cauda->proximo = novo_no;
        lista->cauda = novo_no;
    }
    
    lista->tamanho++;
}

bool remover_inicio(ListaEncadeada *lista, int *valor_removido)
{
    if (lista->tamanho == 0)
    {
        return false;
    }
    
    No *no_removido = lista->cabeca;
    *valor_removido = no_removido->dado;
    
    lista->cabeca = no_removido->proximo;
    delete no_removido;
    
    lista->tamanho--;
    
    if (lista->tamanho == 0)
    {
        lista->cauda = nullptr;
    }
    
    return true;
}

bool remover_fim(ListaEncadeada *lista, int *valor_removido)
{
    if (lista->tamanho == 0)
    {
        return false;
    }
    
    if (lista->tamanho == 1)
    {
        return remover_inicio(lista, valor_removido);
    }
    
    No *atual = lista->cabeca;
    while (atual->proximo != lista->cauda)
    {
        atual = atual->proximo;
    }
    
    *valor_removido = lista->cauda->dado;
    delete lista->cauda;
    
    lista->cauda = atual;
    lista->cauda->proximo = nullptr;
    lista->tamanho--;
    
    return true;
}

bool remover_valor(ListaEncadeada *lista, int valor)
{
    if (lista->tamanho == 0)
    {
        return false;
    }
    
    bool removeu_algum = false;
    No *atual = lista->cabeca;
    No *anterior = nullptr;
    
    while (atual != nullptr)
    {
        if (atual->dado == valor)
        {
            No *remover = atual;
            
            if (anterior == nullptr)
            {
                lista->cabeca = atual->proximo;
                atual = lista->cabeca;
                if (lista->cabeca == nullptr)
                {
                    lista->cauda = nullptr;
                }
            }
            else
            {
                anterior->proximo = atual->proximo;
                if (atual == lista->cauda)
                {
                    lista->cauda = anterior;
                }
                atual = atual->proximo;
            }
            
            delete remover;
            lista->tamanho--;
            removeu_algum = true;
        }
        else
        {
            anterior = atual;
            atual = atual->proximo;
        }
    }
    
    return removeu_algum;
}

int buscar(ListaEncadeada *lista, int valor)
{
    No *atual = lista->cabeca;
    int indice = 0;
    
    while (atual != nullptr)
    {
        if (atual->dado == valor)
        {
            return indice;
        }
        atual = atual->proximo;
        indice++;
    }
    
    return -1;
}

void exibir(ListaEncadeada *lista)
{
    No *atual = lista->cabeca;
    
    while (atual != nullptr)
    {
        cout << atual->dado << " -> ";
        atual = atual->proximo;
    }
    cout << "NULL\n";
}

void destruir(ListaEncadeada *lista)
{
    No *atual = lista->cabeca;
    
    while (atual != nullptr)
    {
        No *proximo = atual->proximo;
        delete atual; 
        atual = proximo;
    }
    
    lista->cabeca = nullptr;
    lista->cauda = nullptr;
    lista->tamanho = 0;
}

int main()
{
    ListaEncadeada lista;
    inicializar(&lista);
    
    cout << "Testando insercoes\n";
    inserir_inicio(&lista, 10);
    inserir_inicio(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_fim(&lista, 10);
    exibir(&lista);
    
    int valor;
    if (remover_inicio(&lista, &valor))
    {
        cout << "Removido do inicio: " << valor << "\n";
    }
    exibir(&lista);
    
    if (remover_fim(&lista, &valor))
    {
        cout << "Removido do fim: " << valor << "\n";
    }
    exibir(&lista);
    
    inserir_inicio(&lista, 10);
    inserir_fim(&lista, 10);
    exibir(&lista);
    remover_valor(&lista, 10);
    exibir(&lista);
    
    destruir(&lista);
    exibir(&lista);

    return 0;
}