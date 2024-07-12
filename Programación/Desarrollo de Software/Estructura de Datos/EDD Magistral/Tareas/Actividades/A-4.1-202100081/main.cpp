#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>

typedef struct {
    long CodCliente;
    std::string nombre;
    std::string telefono;
    std::string direccion;
    long horaAcceso; // marca de tiempo al acceder el registro
} Cliente;

enum Estado {
    LIBRE,
    OCUPADO,
    BORRADO
};

class Cache {
public:
    Cache(int tam) : tam(tam), clientes(tam, nullptr), estados(tam, LIBRE) {}
    ~Cache() {
        for (auto cliente : clientes) {
            delete cliente;
        }
    }

    int size() {
        return std::count_if(estados.begin(), estados.end(), [](Estado estado) { return estado == OCUPADO; });
    }

    const Cliente* get(long codCliente) {
        int idx = hash(codCliente);
        int startIdx = idx;
        while (estados[idx] != LIBRE) {
            if (estados[idx] == OCUPADO && clientes[idx]->CodCliente == codCliente) {
                clientes[idx]->horaAcceso = std::time(0);
                return clientes[idx];
            }
            idx = (idx + 1) % tam;
            if (idx == startIdx) break; // Full cycle, element not found
        }
        return nullptr;
    }

    bool add(Cliente info) {
        int idx = hash(info.CodCliente);
        int startIdx = idx;
        while (estados[idx] == OCUPADO) {
            idx = (idx + 1) % tam;
            if (idx == startIdx) return false; // Table is full
        }
        if (clientes[idx]) delete clientes[idx];
        clientes[idx] = new Cliente(info);
        estados[idx] = OCUPADO;
        return true;
    }

    bool del(long codCliente) {
        int idx = hash(codCliente);
        int startIdx = idx;
        while (estados[idx] != LIBRE) {
            if (estados[idx] == OCUPADO && clientes[idx]->CodCliente == codCliente) {
                delete clientes[idx];
                clientes[idx] = nullptr;
                estados[idx] = BORRADO;
                return true;
            }
            idx = (idx + 1) % tam;
            if (idx == startIdx) break; // Full cycle, element not found
        }
        return false;
    }

private:
    int tam;
    std::vector<Cliente*> clientes;
    std::vector<Estado> estados;

    int hash(long codCliente) {
        return codCliente % tam;
    }
};
