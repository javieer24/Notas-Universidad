#include <iostream>
using namespace std;
#include "Nodo.h"

class ListaSimple
{
private:
    /* NECESITAMOS UNA REFERENCIA DEL PRIMER Y ÚLTIMO NODO DE LA LISTA */
    Nodo *primero, *ultimo;
public:
    ListaSimple(/* args */);
    bool estaVacia();
    void insertarInicio(int dato);
    void insertarFinal(int dato);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    ~ListaSimple();
};

ListaSimple::ListaSimple(/* args */)
{
    primero = ultimo = nullptr;
}

bool ListaSimple::estaVacia()
{
    return (primero == nullptr) && (ultimo == nullptr);
}

void ListaSimple::insertarInicio(int dato)
{
    Nodo *nuevo = new Nodo(dato); //Se crea el nuevo nodo
    if (ListaSimple::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero); //Se enlaza el nuevo nodo al primero
        primero = nuevo; //Se verifica que el nodo creado sea el primero
    }
    
}

void ListaSimple::insertarFinal(int dato)
{
    Nodo *nuevo = new Nodo(dato);
    if (ListaSimple::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        ultimo->setSiguiente(nuevo); //Se enlaza el último nodo al nuevo
        ultimo = nuevo; //Se verfica que el nodo creado sea el último
    }
}

void ListaSimple::eliminarInicio()
{
    if (ListaSimple::estaVacia())
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
            delete primero;
            primero = segundo;
        }   
    } 
}

void ListaSimple::eliminarFinal()
{
    if (ListaSimple::estaVacia())
    {
        cout << "La lista está vacía" << endl;
    }
    else{
        Nodo* temporal = primero;
        if (primero == ultimo)
        {
            /* code */
            delete primero;
            primero = ultimo = nullptr;
        }
        else{
            while (temporal != nullptr)
            {
                /* code */
                if (temporal->getSiguiente() == ultimo) //Si el siguiente de temporal es el último, entonces temporal es el antepenultimo
                {
                    /* code */
                    delete ultimo;
                    temporal->setSiguiente(nullptr);
                    ultimo = temporal;
                }
                temporal = temporal->getSiguiente(); //Recorriendo la lista
            }
            
        }
        
    }
    
}

void ListaSimple::visualizarLista()
{
    if (ListaSimple::estaVacia())
    {
        /* code */
        cout << "La lista está vacía" << endl;
    }
    else
    {
        int nodoDato;
        Nodo *actual = primero;
        while (actual != nullptr)
        {
            /* code */
            nodoDato = actual->getDato();
            //cout << nodoDato << endl;
            cout << nodoDato << (actual->getSiguiente() != nullptr ? " -> ": "\n");
            actual = actual->getSiguiente();
        }
        
    }
    
}


ListaSimple::~ListaSimple()
{
}
