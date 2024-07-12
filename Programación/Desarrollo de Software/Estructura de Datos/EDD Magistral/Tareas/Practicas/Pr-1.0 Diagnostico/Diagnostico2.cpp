#include <stdio.h>

// Función para encontrar la posición de un elemento en un arreglo ordenado descendentemente
int pos(int A[], int n, int k) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        // Si el elemento está en el medio, se devuelve la posición
        if (A[medio] == k)
            return medio;
        // Si el elemento es menor que el medio, se busca en la mitad derecha
        else if (A[medio] < k)
            derecha = medio - 1;
        // Si el elemento es mayor que el medio, se busca en la mitad izquierda
        else
            izquierda = medio + 1;
    }

    // Si el elemento no se encuentra, se devuelve -1
    return -1;
}

int main() {
    int A[] = {40, 30, 20, 10};
    int n = sizeof(A) / sizeof(A[0]);

    printf("pos(30) = %d\n", pos(A, n, 30));
    printf("pos(40) = %d\n", pos(A, n, 40));
    printf("pos(25) = %d\n", pos(A, n, 25));

    return 0;
}
