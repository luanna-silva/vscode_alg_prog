#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846; // Fornecido na dica

struct Vetor3D 
{
    double x, y, z;
};

Vetor3D criar_vetor(double x, double y, double z);
Vetor3D somar(Vetor3D v1, Vetor3D v2);
Vetor3D subtrair(Vetor3D v1, Vetor3D v2);
Vetor3D multiplicar_por_escalar(Vetor3D v, double k);
double produto_escalar(Vetor3D v1, Vetor3D v2);
Vetor3D produto_vetorial(Vetor3D v1, Vetor3D v2);
double norma(Vetor3D v);
Vetor3D normalizar(Vetor3D v);
bool sao_ortogonais(Vetor3D v1, Vetor3D v2);
bool sao_paralelos(Vetor3D v1, Vetor3D v2);
double angulo_entre(Vetor3D v1, Vetor3D v2);
void imprimir(Vetor3D v);

//implementacao
Vetor3D criar_vetor(double x, double y, double z) 
{
    Vetor3D v;
    v.x = x; v.y = y; v.z = z;
    return v;
}

Vetor3D somar(Vetor3D v1, Vetor3D v2) 
{
    return criar_vetor(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vetor3D subtrair(Vetor3D v1, Vetor3D v2) 
{
    return criar_vetor(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vetor3D multiplicar_por_escalar(Vetor3D v, double k) 
{
    return criar_vetor(v.x * k, v.y * k, v.z * k);
}

double produto_escalar(Vetor3D v1, Vetor3D v2) 
{
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vetor3D produto_vetorial(Vetor3D v1, Vetor3D v2) 
{
    double x = (v1.y * v2.z) - (v1.z * v2.y);
    double y = (v1.z * v2.x) - (v1.x * v2.z);
    double z = (v1.x * v2.y) - (v1.y * v2.x);
    return criar_vetor(x, y, z);
}

double norma(Vetor3D v)
{
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

Vetor3D normalizar(Vetor3D v)
{
    double n = norma(v);
    if (n == 0) return criar_vetor(0, 0, 0);
    return criar_vetor(v.x / n, v.y / n, v.z / n);
}

bool sao_ortogonais(Vetor3D v1, Vetor3D v2) 
{
    return produto_escalar(v1, v2) == 0; 
}

bool sao_paralelos(Vetor3D v1, Vetor3D v2) 
{
    Vetor3D cruzado = produto_vetorial(v1, v2);

    return (cruzado.x == 0 && cruzado.y == 0 && cruzado.z == 0);
}

double angulo_entre(Vetor3D v1, Vetor3D v2) 
{
    double prod_esc = produto_escalar(v1, v2);
    double normas = norma(v1) * norma(v2);
    if (normas == 0) return 0; 
    
    double cos_theta = prod_esc / normas;
    double radianos = acos(cos_theta); 

    return radianos * (180.0 / PI);
}

void imprimir(Vetor3D v) 
{
    cout << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}


int main() 
{
    Vetor3D a = criar_vetor(1, 0, 0);
    Vetor3D b = criar_vetor(0, 1, 0);
    Vetor3D c = criar_vetor(1, 2, 3);

    cout << "Vetor a: "; imprimir(a); cout << endl;
    cout << "Vetor b: "; imprimir(b); cout << endl;
    cout << "Vetor c: "; imprimir(c); cout << "\n\n";

    cout << "a e b sao ortogonais? " << (sao_ortogonais(a, b) ? "Sim" : "Nao") << endl;

    // a x b = (0, 0, 1)?
    cout << "Produto vetorial a x b: ";
    imprimir(produto_vetorial(a, b));
    cout << endl;

    cout << "Norma de c: " << norma(c) << endl;
    cout << "c normalizado: ";
    imprimir(normalizar(c));
    cout << endl;

    // Angulo entre a e b
    cout << "Angulo entre a e b: " << angulo_entre(a, b) << " graus\n";

    return 0;
}