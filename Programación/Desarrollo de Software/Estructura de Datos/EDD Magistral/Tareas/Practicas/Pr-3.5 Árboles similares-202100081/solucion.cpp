template <class T>
class NodoBinario {
public:
    T valor;
    NodoBinario<T> *izq;
    NodoBinario<T> *der;
};

template <class T>
class ArbolBinario {
public:
    bool similar(ArbolBinario<T> arbol2) {
        return similarAux(this->raiz, arbol2.raiz);
    }

private:
    NodoBinario<T> *raiz;

    bool similarAux(NodoBinario<T>* raiz1, NodoBinario<T>* raiz2) {
        if (raiz1 == nullptr && raiz2 == nullptr)
            return true;
        if (raiz1 == nullptr || raiz2 == nullptr)
            return false;
        return similarAux(raiz1->izq, raiz2->izq) && similarAux(raiz1->der, raiz2->der);
    }
};
