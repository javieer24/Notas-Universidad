#include <iostream>
#include <list>

const int n = 10; 

struct Vertice {
    char nombre[50];
    int valor;
};

class Grafo {
public:
    Grafo();
    ~Grafo();
    std::list<Vertice> ciclo();

private:
    Vertice V[n];
    int ma[n][n];

    bool dfs(int v, bool visitado[], bool enRecorrido[], std::list<Vertice>& cicloEncontrado);
};

std::list<Vertice> Grafo::ciclo() {
    bool visitado[n] = {false};
    bool enRecorrido[n] = {false};
    std::list<Vertice> cicloEncontrado;

    for (int i = 0; i < n; ++i) {
        if (!visitado[i] && dfs(i, visitado, enRecorrido, cicloEncontrado)) {
            // Se encontró un ciclo, devuelve la lista de vértices involucrados
            return cicloEncontrado;
        }
    }

    // No se encontró ningún ciclo
    return std::list<Vertice>();
}

bool Grafo::dfs(int v, bool visitado[], bool enRecorrido[], std::list<Vertice>& cicloEncontrado) {
    visitado[v] = true;
    enRecorrido[v] = true;

    for (int j = 0; j < n; ++j) {
        if (ma[v][j]) {
            if (!visitado[j]) {
                if (dfs(j, visitado, enRecorrido, cicloEncontrado)) {
                    cicloEncontrado.push_front(V[v]);
                    return true;
                }
            } else if (enRecorrido[j]) {
                cicloEncontrado.push_front(V[j]);
                cicloEncontrado.push_front(V[v]);
                return true;
            }
        }
    }

    enRecorrido[v] = false;
    return false;
}

int main() {
    Grafo grafo;
    std::list<Vertice> cicloEncontrado = grafo.ciclo();

    if (!cicloEncontrado.empty()) {
        std::cout << "Ciclo encontrado: ";
        for (const auto& vertice : cicloEncontrado) {
            std::cout << vertice.nombre << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No se encontró ningún ciclo." << std::endl;
    }

    return 0;
}
