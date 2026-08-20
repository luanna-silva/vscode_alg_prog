#include <iostream>

using namespace std;

int passos_para_zero(int num)
{
    if (num == 0)
    {
        return 0;
    }

    // Se for par
    if (num % 2 == 0)
    {
        return 1 + passos_para_zero(num / 2);
    }

    // Se for ímpar
    return 1 + passos_para_zero(num - 1);
}

int main()
{
    int num;

    cout << "Digite um numero: ";
    cin >> num;

    int resultado = passos_para_zero(num);

    cout << "Numero de passos: " << resultado << endl;

    return 0;
}