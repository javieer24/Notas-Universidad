#include <fstream> //cabecera para manejar archivos (leer y escribir)
#include <cstdlib> //cabecera para manejar el system (cmd)
#include <iostream>
using namespace std;
#include "Nodo.h"

class ListaCircular
{
private:
    /* data */
    Nodo* primero;
    Nodo* ultimo;
public:
    ListaCircular(/* args */);
    bool estaVacia();
    void insertarInicio(int dato);
    void insertarFinal(int dato);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    void generarReporte();
    ~ListaCircular();
};

ListaCircular::ListaCircular(/* args */)
{
    primero = nullptr;
    ultimo = nullptr;
}

bool ListaCircular::estaVacia()
{
    return (primero == nullptr) && (ultimo == nullptr);
}

void ListaCircular::insertarInicio(int dato)
{
    Nodo *nuevo = new Nodo(dato); //Se crea el nuevo nodo
    if (ListaCircular::estaVacia())
    {
        nuevo->setSiguiente(nuevo); //El primer nodo se apunta a si mismo
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero); //Se enlaza el nuevo nodo al primero
        ultimo->setSiguiente(nuevo); //Se enlaza el ultimo nodo al nuevo
        primero = nuevo; //Se verifica que el nodo creado sea el primero
    }
    
}

void ListaCircular::insertarFinal(int dato)
{
    Nodo *nuevo = new Nodo(dato);
    if (ListaCircular::estaVacia())
    {
        nuevo->setSiguiente(nuevo);
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero);
        ultimo->setSiguiente(nuevo); //Se enlaza el último nodo al nuevo
        ultimo = nuevo; //Se verfica que el nodo creado sea el último
    }
}

void ListaCircular::eliminarInicio()
{
    if (ListaCircular::estaVacia())
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
            ultimo->setSiguiente(segundo);
            delete primero;
            primero = segundo;
        }   
    } 
}

void ListaCircular::eliminarFinal()
{
    if (ListaCircular::estaVacia())
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
            do
            {
                if (temporal->getSiguiente() == ultimo) //Se encontro el antepenultimo nodo
                {
                    delete ultimo;
                    temporal->setSiguiente(primero); //Se enlaza el antepenultimo nodo al primero
                    ultimo = temporal; //se verifica que temporal sea el último
                    break;
                }  
                temporal = temporal->getSiguiente();
            } while (temporal != primero);
            
        }
        
    }    
}

void ListaCircular::visualizarLista()
{
    if (ListaCircular::estaVacia())
    {
        /* code */
        cout << "La lista está vacía\n" << endl;
    }
    else
    {
        int nodoDato;
        Nodo *actual = primero;
        do
        {
            nodoDato = actual->getDato();
            cout << nodoDato << endl;
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
}

void ListaCircular::generarReporte(){
    if (ListaCircular::estaVacia()){}
    else
    {
        ofstream archivo; //
        archivo.open("grafica_LC.dot", ios::out);
        archivo << "digraph G { rankdir = LR; " << endl;

        int nodoDato;
        Nodo *actual = primero;
        do
        {
            nodoDato = actual->getDato();
            archivo << nodoDato;
            archivo << " -> ";
            actual = actual->getSiguiente();
            if (actual == primero)
            {
                archivo << actual->getDato();
            }
            
        } while (actual != primero);

        archivo << "; }";
        archivo.close();
        system("dot -Tpng grafica_LC.dot -o grafica_LC.png");
        system("start grafica_LC.png");
    }
    

}

ListaCircular::~ListaCircular()
{
}
