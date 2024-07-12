#include <iostream>
#include <string.h>
using namespace std;
#include "Nodo.h"

class Matriz
{
private:
    /* data */
public:
    Nodo* root;
    Matriz(/* args */);
    Nodo* buscarFila(int fila, Nodo* inicio);
    Nodo* buscarColumna(int columna, Nodo* inicio);
    Nodo* crearFila(int fila);
    Nodo* crearColumna(int columna);
    void insertar(string dato, int fila, int columna);
    ~Matriz();
};

Matriz::Matriz(/* args */)
{
    root = new Nodo("Root",-1, -1); //-1 y -1 para encabezado root
}

Nodo* Matriz::buscarFila(int fila, Nodo* inicio)
{
    Nodo* aux = inicio; //inicio puede ser el root
    while (aux != nullptr)
    {
        if (aux->getFila() == fila)
        {
            return aux; //Si se encuentra la cabecera fila, la retorno
        }
        aux = aux->getAbajo();
    }
    return nullptr; //Si no la encuentra quiere decir que no existe la cabecera fila
}

Nodo* Matriz::buscarColumna(int columna, Nodo* inicio)
{
    Nodo* aux = inicio; //inicio puede ser el root
    while (aux != nullptr)
    {
        if (aux->getColumna() == columna)
        {
            return aux; //Si se encuentra la cabecera columna, la retorno
        }
        aux = aux->getSiguiente();
    }
    return nullptr; //Si no la encuentra quiere decir que no existe la cabecera columna
}

Nodo* Matriz::crearFila(int fila)
{
    Nodo* f = new Nodo("Fila", fila, -1);
    Nodo* aux = root;
    while (aux->getAbajo() != nullptr)
    {
        aux = aux->getAbajo();
    }
    aux->setAbajo(f);
    f->setArriba(aux);
    return f;
}

Nodo* Matriz::crearColumna(int columna)
{
    Nodo* c = new Nodo("Columna", -1, columna);
    Nodo* aux = root;
    while (aux->getSiguiente() != nullptr)
    {
        aux = aux->getSiguiente();
    }
    aux->setSiguiente(c);
    c->setAnterior(aux);
    return c;
}

void Matriz::insertar(string dato, int fila, int columna)
{
    Nodo* nodoDato = new Nodo(dato, fila, columna);
    Nodo* nodoFila; //Para saber en que fila insertar
    Nodo* nodoColumna; //Para saber en que columna insertar

    nodoFila = buscarFila(fila, root);
    nodoColumna = buscarColumna(columna, root);

    //REVISAMOS SI EXISTEN LOS ENCABEZADOS
    /*if (nodoFila == nullptr)
    {
        nodoFila = crearFila(fila);
    }
    if (nodoColumna == nullptr)
    {
        nodoColumna = crearColumna(columna);
    }*/

   if (nodoFila == nullptr && nodoColumna == nullptr) //Caso 1
   {
        nodoFila = crearFila(fila);
        nodoColumna = crearColumna(columna);
   }
   else if (nodoFila != nullptr && nodoColumna == nullptr) //Caso 2
   {
        nodoColumna = crearColumna(columna);
   }
   else if (nodoFila == nullptr && nodoColumna != nullptr)
   {
        nodoFila = crearFila(fila);
   }
   
    
    //INSERTAR NODODATO EN LAS CABECERAS
    /*if (nodoFila->getSiguiente() == nullptr)
    {
        nodoFila->setSiguiente(nodoDato);
        nodoDato->setAnterior(nodoFila);
    }

    if (nodoColumna->getAbajo() == nullptr)
    {
        nodoColumna->setAbajo(nodoDato);
        nodoDato->setArriba(nodoColumna);
    }*/

   //Insertando nodoDato en la cabecera fila
   Nodo* auxFila = nodoFila;
   while (auxFila != nullptr)
   {
        if (auxFila->getSiguiente() == nullptr) //Encontre el último nodo (puede ser la misma cabecera)
        {
            //Hacemos los enlaces correspondientes
            auxFila->setSiguiente(nodoDato);
            nodoDato->setAnterior(auxFila);
            break;
        }
        auxFila = auxFila->getSiguiente();
   }

   //Insertando nodoDato en la cabecera columna
   Nodo* auxColumna = nodoColumna;
   while (auxColumna != nullptr)
   {
        if (auxColumna->getAbajo() == nullptr) //Encontre el último nodo (puede ser la misma cabecera)
        {
            //Hacemos los enlaces correspondientes
            auxColumna->setAbajo(nodoDato);
            nodoDato->setArriba(auxColumna);
            break;
        }
        auxColumna = auxColumna->getAbajo();  
   }
   
   
    
    

}

Matriz::~Matriz()
{
}
