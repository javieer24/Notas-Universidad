#include <list>
#include <climits>

const int n = 100;

struct Vertice {
    char nombre[50];
    int valor;
};

class Grafo {
public:
    Grafo();
    ~Grafo();
    std::list<Vertice> rutaMasCorta(int origen, int destino);

private:
    Vertice V[n];
    int ma[n][n];

    int minDistancia(int dist[], bool sptSet[]);
    void imprimirRuta(int parent[], int j, std::list<Vertice>& ruta);
};

int Grafo::minDistancia(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void Grafo::imprimirRuta(int parent[], int j, std::list<Vertice>& ruta) {
    if (parent[j] == -1)
        return;

    imprimirRuta(parent, parent[j], ruta);
    ruta.push_back(V[j]);
}

std::list<Vertice> Grafo::rutaMasCorta(int origen, int destino) {
    std::list<Vertice> ruta;

    int dist[n]; 
    bool sptSet[n]; 


    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[origen] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistancia(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && ma[u][v] != -1 && dist[u] != INT_MAX && dist[u] + ma[u][v] < dist[v]) {
                dist[v] = dist[u] + ma[u][v];
            }
        }
    }

    int parent[n];
    parent[origen] = -1;

    for (int i = 0; i < n; i++) {
        if (i != origen && dist[i] != INT_MAX) {
            parent[i] = origen;
            imprimirRuta(parent, i, ruta);
            ruta.push_back(V[i]);
        }
    }

    return ruta;
}
