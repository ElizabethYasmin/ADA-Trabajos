//Elizabeth Yasmin Huanca Parqui

#include<iostream>
#include<ctime>
#include<stdlib.h>
unsigned t0, t1;
using namespace std;

void quickSort(int *arreglo, int l, int r){
	if (l < r){
		int i = l, j = r, x = *(arreglo+l);
		while (i < j){
			while (i < j && *(arreglo+j) >= x) // Encuentra el primer número menor que x de derecha a izquierda
				j--;
			if (i < j)
				*(arreglo+i++) = *(arreglo + j);
			while (i < j && *(arreglo+i) < x)// Encuentra el primer número mayor o igual a x de izquierda a derecha
				i++;
			if (i < j)
				*(arreglo+j--) = *(arreglo+i);
		}
		*(arreglo+i) = x;
		quickSort(arreglo, l, i - 1); // Llamada recursiva
		quickSort(arreglo, i + 1, r);
	}
}
int main(){
	
	int n, i;
	int DESDE = 1, HASTA = 100;
	cout << "Numeros aleatorios entre " << DESDE << " y " << HASTA << endl;
	cout << "Cuantos numeros aleatorios quiere generar? ";
	cin >> n;
	srand(time(NULL));
	int aleatorio;
	int* arreglo;
	arreglo = new int[n]; 
	for (int i = 0; i < n; i++){
		aleatorio = rand() % (HASTA - DESDE + 1) + DESDE;
		arreglo[i] = aleatorio;
	}
	cout << "Arreglo Desordenado\n";
	for (i = 0; i < n; i++){
		cout << arreglo[i] << " ";
	}
	t0 = clock();
	// Code to execute
	quickSort(arreglo, 0, n - 1);
	cout << "Arreglo Ordenado:" << endl;
	for (i = 0; i < n; i++)
		cout << arreglo[i] << " ";
	cout << endl;
	t1 = clock();

	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "\nExecution Time-> " << time << endl;
	return 0;
	


	/*
	cout << "SEMIORDENADO\n";
	int A[] = { 1,2,5,6,3,4,7,8,9,10 };
	int i, elementos;

	elementos = sizeof(A) / sizeof(A[0]);

	t0 = clock();
	// Code to execute

	quickSort(A,0,elementos-1);


	for (i = 0; i < elementos; i++)
		cout << " " << A[i];
	t1 = clock();

	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "\nExecution Time-> " << time << endl;

	*/

	/*
	cout << "CRECIENTE\n";
	int A[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i, elementos;

	elementos = sizeof(A) / sizeof(A[0]);

	t0 = clock();
	// Code to execute

	quickSort(A, 0, elementos - 1);


	for (i = 0; i < elementos; i++)
		cout << " " << A[i];
	t1 = clock();

	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "\nExecution Time-> " << time << endl;
	*/

}

