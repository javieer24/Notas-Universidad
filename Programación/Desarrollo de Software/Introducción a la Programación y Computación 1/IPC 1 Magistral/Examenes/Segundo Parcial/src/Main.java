public class Main {
    public static void main(String[] args) {
        Main m = new Main();
        m.f(24, 2);
        System.out.println();
        m.f_iterative(24);
    }

    void f(int num, int div) {
        if (num > 1) {
            if ((num % div) == 0) {
                System.out.println(div);
                f(num / div, div);
            } else {
                f(num, div + 1);
            }
        }
    }

    void f_iterative(int num) {
        int div = 2;
        while (num > 1) {
            if (num % div == 0) {
                System.out.println(div);
                num /= div;
            } else {
                div++;
            }
        }
    }

}
