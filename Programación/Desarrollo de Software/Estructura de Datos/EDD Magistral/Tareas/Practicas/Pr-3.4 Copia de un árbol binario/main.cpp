#include <iostream>
#include <string>

class NodoBinario {
public:
    string valor;
    NodoBinario *izq;
    NodoBinario *der;
};

class ArbolBinario {
public:
    ArbolBinario* copia();
    
private:
    NodoBinario *raiz;

    // Método auxiliar para copiar el árbol recursivamente
    NodoBinario* copiaRecursiva(NodoBinario* nodo);
};

NodoBinario* ArbolBinario::copiaRecursiva(NodoBinario* nodo) {
    if (nodo == nullptr) {
        return nullptr;
    }
    
    // Crear un nuevo nodo y copiar el valor del nodo actual
    NodoBinario* nuevoNodo = new NodoBinario();
    nuevoNodo->valor = nodo->valor;
    
    // Copiar recursivamente los subárboles izquierdo y derecho
    nuevoNodo->izq = copiaRecursiva(nodo->izq);
    nuevoNodo->der = copiaRecursiva(nodo->der);
    
    return nuevoNodo;
}

ArbolBinario* ArbolBinario::copia() {
    // Crear un nuevo árbol binario
    ArbolBinario* nuevoArbol = new ArbolBinario();
    
    // Copiar el árbol original a través de la raíz
    nuevoArbol->raiz = copiaRecursiva(this->raiz);
    
    return nuevoArbol;
};

