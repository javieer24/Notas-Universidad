public class Programa {
    public static void main(String[] args) {
        Pila pila = new Pila();
        pila.push(1);
        pila.push(2);
        pila.push(3);
        System.out.println(pila.pop()); // Salida: 3
        System.out.println(pila.pop()); // Salida: 2
        System.out.println(pila.top()); // Salida: 1
        pila.push(4);
        System.out.println(pila.pop()); // Salida: 4
        System.out.println(pila.pop()); // Salida: 1
        System.out.println(pila.pop()); // Salida: -1 (la pila está vacía)
    }
}