#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
struct Data
{
    int dia;
    int mes;
    int ano;
};

Data criar_data(int dia, int mes, int ano);
bool eh_bissexto(int ano);
int dias_no_mes(int mes, int ano);
bool data_valida(Data d);
Data somar_dias(Data d, int dias);
int diferenca_dias(Data d1, Data d2);
int dia_da_semana(Data d);
void imprimir(Data d);
void imprimir_por_extenso(Data d);

int dias_desde_ano_zero(Data d);

Data criar_data(int dia, int mes, int ano)
{
    Data d;
    d.dia = dia;
    d.mes = mes;
    d.ano = ano;
    return d;
}

bool eh_bissexto(int ano)
{
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        return true;
    }
    return false;
}

int dias_no_mes(int mes, int ano)
{
    if (mes == 2)
    {
        if (eh_bissexto(ano))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }
    
    return 31;
}

bool data_valida(Data d)
{
    if (d.ano < 1) return false;
    if (d.mes < 1 || d.mes > 12) return false;
    if (d.dia < 1 || d.dia > dias_no_mes(d.mes, d.ano)) return false;
    
    return true;
}

Data somar_dias(Data d, int dias)
{
    d.dia += dias;
    
    while (d.dia > dias_no_mes(d.mes, d.ano))
    {
        d.dia -= dias_no_mes(d.mes, d.ano);
        d.mes++;
        
        if (d.mes > 12)
        {
            d.mes = 1;
            d.ano++;
        }
    }
    
    return d;
}

int dias_desde_ano_zero(Data d)
{
    int total_dias = d.dia;
    
    total_dias += (d.ano - 1) * 365;
    total_dias += (d.ano - 1) / 4;
    total_dias -= (d.ano - 1) / 100;
    total_dias += (d.ano - 1) / 400;
    
    for (int i = 1; i < d.mes; i++)
    {
        total_dias += dias_no_mes(i, d.ano);
    }
    
    return total_dias;
}

int diferenca_dias(Data d1, Data d2)
{
    int dias_d1 = dias_desde_ano_zero(d1);
    int dias_d2 = dias_desde_ano_zero(d2);
    
    return abs(dias_d1 - dias_d2);
}

int dia_da_semana(Data d)
{
    int q = d.dia;
    int m = d.mes;
    int ano = d.ano;
    
    if (m == 1 || m == 2)
    {
        m += 12;
        ano -= 1;
    }
    
    int K = ano % 100;
    int J = ano / 100;
    
    int h = (q + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) + 5 * J) % 7;
    
    return h; // 0=sabado, 1=domingo, 2=segunda, 3=terca, 4=quarta, 5=quinta, 6=sexta
}

void imprimir(Data d)
{
    cout << setfill('0') << setw(2) << d.dia << "/" 
         << setw(2) << d.mes << "/" 
         << d.ano;
}

void imprimir_por_extenso(Data d)
{
    const string meses[] = {
        "", "janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
    };
    
    cout << d.dia << " de " << meses[d.mes] << " de " << d.ano;
}

int main()
{
    Data inicio = criar_data(1, 1, 2024);
    Data fim = criar_data(31, 12, 2024);
    Data natal = criar_data(25, 12, 2024);
    
    cout << "1. Diferenca entre "; 
    imprimir(inicio); cout << " e "; imprimir(fim); 
    cout << " = " << diferenca_dias(inicio, fim) << " dias.\n";
    
    cout << "2. Somar 30 dias a "; imprimir(inicio); cout << " = ";
    imprimir(somar_dias(inicio, 30)); cout << "\n";

    cout << "3. Somar 365 dias a "; imprimir(inicio); cout << " = ";
    imprimir(somar_dias(inicio, 365)); cout << "\n";
    
    cout << "4. O dia da semana de "; imprimir_por_extenso(natal); cout << " eh: ";
    
    int dia_sem = dia_da_semana(natal);
    const string dias_semana[] = {"Sabado", "Domingo", "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira"};
    cout << dias_semana[dia_sem] << " (Codigo: " << dia_sem << ")\n";

    return 0;
}