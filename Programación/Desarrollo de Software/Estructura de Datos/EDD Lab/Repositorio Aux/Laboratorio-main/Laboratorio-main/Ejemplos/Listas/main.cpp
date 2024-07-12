#include <iostream>
using namespace std;
//#include "ListaSimple.h"
//#include "ListaDoble.h"
#include "ListaCircular.h"

int main()
{
    /*ListaSimple miLista;
    miLista.insertarInicio(10);
    miLista.insertarInicio(5);
    miLista.insertarFinal(15);
    miLista.visualizarLista();
    cout << endl;
    miLista.eliminarFinal();
    miLista.eliminarInicio();
    miLista.eliminarFinal();
    miLista.visualizarLista();*/

    /*ListaDoble miLista;
    miLista.insertarInicio(100);
    miLista.insertarInicio(50);
    miLista.insertarFinal(150);
    miLista.visualizarLista();
    cout << endl;
    miLista.eliminarFinal();
    miLista.eliminarInicio();
    miLista.eliminarFinal();
    miLista.visualizarLista();*/

    ListaCircular miLista;
    miLista.insertarFinal(100);
    miLista.insertarFinal(50);
    miLista.insertarFinal(150);
    miLista.insertarInicio(300);
    miLista.visualizarLista();
    miLista.generarReporte();
    cout << endl;
    /*miLista.eliminarFinal();
    miLista.eliminarInicio();
    miLista.visualizarLista();*/

    return 0;
}