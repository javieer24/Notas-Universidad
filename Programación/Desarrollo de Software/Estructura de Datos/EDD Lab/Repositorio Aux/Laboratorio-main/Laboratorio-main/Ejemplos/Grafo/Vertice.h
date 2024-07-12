#include <iostream>
using namespace std;

//REPRESENTA UN NODO EN EL GRAFO
class Vertice
{
private:
    /* data */
    string nombre; //nombre de vértice
    int numVertice; //número de vértice
public:
    Vertice(/* args */);
    string getNombre(){
        return this->nombre;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    bool esIgual(string nombre);
    Vertice(string nombre, int n);

    ~Vertice();
};

Vertice::Vertice(/* args */)
{
}

Vertice::Vertice(string nombre, int n)
{
    this->nombre = nombre;
    this->numVertice = n;
}

//Devuelve TRUE si dos vertices tienen el mismo nombre
bool Vertice::esIgual(string nombre)
{
    //Comparamos el nombre del vértice "actual" con el nombre del vértice que se quiere agregar
    return (this->nombre == nombre);
}


Vertice::~Vertice()
{
}
