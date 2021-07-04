#include <iostream>
using namespace std;

double fibonaci(double l)
{
    double  x = 1, y = 0, aux = 0;

    for (int i = 2; i <= l; i++)
    {
        aux = y;
        y = x;
        x += aux;
    }
    return y;
}

void imprimir(double limite) {
    for (double i = 1; i < limite; i++)
        cout << "..[" << i << "]..->" << fibonaci(i) << "\n";
}

int main()
{
    double  x;
    cout << "Agregar limite->";
    cin >> x;
    imprimir(x + 1);
    return  0;
}