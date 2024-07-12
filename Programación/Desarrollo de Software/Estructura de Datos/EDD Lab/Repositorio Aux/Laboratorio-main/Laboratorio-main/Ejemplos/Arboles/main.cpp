#include <iostream>
using namespace std;
#include "ArbolBB.h"

int main()
{
    ArbolBB miArbolBB;
    miArbolBB.insertar(30);
    miArbolBB.insertar(33);
    miArbolBB.insertar(40);
    miArbolBB.insertar(34);
    miArbolBB.insertar(20);
    miArbolBB.insertar(32);
    miArbolBB.insertar(15);
    miArbolBB.insertar(25);
    //miArbolBB.buscar(25);
    cout << endl;
    miArbolBB.Recorrido(); //30, 20, 15, 25, 33, 32, 40, 34
    miArbolBB.generarReporte();

    return 0;
}