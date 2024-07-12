#include <string>
#include <stdexcept>

class NodoExp {
public:
    std::string valor; 
    NodoExp *izq;
    NodoExp *der;

    NodoExp(const std::string &v, NodoExp *i = nullptr, NodoExp *d = nullptr)
        : valor(v), izq(i), der(d) {}
};

class ArbolExp {
public:
    int valor(); 

private:
    NodoExp *raiz;

    int evaluar(NodoExp *nodo);
};

int ArbolExp::valor() {
    if (!raiz) {
        throw std::runtime_error("El árbol está vacío");
    }
    return evaluar(raiz);
}

int ArbolExp::evaluar(NodoExp *nodo) {
    if (!nodo) {
        throw std::runtime_error("Nodo inválido");
    }

    // Si es un nodo hoja, debe ser un operando
    if (!nodo->izq && !nodo->der) {
        return std::stoi(nodo->valor);
    }

    // Evaluar subárbol izquierdo y derecho
    int valorIzq = evaluar(nodo->izq);
    int valorDer = evaluar(nodo->der);

    // Realizar operación basada en el valor del nodo actual
    if (nodo->valor == "+") {
        return valorIzq + valorDer;
    } else if (nodo->valor == "-") {
        return valorIzq - valorDer;
    } else if (nodo->valor == "*") {
        return valorIzq * valorDer;
    } else if (nodo->valor == "/") {
        if (valorDer == 0) {
            throw std::runtime_error("División por cero");
        }
        return valorIzq / valorDer;
    } else {
        throw std::runtime_error("Operador desconocido: " + nodo->valor);
    }
}
