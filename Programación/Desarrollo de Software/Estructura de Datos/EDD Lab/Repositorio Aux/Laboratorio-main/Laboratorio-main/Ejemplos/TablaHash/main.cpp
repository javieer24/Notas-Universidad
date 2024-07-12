#include <iostream>
using namespace std;
#include "TablaHash.h"

int main()
{
    TablaHash miTabla;
    miTabla.Insertar(99);
    miTabla.Insertar(35);
    miTabla.Insertar(15);
    miTabla.Insertar(90);
    miTabla.Insertar(88);
    miTabla.Insertar(64);
    miTabla.Insertar(77);
    miTabla.Insertar(41);
    miTabla.Insertar(19);
    miTabla.Insertar(98);
    miTabla.Insertar(48);
    miTabla.Insertar(71);
    miTabla.Insertar(22);
    miTabla.Insertar(10);
    miTabla.Insertar(57);
    miTabla.imprimirTabla();
    return 0;
}