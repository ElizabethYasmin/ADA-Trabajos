#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

const int MOD = 3000000004;//evitar desborde del int

void Mmultiplicacion(int a[][2], int b[][2], int c[][2])// método de multiplicación al cuadrado (potencia rápida)
{
    int aux[][2] = { {0, 0}, {0, 0} };
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
            {
                long long x = aux[i][j] + (long long)a[i][k] * b[k][j];
                aux[i][j] = x % MOD;
            }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            c[i][j] = aux[i][j];
}


int FIBONACI(long long n)
{
    int x[2] = { 1, 1 };

    int res[][2] = { {1, 0}, {0, 1} };
    int t[][2] = { {1, 1}, {1, 0} };
    long long k = n - 1;
    while (k)
    {
        if (k & 1) Mmultiplicacion(res, t, res);
        Mmultiplicacion(t, t, t);
        k >>= 1;
    }

    int c[2] = { 0, 0 };
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            long long r = c[i] + (long long)x[j] * res[j][i];
            c[i] = r % MOD;
        }

    return c[0];
}

int Fibonacci(int n) {
    double sqrt5 = sqrt(5);
    double alfa = (1 + sqrt5) / 2;
    double beta = (1 - sqrt5) / 2;
    double ret = (pow(alfa, n) - pow(beta, n)) / sqrt5;
    return (int)ret;
}

int main()
{
    
    //cout<<Fibonacci(8);
    
    long long n;

    cout << "Agregar el limite->"; cin >> n;
    cout << FIBONACI(n) << endl;

    return 0;
    


}
