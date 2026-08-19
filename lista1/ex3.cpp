#include <iostream>

using namespace std;

const unsigned char LER  = (1 << 0);
const unsigned char ESCREVER = (1 << 1);
const unsigned char EXECUTAR = (1 << 2);
const unsigned char DELETAR = (1 << 3);
const unsigned char ADMINISTRAR = (1 << 4);

void ligar_permissao(unsigned char& permissoes, unsigned char mascara)
{
   permissoes = permissoes | mascara;
}

void desligar_permissao(unsigned char& permissoes, unsigned char mascara)
{
    permissoes = permissoes & (~mascara);
}

bool verificar_permissao(unsigned char permissoes, unsigned char mascara)
{
    return (permissoes & mascara) != 0;
}

unsigned char intersecao_permisoes(unsigned char user1, unsigned char user2)
{
    return user1 & user2;
}

bool pode_administrar_e_executar(unsigned char permissoes)
{
    unsigned char mascara = ADMINISTRAR | EXECUTAR;

    return (permissoes & mascara) == mascara;
}

int main()
{
    unsigned char permissoes = 0;

    ligar_permissao(permissoes, LER);
    ligar_permissao(permissoes, EXECUTAR);
    ligar_permissao(permissoes, ADMINISTRAR);

    cout << verificar_permissao(permissoes, LER) << endl;
    cout << verificar_permissao(permissoes, DELETAR) << endl;
    cout << pode_administrar_e_executar(permissoes) << endl;

    unsigned char u1 = LER | ESCREVER;
    unsigned char u2 = ESCREVER | EXECUTAR;

    cout << (int)intersecao_permisoes(u1, u2) << endl;
    
    desligar_permissao(permissoes, LER);

    return 0;
}