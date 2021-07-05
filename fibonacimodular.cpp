#include <iostream>
using namespace std;

long long potencia(long long base, int exponente){
    long long resultado;
    if (exponente == 0)
        resultado = 1.0;
    else if (exponente > 0){
        resultado = base * potencia(base, exponente - 1);
    }
    else if (exponente < 0){
        resultado = 1.0 / base * potencia(base, exponente + 1);
    }
    return resultado;
}

long long Periodo_Pisano(long long m) {
    long long a = 0;
    long long b = 1;
    long long c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i ++;
    }
}

long long fibonacci(long long f, long long m) {
    long long mod = f % Periodo_Pisano(m);

    long long x = 0;
    long long y = 1;

    long long resultado = mod;

    for (int i = 1; i < mod; i++) {
        resultado = (x + y) % m;
        x = y;
        y = resultado;
    }

    return resultado % m;
}

int main() {
    long long e1=30;
    long long e2=20;
    cout << potencia(2, e1) << endl;
    cout << potencia(2, e2) << endl;
    cout << "F(2^30) % (2^20)->"<<fibonacci(potencia(2,e1), potencia(2,e2)) <<endl;

}






