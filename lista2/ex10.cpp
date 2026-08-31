#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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

struct ListaSequencial
{
    int *dados;
    int tamanho;
};

double medir_tempo_insercao_inicio(int n, int tipo_estrutura)
{
    clock_t inicio, fim;
    
    if (tipo_estrutura == 0) 
    {
        ListaSequencial seq;
        seq.dados = new int[n];
        seq.tamanho = 0;
        
        inicio = clock();
        for (int i = 0; i < n; i++)
        {
            for (int j = seq.tamanho; j > 0; j--)
            {
                seq.dados[j] = seq.dados[j - 1];
            }
            seq.dados[0] = i;
            seq.tamanho++;
        }
        fim = clock();
        delete[] seq.dados;
    }
    else 
    {
        ListaEncadeada enc;
        enc.cabeca = nullptr;
        enc.cauda = nullptr;
        enc.tamanho = 0;
        
        inicio = clock();
        for (int i = 0; i < n; i++)
        {
            No *novo = new No;
            novo->dado = i;
            novo->proximo = enc.cabeca;
            enc.cabeca = novo;
            if (enc.tamanho == 0) enc.cauda = novo;
            enc.tamanho++;
        }
        fim = clock();
        
        No *atual = enc.cabeca;
        while (atual != nullptr)
        {
            No *prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }
    
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_insercao_fim(int n, int tipo_estrutura)
{
    clock_t inicio, fim;
    
    if (tipo_estrutura == 0)
    {
        ListaSequencial seq;
        seq.dados = new int[n];
        seq.tamanho = 0;
        
        inicio = clock();
        for (int i = 0; i < n; i++)
        {
            seq.dados[seq.tamanho] = i;
            seq.tamanho++;
        }
        fim = clock();
        delete[] seq.dados;
    }
    else
    {
        ListaEncadeada enc;
        enc.cabeca = nullptr;
        enc.cauda = nullptr;
        enc.tamanho = 0;
        
        inicio = clock();
        for (int i = 0; i < n; i++)
        {
            No *novo = new No;
            novo->dado = i;
            novo->proximo = nullptr;
            
            if (enc.tamanho == 0)
            {
                enc.cabeca = novo;
                enc.cauda = novo;
            }
            else
            {
                enc.cauda->proximo = novo;
                enc.cauda = novo;
            }
            enc.tamanho++;
        }
        fim = clock();
        
        No *atual = enc.cabeca;
        while (atual != nullptr)
        {
            No *prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_acesso_aleatorio(int n, int num_acessos, int tipo_estrutura)
{
    int *indices = new int[num_acessos];
    for (int i = 0; i < num_acessos; i++)
    {
        indices[i] = rand() % n;
    }
    
    clock_t inicio, fim;
    volatile int lixo;
    
    if (tipo_estrutura == 0)
    {
        int *dados = new int[n];
        for (int i = 0; i < n; i++) dados[i] = i;
        
        inicio = clock();
        for (int i = 0; i < num_acessos; i++)
        {
            lixo = dados[indices[i]];
        }
        fim = clock();
        delete[] dados;
    }
    else
    {
        ListaEncadeada enc;
        enc.cabeca = nullptr;
        enc.cauda = nullptr;
        enc.tamanho = 0;
        for (int i = 0; i < n; i++)
        {
            No *novo = new No;
            novo->dado = i;
            novo->proximo = nullptr;
            if (enc.tamanho == 0) enc.cabeca = novo;
            else enc.cauda->proximo = novo;
            enc.cauda = novo;
            enc.tamanho++;
        }
        
        inicio = clock();
        for (int i = 0; i < num_acessos; i++)
        {
            No *atual = enc.cabeca;
            int pos = indices[i];
            for (int k = 0; k < pos; k++)
            {
                atual = atual->proximo;
            }
            lixo = atual->dado;
        }
        fim = clock();
        
        No *atual = enc.cabeca;
        while (atual != nullptr)
        {
            No *prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }
    
    delete[] indices;
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

void gerar_tabela_resultados()
{
    int Ns[] = {1000, 5000, 10000, 50000};
    int qtd_N = 4;
    int num_acessos = 10000;
    
    cout << fixed << setprecision(5);
    cout << setw(35) << "Operacao " << setw(10) << "N=1.000" << setw(10) << "N=5.000" << setw(10) << "N=10.000" << setw(10) << "N=50.000\n";
    
    cout << setw(34) << "inicio (Sequencial) ";
    for(int i = 0; i < qtd_N; i++) cout << setw(10) << medir_tempo_insercao_inicio(Ns[i], 0);
    cout << "\n";
    
    cout << setw(34) << "inicio (Encadeada) ";
    for(int i = 0; i < qtd_N; i++) cout << setw(10) << medir_tempo_insercao_inicio(Ns[i], 1);
    cout << "\n";
    
    cout << setw(34) << "fim (Sequencial) ";
    for(int i = 0; i < qtd_N; i++) cout << setw(10) << medir_tempo_insercao_fim(Ns[i], 0);
    cout << "\n";
    
    cout << setw(34) << "fim (Encadeada) ";
    for(int i = 0; i < qtd_N; i++) cout << setw(10) << medir_tempo_insercao_fim(Ns[i], 1);
    cout << "\n";
    
    cout << setw(34) << "acesso aleatorio (Sequencial) ";
    for(int i = 0; i < qtd_N; i++) cout << setw(10) << medir_tempo_acesso_aleatorio(Ns[i], num_acessos, 0);
    cout << "\n";
    
    cout << setw(34) << "acesso aleatorio (Encadeada) ";
    for(int i = 0; i < qtd_N; i++) cout << setw(10) << medir_tempo_acesso_aleatorio(Ns[i], num_acessos, 1);
    cout << "\n";
    
}

int main()
{
    srand(time(NULL));
    gerar_tabela_resultados();
    
    return 0;
}