#include <iostream>

using namespace std;

#define MAX 5

void imprimir_labirinto(int labirinto[][MAX], int n, int m) 
{
    cout << "Estado atual:\n";
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        // ATENÇÃO: Aqui dentro não pode ter \n nem endl
        if (labirinto[i][j] == 0) cout << ". ";      
        else if (labirinto[i][j] == 1) cout << "# "; 
        else if (labirinto[i][j] == 2) cout << "¨% "; 
    }
    cout << "\n"; 
    }
}

bool resolver_labirinto(int labirinto[][MAX], int n, int m, int x, int y, int destino_x, int destino_y, int &passos) 
{
    if (x < 0 || x >= n || y < 0 || y >= m) return false;

    //Verifica se é parede ou se já visitado 
    if (labirinto[x][y] == 1 || labirinto[x][y] == 2) return false;

    //Marca como visitado 
    labirinto[x][y] = 2;
    passos++; 

    imprimir_labirinto(labirinto, n, m);

    //Verifica se chegou ao destino
    if (x == destino_x && y == destino_y) {
        return true;
    }

    if (resolver_labirinto(labirinto, n, m, x + 1, y, destino_x, destino_y, passos)) return true;
    if (resolver_labirinto(labirinto, n, m, x, y + 1, destino_x, destino_y, passos)) return true;
    if (resolver_labirinto(labirinto, n, m, x - 1, y, destino_x, destino_y, passos)) return true;
    if (resolver_labirinto(labirinto, n, m, x, y - 1, destino_x, destino_y, passos)) return true;

    labirinto[x][y] = 0;
    
    return false;
}

int main() 
{
    int labirinto[MAX][MAX] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int passos = 0;
    
    bool encontrou = resolver_labirinto(labirinto, MAX, MAX, 0, 0, 4, 4, passos);

    if (encontrou) {
        cout << "\nCaminho.\n";
    } else {
        cout << "\nNao ha caminho possivel.\n";
    }
    
    cout << "Total de movimentos (passos recursivos): " << passos << "\n";

    return 0;
}