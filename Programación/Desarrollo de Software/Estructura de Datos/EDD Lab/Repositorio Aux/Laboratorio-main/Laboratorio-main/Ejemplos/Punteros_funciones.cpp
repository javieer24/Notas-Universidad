//PASO POR VALOR Y POR REFERENCIA
#include <iostream>
using namespace std;


/*PASO POR VALOR*/
/*void funcion(int y){
    y = 100;
}

int main(){
    int x = 0;
    cout << x << endl;
    funcion(x); //Pasamos el valor de x, no pasamos la dirección en memoria
    cout << x << endl;

    return 0;
}*/


/*PASO POR REFENCIA*/
void funcion(int *y){
    *y = 100;
}

int main(){
    int x = 0;
    cout << x << endl;
    funcion(&x); //Pasamos la dirección en memoria de x
    cout << x << endl;

    return 0;
}