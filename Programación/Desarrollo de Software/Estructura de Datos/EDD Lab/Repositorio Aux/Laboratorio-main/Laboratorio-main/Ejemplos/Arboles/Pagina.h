#include <iostream>
using namespace std;

class Pagina
{
private:
    /* data */
    int* claves; //Puntero de arreglos de claves
    Pagina* ramas; //Puntero de arreglos de ramas o hijos
    int cuenta; //Número de claves que posee la página
    int m; //Maximo número de claves que puede almacenar una página (orden o grado)
public:
    Pagina(/* args */);
    bool nodoLleno(); //Para saber si me toca dividir la página
    bool nodoSemiVacio(); //Para saber si me toca unir con otra página
    ~Pagina();
};

Pagina::Pagina(/* args */)
{
}

Pagina::~Pagina()
{
}
