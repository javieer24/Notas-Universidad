import java.util.Queue;
import java.util.LinkedList;

public class Pila {
    private Queue<Integer> qPrincipal;
    private Queue<Integer> qAuxiliar;

    public Pila() {
        qPrincipal = new LinkedList<Integer>();
        qAuxiliar = new LinkedList<Integer>();
    }

    public boolean estaVacia() {
        return qPrincipal.isEmpty();
    }

    public void push(int elemento) {
        qPrincipal.offer(elemento);
    }

    public int pop() {
        if (estaVacia()) {
            return -1;
        }
        while (qPrincipal.size() > 1) {
            qAuxiliar.offer(qPrincipal.poll());
        }
        int elemento = qPrincipal.poll();
        Queue<Integer> temp = qPrincipal;
        qPrincipal = qAuxiliar;
        qAuxiliar = temp;
        return elemento;
    }

    public int top() {
        if (estaVacia()) {
            return -1;
        }
        while (qPrincipal.size() > 1) {
            qAuxiliar.offer(qPrincipal.poll());
        }
        int elemento = qPrincipal.poll();
        qAuxiliar.offer(elemento);
        Queue<Integer> temp = qPrincipal;
        qPrincipal = qAuxiliar;
        qAuxiliar = temp;
        return elemento;
    }

}
