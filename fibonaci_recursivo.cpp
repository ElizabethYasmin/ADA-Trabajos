#include <iostream>
using namespace std;

long long int fibonacci(int x)
{
    if (x <= 1)
        return 1;
   
    return  fibonacci(x-1) + fibonacci(x-2);
}

void imprimir(int limite){
   for (int i = 1; i < limite; i++)
        std::cout<< "..["<<i << "]..->"<< fibonacci(i)<<"\n"; 
}

int main()
{
    int x;
    cout<< "Agregar limite->";
    cin>> x;
    imprimir(x+1);
    return  0;
}
