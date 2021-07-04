#include <iostream>
using namespace std;

long fibonaci(long l)
{
    long  x = 1, y = 0, aux = 0;

    for (long i = 2; i <= l; i++)
    {
        aux = y;
        y = x;
        x += aux;
    }
    return y;
}

void imprimir(int limite) {
    for (int i = 1; i < limite; i++)
        cout << "..[" << i << "]..->" << fibonaci(i) << "\n";
}

int main()
{
    long x;
    cout << "Agregar limite->";
    cin >> x;
    imprimir(x + 1);
    return  0;
}