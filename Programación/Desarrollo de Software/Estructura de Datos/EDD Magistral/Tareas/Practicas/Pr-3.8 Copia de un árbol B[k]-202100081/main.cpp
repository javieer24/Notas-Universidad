template <class K, class T, int k>
class NodoB {
public:
    K llaves[k];
    T info[k];
    NodoB* hijo[k+1];
    int conteo;

    NodoB* copia() {
        NodoB* nuevoNodo = new NodoB;
        nuevoNodo->conteo = conteo;
        for(int i = 0; i < conteo; i++) {
            nuevoNodo->llaves[i] = llaves[i];
            nuevoNodo->info[i] = info[i];
            if(hijo[i]) {
                nuevoNodo->hijo[i] = hijo[i]->copia();
            }
        }
        if(hijo[conteo]) {
            nuevoNodo->hijo[conteo] = hijo[conteo]->copia();
        }
        return nuevoNodo;
    }
};

template <class K, class T,int k>
class ArbolB {
public:
    NodoB<K,T,k> *raíz;

    ArbolB<K,T,k>* copia() {
        ArbolB<K,T,k>* nuevoArbol = new ArbolB;
        if(raíz) {
            nuevoArbol->raíz = raíz->copia();
        }
        return nuevoArbol;
    }
};
