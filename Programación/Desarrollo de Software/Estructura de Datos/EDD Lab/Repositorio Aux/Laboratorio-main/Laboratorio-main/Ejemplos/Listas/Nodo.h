#include <iostream>
using namespace std;

class Nodo
{
private:
    /* data */
    int dato;
    Nodo *anterior;
    Nodo *siguiente;
public:
    Nodo(int dato);
    Nodo *getSiguiente();
    Nodo *getAnterior();
    void setSiguiente(Nodo *siguiente);
    void setAnterior(Nodo *anterior);
    int getDato();
    void setDato(int dato);
    ~Nodo();
};

Nodo::Nodo(int dato)
{
    this->dato = dato;
    this->anterior = nullptr;
    this->siguiente = nullptr;
}

Nodo* Nodo::getSiguiente(){
    return this->siguiente;
}

Nodo* Nodo::getAnterior(){
    return this->anterior;
}

void Nodo::setSiguiente(Nodo *siguiente){
    this->siguiente = siguiente;
}

void Nodo::setAnterior(Nodo *anterior){
    this->anterior = anterior;
}

int Nodo::getDato(){
    return this->dato;
}


Nodo::~Nodo()
{
}
