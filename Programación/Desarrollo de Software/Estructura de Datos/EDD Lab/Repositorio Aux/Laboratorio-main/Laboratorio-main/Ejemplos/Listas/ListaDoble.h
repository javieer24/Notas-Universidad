#include <iostream>
using namespace std;
#include "Nodo.h"

class ListaDoble
{
private:
    /* data */
    Nodo *primero;
    Nodo *ultimo;
public:
    ListaDoble(/* args */);
    bool estaVacia();
    void insertarInicio(int dato);
    void insertarFinal(int dato);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    ~ListaDoble();
};

ListaDoble::ListaDoble(/* args */)
{
    primero = nullptr;
    ultimo = nullptr;
}

bool ListaDoble::estaVacia()
{
    return (primero==nullptr) && (ultimo == nullptr);
}

void ListaDoble::insertarInicio(int dato)
{
    Nodo *nuevo = new Nodo(dato); //Se crea el nuevo nodo
    if (ListaDoble::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        primero->setAnterior(nuevo); //Se enlaza el primer nodo al nuevo
        nuevo->setSiguiente(primero); //Se enlaza el nuevo nodo al primero
        primero = nuevo; //Se verifica que el nodo creado sea el primero
    } 
}

void ListaDoble::insertarFinal(int dato)
{
    Nodo *nuevo = new Nodo(dato);
    if (ListaDoble::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        ultimo->setSiguiente(nuevo); //Se enlaza el último nodo al nuevo
        nuevo->setAnterior(ultimo); //Se enlaza el nuevo nodo al último
        ultimo = nuevo; //Se verfica que el nodo creado sea el último
    }
}

void ListaDoble::eliminarInicio()
{
    if (ListaDoble::estaVacia())
    {
        /* code */
        cout << "La lista está vacía" << endl;
    }
    else
    {
        if (primero == ultimo)
        {
            /* code */
            delete primero;
            primero = ultimo = nullptr;
        }
        else
        {
            Nodo *segundo = primero->getSiguiente();
            segundo->setAnterior(nullptr);
            delete primero;
            primero = segundo;
        }   
    } 
}

void ListaDoble::eliminarFinal()
{
    if (ListaDoble::estaVacia())
    {
        cout << "La lista está vacía" << endl;
    }
    else{
        if (primero == ultimo)
        {
            /* code */
            delete primero;
            primero = ultimo = nullptr;
        }
        else{
            Nodo* antepenultimo = ultimo->getAnterior(); //Guardo la refencia del antepenultimo nodo
            delete ultimo;
            antepenultimo->setSiguiente(nullptr);
            ultimo = antepenultimo;
        }
    }
}

void ListaDoble::visualizarLista()
{
    if (ListaDoble::estaVacia())
    {
        /* code */
        cout << "La lista está vacía\n" << endl;
    }
    else
    {
        int nodoDato;
        /*Nodo *actual = primero;
        while (actual != nullptr)
        {
            nodoDato = actual->getDato();
            cout << nodoDato << endl;
            actual = actual->getSiguiente();
        }*/
        
       Nodo *actual = ultimo;
        while (actual != nullptr)
        {
            nodoDato = actual->getDato();
            cout << nodoDato << endl;
            actual = actual->getAnterior();
        }
        
    }
    
}

ListaDoble::~ListaDoble()
{
}
