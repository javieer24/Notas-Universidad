template <class K, class T>
class ArbolBinBusq {
public:
    bool esHB(int k) {
        int altura;
        return esHB(raíz, k, altura);
    }
private:
    NodoBinBusq<K,T> *raíz;

    bool esHB(NodoBinBusq<K,T>* nodo, int k, int& altura) {
        if (nodo == nullptr) {
            altura = 0;
            return true;
        }

        int alturaIzq, alturaDer;
        bool esHBIzq = esHB(nodo->izq, k, alturaIzq);
        bool esHBDer = esHB(nodo->der, k, alturaDer);

        altura = max(alturaIzq, alturaDer) + 1;

        return esHBIzq && esHBDer && abs(alturaIzq - alturaDer) <= k;
    }
};
