#include <iostream>

using namespace std;

int soma_array(int arr[], int n)
{
    if (n == 0)
        return 0;

    return arr[0] + soma_array(arr + 1, n - 1);
}

long long produto_array(int arr[], int n)
{
    if (n == 0)
        return 1;

    return arr[0] * produto_array(arr + 1, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    cout << "Soma: "
         << soma_array(arr, 5) << endl;

    cout << "Produto: "
         << produto_array(arr, 5) << endl;

    return 0;
}