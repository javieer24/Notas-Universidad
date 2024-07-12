#include <iostream>
using namespace std;

class Estatico
{
private:
    int datos;
public:
    static int cuenta;
    int valor;
    Estatico();
    Estatico(int n);

    ~Estatico();
};

int Estatico::cuenta = 0;

Estatico::Estatico(/* args */)
{
    datos = 0;
    valor = 10;
    cuenta++;
}

Estatico::Estatico(int x){
    datos = x;
    valor = x;
    cuenta++;
}

Estatico::~Estatico()
{
    cuenta--;
}
