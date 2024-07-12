#include <iostream>
using namespace std;

class Nodo
{
private:
    /* data */
    int dato;
    Nodo* izq; //Hijo izquierdo
    Nodo* der; //Hijo derecho
public:
    Nodo(int dato);
    void setDato(int dato);
    int getDato();
    void setIzq(Nodo* izq);
    Nodo* getIzq();
    void setDer(Nodo* der);
    Nodo* getDer();
    ~Nodo();
};

Nodo::Nodo(int dato)
{
    this->dato = dato;
    this->izq = nullptr;
    this->der = nullptr;
}

void Nodo::setDato(int dato)
{
    this->dato = dato;
}

void Nodo::setIzq(Nodo* izq)
{
    this->izq = izq;
}

void Nodo::setDer(Nodo* der)
{
    this->der = der;
}

int Nodo::getDato()
{
    return this->dato;
}

Nodo* Nodo::getIzq()
{
    return this->izq;
}

Nodo* Nodo::getDer()
{
    return this->der;
}

Nodo::~Nodo()
{
}
