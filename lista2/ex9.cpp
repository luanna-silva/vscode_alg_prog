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

void inverter_iterativa(ListaEncadeada *lista)
{
    No *anterior = nullptr;
    No *atual = lista->cabeca;
    
    lista->cauda = lista->cabeca; 
    
    while (atual != nullptr)
    {
        No *proximo_temp = atual->proximo;
        atual->proximo = anterior;
        
        anterior = atual;
        atual = proximo_temp;
    }
    
    lista->cabeca = anterior;
}

No* auxiliar_inverter_recursiva(No *atual, No *anterior)
{
    if (atual == nullptr)
    {
        return anterior; 
    }
    
    No *proximo_temp = atual->proximo;
    atual->proximo = anterior;
    
    return auxiliar_inverter_recursiva(proximo_temp, atual);
}

void inverter_recursiva(ListaEncadeada *lista)
{
    lista->cauda = lista->cabeca;
    lista->cabeca = auxiliar_inverter_recursiva(lista->cabeca, nullptr);
}

void inserir_ordenado(ListaEncadeada *lista, int valor)
{
    No *novo = new No;
    novo->dado = valor;
    novo->proximo = nullptr;
    
    if (lista->cabeca == nullptr || lista->cabeca->dado >= valor)
    {
        novo->proximo = lista->cabeca;
        lista->cabeca = novo;
        
        if (lista->tamanho == 0)
        {
            lista->cauda = novo;
        }
    }
    
    else
    {
        No *atual = lista->cabeca;
        
        while (atual->proximo != nullptr && atual->proximo->dado < valor)
        {
            atual = atual->proximo;
        }
        
        novo->proximo = atual->proximo;
        atual->proximo = novo;
        
        if (novo->proximo == nullptr)
        {
            lista->cauda = novo;
        }
    }
    
    lista->tamanho++;
}

int encontrar_meio(ListaEncadeada *lista)
{
    if (lista->cabeca == nullptr)
    {
        return -1; 
    }
    
    No *lento = lista->cabeca;
    No *rapido = lista->cabeca;
    
    while (rapido != nullptr && rapido->proximo != nullptr)
    {
        lento = lento->proximo;
        rapido = rapido->proximo->proximo;
    }
    
    return lento->dado;
}

bool tem_ciclo(ListaEncadeada *lista)
{
    if (lista->cabeca == nullptr)
    {
        return false;
    }
    
    No *lento = lista->cabeca;
    No *rapido = lista->cabeca;
    
    while (rapido != nullptr && rapido->proximo != nullptr)
    {
        lento = lento->proximo;
        rapido = rapido->proximo->proximo;

        if (lento == rapido)
        {
            return true; 
        }
    }
    
    return false;
}

int main()
{
    ListaEncadeada lista;
    inicializar(&lista);

    inserir_ordenado(&lista, 10);
    inserir_ordenado(&lista, 5);
    inserir_ordenado(&lista, 20);
    inserir_ordenado(&lista, 15);
    exibir(&lista);
    
    cout << "elemento do meio: " << encontrar_meio(&lista) << "\n";
    
    inserir_ordenado(&lista, 25);
    cout << "Lista apos inserir 25: ";
    exibir(&lista);
    cout << "novo elemento do meio: " << encontrar_meio(&lista) << "\n";
    
    cout << "Iterativa: ";
    inverter_iterativa(&lista);
    exibir(&lista);
    
    cout << "Recursiva: ";
    inverter_recursiva(&lista);
    exibir(&lista);
    
    cout << "a lista tem ciclo agora? " << (tem_ciclo(&lista) ? "Sim" : "Nao") << "\n";
    
    if (lista.cauda != nullptr)
    {
        lista.cauda->proximo = lista.cabeca;
    }
    
    cout << "A lista tem ciclo agora? " << (tem_ciclo(&lista) ? "Sim" : "Nao") << "\n";
    
    return 0;
}