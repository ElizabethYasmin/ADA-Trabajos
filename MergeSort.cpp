///Elizabeth Yasmin Huanca Parqui

#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <ctime>
unsigned t0, t1;
using namespace std;

void Merge(int* arreglo, int* I, int elementosIzquierda, int* D, int elementosDerecha) {
	int i = 0;
	int j = 0; 
	int k = 0;
	//Fusionando las matrices I y D en arreglo
	while (i < elementosIzquierda && j < elementosDerecha) {
		if (*(I+i) < *(D+j)) 
			*(arreglo+k++) = *(I+i++);
		else 
			*(arreglo+k++) = *(D+j++);
	}
	while (i < elementosIzquierda) *(arreglo + k++) = *(I + i++);
	while (j < elementosDerecha) *(arreglo + k++) = *(D + j++);
}

void MergeSort(int* arreglo, int n) {
	int media, i, * I, * D;
	if (n < 2) return; // para menos de dos elementos la funcion termina

	media = n / 2; //indice medio

	//Creacion de subarreglos izquierdos y derechos
	I = new int[media];//submatriz izquierda del arreglo principal
	D = new int[n - media];//submatriz derecha del arreglo principal

	for (i = 0; i < media; i++) 
		*(I+i) = *(arreglo+i); // subarreglo izquierdo
	for (i = media; i < n; i++) 
		*(D+i - media) = *(arreglo + i); //subarreglo derecho
	//ordenando recursivamente los subarreglos izquierdo y derechos
	MergeSort(I, media);
	MergeSort(D, n - media); 
	Merge(arreglo, I, media, D, n - media); //fusion de I y D
	//Liberacion de memoria
	delete[] D;
	delete[] I;
}


int main() {
	
		int n;

		int DESDE = 4, HASTA = 10;
		cout << "Numeros aleatorios entre " << DESDE << " y " << HASTA << endl;
		cout << "Cuantos numeros aleatorios quiere generar? ";
		cin >> n;

		srand(time(NULL));

		int aleatorio;

		int* arreglo;
		arreglo = new int[n];

		for (int i = 0; i < n; i++)
		{
			aleatorio = rand() % (HASTA - DESDE + 1) + DESDE;
			arreglo[i] = aleatorio;
		}
		cout << "Arreglo Desordenado\n";
		 for (int i = 0; i < n; i++)
		 {
		 cout << arreglo[i] << " ";
			}

		 t0 = clock();
		 // Code to execute
		 MergeSort(arreglo, n);


		 cout << "Arreglo ordenado	\n";
		 for (int i = 0; i < n; i++) {
			 cout << " " << arreglo[i];
		 }
		 t1 = clock();

		 double time = (double(t1 - t0) / CLOCKS_PER_SEC);
		 cout << "\nExecution Time-> " << time << endl;
		 delete arreglo;

		 return 0;




	/*
	cout << "SEMIORDENADO\n";
	int A[] = { 1,2,5,6,3,4,7,8,9,10 };
	int i, elementos;

	elementos = sizeof(A) / sizeof(A[0]);

	t0 = clock();
	// Code to execute

	MergeSort(A, elementos);


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

	MergeSort(A, elementos);


	for (i = 0; i < elementos; i++)
		cout << " " << A[i];
	t1 = clock();
	
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "\nExecution Time-> " << time << endl;
	*/
}