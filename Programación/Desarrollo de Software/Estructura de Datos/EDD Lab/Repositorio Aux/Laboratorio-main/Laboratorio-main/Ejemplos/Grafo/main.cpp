#include <iostream>
using namespace std;
#include "Grafo.h"

int main()
{
    Grafo miGrafo(10);
    miGrafo.nuevoVertice("peten");
    miGrafo.nuevoVertice("izabal");
    miGrafo.nuevoVertice("zacapa");
    miGrafo.nuevoVertice("jalapa");
    miGrafo.nuevoVertice("jutiapa");
    miGrafo.nuevoVertice("chiqui");
    miGrafo.nuevoVertice("guate");
    miGrafo.nuevoVertice("quiche");
    miGrafo.nuevoVertice("baja");
    miGrafo.nuevoVertice("alta");

    miGrafo.nuevoArco("peten", "izabal");
    miGrafo.nuevoArco("izabal", "peten");
    miGrafo.nuevoArco("izabal", "zacapa");
    miGrafo.nuevoArco("zacapa", "izabal");
    miGrafo.nuevoArco("zacapa", "chiqui");
    miGrafo.nuevoArco("zacapa", "jalapa");
    miGrafo.nuevoArco("jalapa", "guate");
    miGrafo.nuevoArco("jalapa", "jutiapa");
    miGrafo.nuevoArco("guate", "quiche");
    miGrafo.nuevoArco("guate", "jalapa");
    miGrafo.nuevoArco("quiche", "alta");
    miGrafo.nuevoArco("quiche", "baja");
    miGrafo.nuevoArco("quiche", "peten");
    miGrafo.nuevoArco("alta", "peten");
    miGrafo.nuevoArco("alta", "izabal");
    miGrafo.nuevoArco("baja", "guate");

    miGrafo.imprimirMatriz();
    miGrafo.generarReporte();
    return 0;
}
