
#include <iostream>

using namespace std;

long long potencia_ingenua(int base, int expoente)
{
    if (expoente == 0)
        return 1;

    return base * potencia_ingenua(base, expoente - 1);
}

long long potencia_rapida(long long base, int expoente)
{
    if (expoente == 0)
        return 1;

    long long metade = potencia_rapida(base, expoente / 2);

    if (expoente % 2 == 0)
    {
        return metade * metade;
    }
    else
    {
        return base * metade * metade;
    }
}

long long contador_ingenua = 0;
long long contador_rapida = 0;

long long potencia_ingenua_contador(long long base, int expoente)
{
    contador_ingenua++;

    if (expoente == 0)
        return 1;

    return base *
           potencia_ingenua_contador(base, expoente - 1);
}

long long potencia_rapida_contador(long long base, int expoente)
{
    contador_rapida++;

    if (expoente == 0)
        return 1;

    long long metade = potencia_rapida_contador(base, expoente / 2);

    if (expoente % 2 == 0)
        return metade * metade;

    return base * metade * metade;
}

int main()
{
    int expoente = 30;

    contador_ingenua = 0;
    contador_rapida = 0;

    long long resultado_ingenua =
        potencia_ingenua_contador(2, expoente);

    long long resultado_rapida =
        potencia_rapida_contador(2, expoente);

    cout << "2^" << expoente << endl;

    cout << "Resultado (ingenua): "
         << resultado_ingenua << endl;

    cout << "Chamadas (ingenua): "
         << contador_ingenua << endl;

    cout << "Resultado (rapida): "
         << resultado_rapida << endl;

    cout << "Chamadas (rapida): "
         << contador_rapida << endl;

    return 0;
}