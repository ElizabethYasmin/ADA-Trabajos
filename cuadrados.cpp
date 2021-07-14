

#include <iostream>
using namespace std;
#include <stdlib.h>
int Fila, Col;
int** matriz;
/*
void reservaM(int Fila,int  Col) {
matriz = new int*[Fila];
for (int i = 0; i < Fila; i++) {
	matriz[i] = new int[Col];
	}
}
*/


long long countSquares(long long m, long long n)
{
	// Si n es más pequeño, intercambia myn
	if (n < m)
		swap(m, n);// n es una dimensión mayor


// aplicar fórmula
	return m * (m + 1) * (2 * m + 1) /
		6 + (n - m) * m * (m + 1) / 2;
}


//forma recursiva de calculos de cuadrados
//indice de fila * indice de columna + diagonal (fila-1,columna-1)

long long cuadrados(long long n, long long m) {
	long long r;
	if (n==0 && m == 0) {
		return 0;
	}
	else {
		r = n * m + cuadrados(n - 1, m - 1);
		//cout << r;

	}
	return r;
}

//memoizacion
int cuadradosM(int n, int m) {
		int *ma = new int[m];
		

		for (int i = 0; i < m; i++) {
			
				if (m==0 && n == 0) {
						ma[i] = 0;
				}
				else {
					ma[i] = n * m + cuadradosM(n - 1, m - 1);
				}
				return ma[i];
			
		}
		
}

int main() {
	long long f, c;
	cout << "Filas"; cin >> f;
	cout << "Columnas"; cin >> c;
	//reservaM(f, c);
	cout << "Recursivamente-> "<<cuadrados(f, c)<<endl;
	cout << "memoizacion-> " << cuadradosM(f, c) << endl;
	cout << "Formula-> "<< countSquares(f, c)<<endl;

}

