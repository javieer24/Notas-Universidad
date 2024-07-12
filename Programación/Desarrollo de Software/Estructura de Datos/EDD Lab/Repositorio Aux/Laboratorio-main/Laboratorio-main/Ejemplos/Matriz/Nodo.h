#include <iostream>
#include <string.h>
using namespace std;

class Nodo
{
private:
    /* data */
    string dato;
    int fila, columna;
    Nodo* anterior;
    Nodo* siguiente;
    Nodo* arriba;
    Nodo* abajo;
    
public:
    Nodo(/* args */);
    Nodo(string dato, int fila, int columna);

    string getDato();
    void setDato(string dato);
    int getFila();
    void setFila(int fila);
    int getColumna();
    void setColumna(int columna);

    Nodo* getAnterior();
    void setAnterior(Nodo* anterior);
    Nodo* getSiguiente();
    void setSiguiente(Nodo* siguiente);
    Nodo* getArriba();
    void setArriba(Nodo* arriba);
    Nodo* getAbajo();
    void setAbajo(Nodo* abajo);
    ~Nodo();
};

Nodo::Nodo(/* args */)
{

}

Nodo::Nodo(string dato, int fila, int columna)
{
    this->dato = dato;
    this->fila = fila;
    this->columna = columna;
    anterior = siguiente = arriba = abajo = nullptr;
}

Nodo* Nodo::getAnterior()
{
    return anterior;
}

void Nodo::setAnterior(Nodo* anterior)
{
    this->anterior = anterior;
}


Nodo* Nodo::getSiguiente()
{
    return siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente)
{
    this->siguiente = siguiente;
}



Nodo* Nodo::getArriba()
{
    return arriba;
}

void Nodo::setArriba(Nodo* arriba)
{
    this->arriba = arriba;
}


Nodo* Nodo::getAbajo()
{
    return abajo;
}

void Nodo::setAbajo(Nodo* abajo)
{
    this->abajo = abajo;
}

int Nodo::getFila(){
    return fila;
}

void Nodo::setFila(int fila)
{
    this->fila = fila;
}

int Nodo::getColumna()
{
    return columna;
}

void Nodo::setColumna(int columna)
{
    this->columna = columna;
}

string Nodo::getDato(){
    return dato;
}

void Nodo::setDato(string dato)
{
    this->dato = dato;
}

Nodo::~Nodo()
{
}

