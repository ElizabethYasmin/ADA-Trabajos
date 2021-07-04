//Elizabeth Yasmin Huanca Parqui

#include <iostream>
#include <ctime>
#include <stdlib.h>
unsigned t0, t1;
using namespace std;

void InsertSort(int* arreglo, int n){
    for (int j = 1; j < n; j++){
        int key = *(arreglo + j);
        int i = j - 1;

		//Mover elementos de arr[0..i - 1], que son mayor que la clave, a una posición por delante de su posición actual
        while (i >= 0 && *(arreglo + i) > key){
            *(arreglo + i + 1) = *(arreglo + i);
            i--;
        }
		*(arreglo + i + 1) = key;
    }
}

int main(){
	
	/*
	//Creacion de los numeros aleatorios
	int n;

	int DESDE = 4, HASTA = 10;
	cout << "Aleatorios entre " << DESDE << " - " << HASTA << endl;
	cout << "Numeros de aleatorios a generar -> ";
	cin >> n;

	srand(time(NULL));
	//Creacion de un arreglo dinamico para colocar los numeros aleatorios
	int aleatorio;
	int* arreglo;
	arreglo = new int[n];
	//Llenando el array de aleatorios
	for (int i = 0; i < n; i++)
	{
		aleatorio = rand() % (HASTA - DESDE + 1) + DESDE;
		arreglo[i] = aleatorio;
	}
	cout << "Arreglo Desordenado\n";
	for (int i = 0; i < n; i++)
	{
		cout << *(arreglo + i) << " ";
	}
	//Llamada de la funcion
	InsertSort(arreglo, n);
	
	cout << "Arreglo ordenado	\n";
	for (int i = 0; i < n; i++) {
		cout << " " << *(arreglo + i);
	}
	delete arreglo;
	*/

	
	

	cout << "SEMIORDENADO\n";
	int A[] = { 1,2,5,6,3,4,7,8,9,10 }; 
	int i, elementos;

	elementos = sizeof(A) / sizeof(A[0]);

	t0 = clock();
	// Code to execute

	InsertSort(A, elementos);

	
	for (i = 0; i < elementos; i++)
		cout << " " << A[i];
	t1 = clock();

	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "\nExecution Time-> " << time << endl;
}