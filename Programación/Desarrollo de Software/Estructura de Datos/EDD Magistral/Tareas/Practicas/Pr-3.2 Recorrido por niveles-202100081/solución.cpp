#include <iostream>
#include <queue>

template <class T>
class NodoBin;

template <class T>
class ArbolBin {
public:
    ArbolBin() : raiz(nullptr) {}
    virtual ~ArbolBin() {}

    void recNiveles() {
        if (raiz == nullptr) {
            return;
        }

        std::queue<NodoBin<T>*> cola;
        cola.push(raiz);

        while (!cola.empty()) {
            NodoBin<T>* nodoActual = cola.front();
            cola.pop();

            visita(nodoActual);

            if (nodoActual->izq != nullptr) {
                cola.push(nodoActual->izq);
            }

            if (nodoActual->der != nullptr) {
                cola.push(nodoActual->der);
            }
        }
    }

protected:
    NodoBin<T> *raiz;

    virtual void visita(NodoBin<T> *n) {
        std::cout << n->info << ", ";
    }
};

template <class T>
class NodoBin {
public:
    NodoBin<T> *izq;
    NodoBin<T> *der;
    T info;

    NodoBin() : izq(nullptr), der(nullptr) {}
    NodoBin(T info) : izq(nullptr), der(nullptr), info(info) {}
    virtual ~NodoBin() {}
};
