#include <iostream>

using namespace std;

void imprimir_crescente(int n)
{
    if (n <= 0)
    {
        return;
    }

    imprimir_crescente(n - 1);

    cout << n << " ";
}

void imprimir_decrescente(int n)
{
    if (n <= 0)
    {
        return;
    }

    cout << n << " ";

    imprimir_decrescente(n - 1);
}

int main()
{
    int n;

    cout << "Digite um numero: ";
    cin >> n;

    cout << "Crescente: ";
    imprimir_crescente(n);

    cout << endl;

    cout << "Decrescente: ";
    imprimir_decrescente(n);

    cout << endl;

    return 0;
}

//refelxão: o lugar onde coloca o cout determina se a impressão acontece durante a descida ou durante a subida da recursão.