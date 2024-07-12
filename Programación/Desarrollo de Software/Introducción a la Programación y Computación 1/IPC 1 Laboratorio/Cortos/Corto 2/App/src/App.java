import javax.swing.*;
import java.awt.*;

public class App {
    public static void main(String[] args) {
        A a = new A(110);
        System.out.println(a.getI());
    }
}

class A {
    private int i = 0;

    public A(int i) {
        this.i = 345 + i;
    }

    public int getI() {
        return i;
    }

    public void setI(int i) {
        this.i = i;
    }
}
