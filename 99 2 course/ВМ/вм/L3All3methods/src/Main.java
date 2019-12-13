import java.util.function.DoubleFunction;

public class Main {
    private static final double DX = 0.00000001;
    public static double a = 1, b = 2, x = 0, e = 0.000000001;
    static int c = 0;

    public static void init() {
        a = 1;
        b = 2;
        x = a;
        c = 0;
    }

    public static double f(double x) {
        return x * x - 2;
    }

    private static DoubleFunction<Double> derive(DoubleFunction<Double> f) {// здесь как-то считается производная
        return (x) -> (f.apply(x + DX) - f.apply(x)) / DX;
    }

    public static void newt() {// метод Ньютона или метод касательных

        // f(x) = x^2 -2
        DoubleFunction<Double> ff = (x) -> (x * x - 2);
        // f'(x) = 2*x
        DoubleFunction<Double> fDeriv = derive(ff);
        //f''(x) = 2
        DoubleFunction<Double> fDeriv2 = derive(fDeriv);

        if (f(x) * fDeriv2.apply(a) < 0)
            x = a;//условие сходимости выполнено для a
        else x = b;//условие сходимости выполнено для b

        while (Math.abs(f(x)) > e) {
            x = x - f(x) / fDeriv.apply(x);
            print();
        }
    }

    public static void print() {
        System.out.print("Итерация номер: " + ++c + ", промежуточное значение X = ");
        System.out.printf("%2.15f", x);
        System.out.println();
    }

    public void chor() {// метод хорд(модификация МПД
        if (f(a) * f(b) > 0) {
            System.out.println("Условие на сходимость не выполняется");
        } else {
            // while ((Math.abs(f(a) - f(x)) > e) || (Math.abs(f(x) - f(b))) > e) {
            while (Math.abs(f(x)) > e) {
                x = (a * f(b) - b * f(a)) / (f(b) - f(a));
                if (f(a) * f(x) < 0) {//ищем отрезок, на котором функция меняет знак
                    b = x;
                } else a = x;
                print();
            }
        }
    }

    public void mpd() {//метод половинного деления или метод бисекций
        if (f(a) * f(b) > 0) {
            System.out.println("Условие на сходимость не выполняется");
        } else {
            while ((Math.abs(f(a) - f(x)) > e) || (Math.abs(f(x) - f(b))) > e) {
                x = (a + b) / 2;// делим отрезок пополам
                if (f(a) * f(x) < 0) {//ищем отрезок, на котором функция меняет знак
                    b = x;
                } else a = x;
                print();
            }
        }
    }

    public static void main(String[] args) {
        Main mn = new Main();

        init();

        System.out.println("МПД: ");
        mn.mpd();
        System.out.println();
        init();


        System.out.println("Хорды: ");
        mn.chor();
        System.out.println();
        init();

        System.out.println("Ньютон: ");
        newt();


    }
}
