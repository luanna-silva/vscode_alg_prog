#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//A) 
bool eh_palindromo(string s, int inicio, int fim)
{
    if (inicio >= fim)
    {
        return true;
    }

    // Converte os caracteres para minúsculo
    char esquerda = tolower(s[inicio]);
    char direita = tolower(s[fim]);

    // Se os caracteres forem diferentes não é palíndromo
    if (esquerda != direita)
    {
        return false;
    }

    // Compara os próximos caracteres,
    return eh_palindromo(s, inicio + 1, fim - 1);
}


//B)

string inverter(string s, int inicio, int fim)
{
    if (inicio >= fim)
    {
        return s;
    }

    // Troca o primeiro pelo último
    swap(s[inicio], s[fim]);

    return inverter(s, inicio + 1, fim - 1);
}


//C)

int contar_vogais(string s, int pos)
{
    if (pos == s.size())
    {
        return 0;
    }

    char c = tolower(s[pos]);

    int quantidade = 0;

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        quantidade = 1;
    }

    // Soma 1 se for vogal
    return quantidade + contar_vogais(s, pos + 1);
}

int main()
{
    string texto;

    cout << "Digite uma palavra: ";
    cin >> texto;

    if (eh_palindromo(texto, 0, texto.size() - 1))
    {
        cout << "E palindromo!" << endl;
    }
    else
    {
        cout << "Nao e palindromo." << endl;
    }

    string invertida = inverter(texto, 0, texto.size() - 1);

    cout << "String invertida: " << invertida << endl;

    int vogais = contar_vogais(texto, 0);

    cout << "Quantidade de vogais: " << vogais << endl;

    return 0;
}