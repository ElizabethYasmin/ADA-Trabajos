#include <iostream>
using namespace std;

double fibonaci(double x)
{
    if (x <= 1)
        return 1;
   
    return  fibonaci(x-1) + fibonaci(x-2);
}

void imprimir(double limite){
   for (double i = 1; i < limite; i++)
        cout<< "..["<<i << "]..->"<< fibonaci(i)<<"\n"; 
}

int main()
{
    double x;
    cout<< "Agregar limite->";
    cin>> x;
    imprimir(x+1);
    return  0;
}
