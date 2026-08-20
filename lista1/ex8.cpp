#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono; //permite usar as funções e classes sem digitar o prefixo std::chrono:: repetidamenteee

long long contador_chamadas = 0;

int fibonacci_contador(int n)
{
    contador_chamadas++;

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci_contador(n - 1) +
           fibonacci_contador(n - 2);
}

int main()
{
    int valores[] = {5, 10, 15, 20, 25, 30};

    for (int i = 0; i < 6; i++)
    {
        int n = valores[i];

        contador_chamadas = 0;

        auto inicio = high_resolution_clock::now();

        int resultado = fibonacci_contador(n);

        auto fim = high_resolution_clock::now();

        auto duracao =
            duration_cast<milliseconds>(
                fim - inicio
            );

        cout << "n = " << n << endl;
        cout << "Fibonacci = " << resultado << endl;
        cout << "Chamadas = "
             << contador_chamadas << endl;
        cout << "Tempo = "
             << duracao.count() << " ms" << endl;

        cout << "-------------------" << endl;
    }

    return 0;
}