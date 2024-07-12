template <class T> class NodoBinario {
public:
  T valor;
  NodoBinario<T> *izq;
  NodoBinario<T> *der;
};

template <class T> class ArbolBinario {
public:
  ArbolBinario<T> *espejo() {
    ArbolBinario<T> *arbolEspejo = new ArbolBinario<T>();
    arbolEspejo->raíz = espejoAux(raíz);
    return arbolEspejo;
  }

private:
  NodoBinario<T> *raíz;

  NodoBinario<T> *espejoAux(NodoBinario<T> *nodo) {
    if (nodo == nullptr) {
      return nullptr;
    }

    NodoBinario<T> *nodoEspejo = new NodoBinario<T>();
    nodoEspejo->valor = nodo->valor;
    nodoEspejo->izq = espejoAux(nodo->der);
    nodoEspejo->der = espejoAux(nodo->izq);
    return nodoEspejo;
  }
};
