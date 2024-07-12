#include <iostream>
#include <fstream>
using namespace std;
#include "Vertice.h"

class Grafo
{
private:
    /* data */
    int numVertices; //número de vértices actuales en el grafo
    int maxVertices; //número máximo de vértices en el grafo
    Vertice* vertices; //arreglo de vértices
    int** matrizAdy; //matriz de adyacencia

    ofstream archivo;
    string arco;
public:
    Grafo(/* args */);

    Grafo(int max);
    int getNumVertices(); //Obtiene el número de vértices
    void setNumVertices(int n); //Establecer el número de vértices

    void nuevoVertice(string nombre);
    int existeVertice(string nombre); //Comprueba si el nombre recibido se encuentra en la lista de vértices
    void nuevoArco(string nom1, string nom2); //Agrega 1 a la matriz de adyacencia si los 2 vértices existen
    void imprimirMatriz();
    void generarReporte();
    ~Grafo();
};

Grafo::Grafo(/* args */)
{
}

typedef int* int_m; //para la dimension de la matriz
Grafo::Grafo(int max)
{
    numVertices = 0; //número de vértices en el grafo, cuando se crea el grafo este aún no tiene nodos
    maxVertices = max; //Número máximo de vértices en el grafo
    vertices = new Vertice[max]; //arreglo de vértices
    matrizAdy = new int_m[max]; //arreglo de punteros
    for (int i = 0; i < max; i++)
    {
        matrizAdy[i] = new int[max]; //Completando la matriz de adyacencia
    }

    for (int i = 0; i < maxVertices; i++)
    {
        for (int j = 0; j < maxVertices; j++)
        {
            matrizAdy[i][j] = 0;
        } 
    }
    
    /**/
}

int Grafo::getNumVertices()
{
    return this->numVertices;
}

void Grafo::setNumVertices(int n)
{
    this->numVertices = n;
}

void Grafo::nuevoVertice(string nombre)
{
    bool existe = (existeVertice(nombre) >= 0);
    if (!existe) //Si no existe
    {
        Vertice nuevo = Vertice(nombre,numVertices);
        vertices[numVertices] = nuevo; //Se agrega el nuevo vértice a la lista
        numVertices++;
    }
}

int Grafo::existeVertice(string nombre)
{   //Busca el vértice en el arreglo vértices, retorna -1 si no lo encuentra
    int i = 0;
    bool encontrado = false;
    while (i < numVertices && !encontrado)
    {   //El ciclo se repite mientras no se haya iterado una cantidad mayor o igual al número de toal de vertices existentes
        //Y mientras no se haya encontrado un vértice con el mismo nombre al que se desea agregar
        encontrado = vertices[i].esIgual(nombre); //Falso mientras no se haya encontrado un vértice con el mismo nombre
        if (!encontrado)
        {
            i++;
        }
    }
    //Si 'i' es menor al número total de vértices, quiere decir que lo encontró en alguna de todas las iteraciones
    return (i < numVertices) ? i : -1;
}

void Grafo::nuevoArco(string nom1, string nom2)
{   //Recibe el nombre de los 2 vértices que forman el arco y los busca en el arreglo de vértices
    //Si existen agrego 1 a la matriz de adyacencia
    int vertice1, vertice2;
    vertice1 = existeVertice(nom1);
    vertice2 = existeVertice(nom2);
    if (vertice1 >= 0 && vertice2 >= 0)
    {
        matrizAdy[vertice1][vertice2] = 1;  
    }
    else
    {
        cout << "Error, uno de los vértices no existe\n";
    }
}

void Grafo::imprimirMatriz()
{
    for (int i = 0; i < maxVertices; i++)
    {
        for (int j = 0; j < maxVertices; j++)
        {
            cout << " " << matrizAdy[i][j] << " ";
        }  
        cout << endl;
    }
}

void Grafo::generarReporte()
{
    if (getNumVertices() == 0) {} //Grafo vacío
    else{
        archivo.open("grafo.dot",ios::out);
        archivo << "digraph G { " << endl;

        for (int i = 0; i < maxVertices; i++)
        {
            for (int j = 0; j < maxVertices; j++)
            {
                if (matrizAdy[i][j] == 1)
                {
                    /* code */
                    arco += vertices[i].getNombre() + " -> " + vertices[j].getNombre() + ";\n";
                    archivo << arco;
                    arco.clear();
                }
            }  
        }

        archivo << "}";
        archivo.close();
        system("dot -Tpng grafo.dot -o grafo.png");
        system("start grafo.png");
    }
}


Grafo::~Grafo()
{
}
