#include <iostream>
using namespace std;

long long int fibonaci(int x)
{
    if (x <= 1)
        return 1;
   
    return  fibonaci(x-1) + fibonaci(x-2);
}

void imprimir(int limite){
   for (int i = 1; i < limite; i++)
        cout<< "..["<<i << "]..->"<< fibonaci(i)<<"\n"; 
}

int main()
{
    int x;
    cout<< "Agregar limite->";
    cin>> x;
    imprimir(x+1);
    return  0;
}
