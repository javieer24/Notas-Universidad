#include <iostream>
#include <fstream>
using namespace std;
#include "Nodo.h"

class ArbolBB
{
private:
    /* data */
    Nodo* raiz;
    ofstream archivo;
    int nodoDato;
public:
    int recorrido = 0;
    ArbolBB(/* args */);
    bool estaVacio();
    void insertar(int dato);
    Nodo* insertarNodo(int dato, Nodo* nodoPtr);
    void buscar(int dato);
    int buscarNodo(int dato, Nodo* nodoPtr);

    void Recorrido();
    void Recorrido(Nodo* nodoPtr);
    
    void generarReporte();
    void imprimirNodo(Nodo* nodoPtr);
    ~ArbolBB();
};

ArbolBB::ArbolBB(/* args */)
{
    raiz = nullptr;
}

bool ArbolBB::estaVacio()
{
    return (raiz == nullptr);
}

void ArbolBB::insertar(int dato)
{
    raiz = insertarNodo(dato, raiz);
}

Nodo* ArbolBB::insertarNodo(int dato, Nodo* nodoPtr)
{
    if (nodoPtr == nullptr)
    {
        Nodo* nuevo = new Nodo(dato);
        nodoPtr = nuevo;
    }
    else if (dato < nodoPtr->getDato())
    {
        nodoPtr->setIzq(insertarNodo(dato, nodoPtr->getIzq()));
    }
    else if (dato > nodoPtr->getDato())
    {
        nodoPtr->setDer(insertarNodo(dato, nodoPtr->getDer()));
    }
    else{
        cout << "Nodo duplicado\n";
    }
    return nodoPtr;
}

void ArbolBB::buscar(int dato)
{
    cout << "Recorrido del nodo encontrado: " << buscarNodo(dato, raiz) << ", " << recorrido;
}

int ArbolBB::buscarNodo(int dato, Nodo* nodoPtr)
{
    if (nodoPtr == nullptr)
    {
        cout << "Nodo no encontrado\n";
        return 0;
    }
    else if(dato == nodoPtr->getDato()){
        recorrido++;
        return nodoPtr->getDato();
    }
    else if(dato < nodoPtr->getDato())
    {
        recorrido++;
        return buscarNodo(dato, nodoPtr->getIzq());
    }
    else if(dato > nodoPtr->getDato())
    {
        recorrido ++;
        return buscarNodo(dato, nodoPtr->getDer());
    }
    
}

void ArbolBB::Recorrido()
{
    Recorrido(raiz);
}

void ArbolBB::Recorrido(Nodo* nodoPtr)
{   
    if (nodoPtr != nullptr)
    {
        //PREORDEN
        cout << nodoPtr->getDato() << endl;
        Recorrido(nodoPtr->getIzq());
        Recorrido(nodoPtr->getDer());

        //INORDEN
        /*Recorrido(nodoPtr->getIzq());
        cout << nodoPtr->getDato() << endl;
        Recorrido(nodoPtr->getDer());*/

        //POSTORDEN
    }
    
}


void ArbolBB::generarReporte()
{
    if (ArbolBB::estaVacio()){}
    else
    {
        archivo.open("grafica_arbol.dot", ios::out);
        archivo << "digraph G { " << endl;

        imprimirNodo(raiz);

        archivo << " }";
        archivo.close();
        system("dot -Tpng grafica_arbol.dot -o grafica_arbol.png");
        system("start grafica_arbol.png");
    }
    
}

void ArbolBB::imprimirNodo(Nodo* nodoPtr)
{
    if (nodoPtr == nullptr)
    {
        return;
    }
    if (nodoPtr->getIzq() != nullptr)
    {
        nodoDato = nodoPtr->getDato();
        archivo << nodoDato; 
        archivo << "->";
        nodoDato = nodoPtr->getIzq()->getDato();
        archivo << nodoDato;
        archivo << ";";
    }
    imprimirNodo(nodoPtr->getIzq());
    
    if (nodoPtr->getDer()!= nullptr)
    {
        nodoDato = nodoPtr->getDato();
        archivo << nodoDato; 
        archivo << "->";
        nodoDato = nodoPtr->getDer()->getDato();
        archivo << nodoDato;
        archivo << ";";
    }
    imprimirNodo(nodoPtr->getDer());
    
}

ArbolBB::~ArbolBB()
{
}
