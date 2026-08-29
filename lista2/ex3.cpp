#include <iostream>
#include <cmath> //sei que era para usar math.h, mas cmath é a de c++

using namespace std;

//interface
struct Complexo 
{
    double real;
    double imag;
};

Complexo criar_complexo(double real, double imag);
Complexo somar(Complexo a, Complexo b);
Complexo subtrair(Complexo a, Complexo b);
Complexo multiplicar(Complexo a, Complexo b);
Complexo dividir(Complexo a, Complexo b);
Complexo conjugado(Complexo z);
double modulo(Complexo z);
double argumento(Complexo z);
void imprimir(Complexo z);

//implementacao
Complexo criar_complexo(double real, double imag) 
{
    Complexo z;
    z.real = real;
    z.imag = imag;
    return z;
}

Complexo somar(Complexo a, Complexo b) 
{
    return criar_complexo(a.real + b.real, a.imag + b.imag);
}

Complexo subtrair(Complexo a, Complexo b) 
{
    return criar_complexo(a.real - b.real, a.imag - b.imag);
}

Complexo multiplicar(Complexo a, Complexo b) 
{
    //(a + bi)(c + di) = (ac - bd) + (ad + bc)i
    double r = (a.real * b.real) - (a.imag * b.imag);
    double i = (a.real * b.imag) + (a.imag * b.real);
    return criar_complexo(r, i);
}

Complexo dividir(Complexo a, Complexo b) 
{
    double divisor = (b.real * b.real) + (b.imag * b.imag);
    
    if (divisor == 0) 
    {
        cout << "[Erro] Divisao por zero! ";
        return criar_complexo(0, 0); 
    }
    
    double r = ((a.real * b.real) + (a.imag * b.imag)) / divisor;
    double i = ((a.imag * b.real) - (a.real * b.imag)) / divisor;
    return criar_complexo(r, i);
}

Complexo conjugado (Complexo z) 
{
    return criar_complexo(z.real, -z.imag);
}

double modulo(Complexo z) 
{

    return sqrt((z.real * z.real) + (z.imag * z.imag));
}

double argumento(Complexo z) 
{
    //radianos
    return atan2(z.imag, z.real);
}

void imprimir(Complexo z) 
{
    cout << z.real;
    if (z.imag >= 0) 
    {
        cout << " + " << z.imag << "i";
    } else 
    {
        cout << " - " << abs(z.imag) << "i"; // abs() remove o sinal negativo duplicado
    }
}

int main() 
{
    Complexo z1 = criar_complexo(3, 4);
    Complexo z2 = criar_complexo(1, -2);

    cout << "z1 = "; imprimir(z1); cout << endl;
    cout << "z2 = "; imprimir(z2); cout << endl;

    cout << "|z1| = " << modulo(z1) << endl;
    
    cout << "z1 + z2 = "; imprimir(somar(z1, z2)); cout << endl;
    cout << "z1 * z2 = "; imprimir(multiplicar(z1, z2)); cout << endl;

    Complexo z3 = criar_complexo(0, 0);
    cout << "z1 / z3 = "; 
    imprimir(dividir(z1, z3)); 
    cout << endl;

    return 0;
}