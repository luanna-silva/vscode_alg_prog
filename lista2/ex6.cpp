#include <iostream>

using namespace std;

#define MAX 50 //toda vez que escrever max troca por 50

struct ListaSequencial
{
    int dados[MAX];
    int tamanho;
};

void inicializar(ListaSequencial *lista);
bool inserir(ListaSequencial *lista, int posicao, int valor);
bool remover(ListaSequencial *lista, int posicao, int *valor_removido);
int buscar(ListaSequencial *lista, int valor);
int tamanho(ListaSequencial *lista);
bool esta_vazia(ListaSequencial *lista);
bool esta_cheia(ListaSequencial *lista);
void exibir(ListaSequencial *lista);
void inverter(ListaSequencial *lista);

void inicializar(ListaSequencial *lista)
{
    lista->tamanho = 0; 
}

bool esta_vazia(ListaSequencial *lista)
{
    return lista->tamanho == 0;
}

bool esta_cheia(ListaSequencial *lista)
{
    return lista->tamanho == MAX;
}

int tamanho(ListaSequencial *lista)
{
    return lista->tamanho;
}

int buscar(ListaSequencial *lista, int valor)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (lista->dados[i] == valor)
        {
            return i; 
        }
    }
    return -1; 
}

bool inserir(ListaSequencial *lista, int posicao, int valor)
{

    if (esta_cheia(lista))
    {
        cout << "[Erro] A lista esta cheia!\n";
        return false;
    }
    if (posicao < 0 || posicao > lista->tamanho)
    {
        cout << "[Erro] Posicao invalida para insercao!\n";
        return false;
    }

    // desloca para a direita para abrir espaço
    for (int i = lista->tamanho; i > posicao; i--)
    {
        lista->dados[i] = lista->dados[i - 1];
    }

    //insere novo elemento e atualiza o tamanho
    lista->dados[posicao] = valor;
    lista->tamanho++;
    
    return true;
}

bool remover(ListaSequencial *lista, int posicao, int *valor_removido)
{
    if (esta_vazia(lista))
    {
        cout << "[Erro] A lista esta vazia!\n";
        return false;
    }
    if (posicao < 0 || posicao >= lista->tamanho)
    {
        cout << "[Erro] Posicao invalida para remocao!\n";
        return false;
    }

    *valor_removido = lista->dados[posicao];

    for (int i = posicao; i < lista->tamanho - 1; i++)
    {
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->tamanho--; 
    return true;
}

void exibir(ListaSequencial *lista)
{
    if (esta_vazia(lista))
    {
        cout << "A lista esta vazia.\n";
        return;
    }

    cout << "Lista: [";
    for (int i = 0; i < lista->tamanho; i++)
    {
        cout << lista->dados[i] << (i < lista->tamanho - 1 ? ", " : "");
    }
    cout << "]\n";
}

void inverter(ListaSequencial *lista)
{
    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio < fim)
    {
        // Troca o elemento do início com o do fim
        int temp = lista->dados[inicio];
        lista->dados[inicio] = lista->dados[fim];
        lista->dados[fim] = temp;

        inicio++;
        fim--;
    }
    cout << "Lista invertida com sucesso!\n";
}

int main()
{
    ListaSequencial lista;
    inicializar(&lista);
    
    int opcao = -1;
    
    while (opcao != 0)
    {
        cout << "\nMenu:\n";
        cout << "1. Inserir\n";
        cout << "2. Remover\n";
        cout << "3. Buscar\n";
        cout << "4. Inverter\n";
        cout << "5. Exibir\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 1)
        {
            int pos, val;
            cout << "Posicao: "; cin >> pos;
            cout << "Valor: "; cin >> val;
            if (inserir(&lista, pos, val))
            {
                cout << "Elemento " << val << " inserido na posicao " << pos << ".\n";
            }
        }
        else if (opcao == 2)
        {
            int pos, val_removido;
            cout << "Posicao: "; cin >> pos;
            if (remover(&lista, pos, &val_removido))
            {
                cout << "Elemento " << val_removido << " removido da posicao " << pos << ".\n";
            }
        }
        else if (opcao == 3)
        {
            int val;
            cout << "Valor a buscar: "; cin >> val;
            int pos = buscar(&lista, val);
            if (pos != -1)
            {
                cout << "Elemento encontrado na posicao " << pos << ".\n";
            }
            else
            {
                cout << "Elemento nao encontrado na lista.\n";
            }
        }
        else if (opcao == 4)
        {
            inverter(&lista);
        }
        else if (opcao == 5)
        {
            exibir(&lista);
        }
        else if (opcao != 0)
        {
            cout << "Opcao invalida!\n";
        }
    }

    return 0;
}