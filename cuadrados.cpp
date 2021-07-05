#include <iostream>
using namespace std;

int cuadrados(int n){
    int resp;
    resp=(n*(n+1)*((2*n)+1))/6;
    return resp;
}
int main(){
    int x;
    cout<<"tamanio->";cin>>x;
    cout<<cuadrados(x);
    return 0;

}