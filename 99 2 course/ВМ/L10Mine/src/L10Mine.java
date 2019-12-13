public class L10Mine {
    static double a = 1.0;
    static double b = 2.0;

    static int Razb = 10;// число разбиений
    static int N = Razb, n = Razb / 2;
    static double h = (b - a) / N;
    static double H = (b - a) / n;
    static double e = 0.00000001;// надо до 10 в минус восьмой

    public static double f(double x) {
        return 1 / x;
    }

    //медленная функция: (но я всё равно горжусь ею)
    public static double integrateTrapezii(double a, double b, double h) {
        int counter = 0;
        double sum = 0, x = 0;
        for (int i = 0; x < b; i++) {
            x = a + h * i;
            sum += h * (f(x) + f(x + h)) / 2;
            counter++;
        }
        System.out.println("Counter = " + counter);
        return sum;
    }

    //эта реализация побыстрее считает:
    public static double trapezoid(double a, double b, int n) {
        double h = (b - a) / n;
        double x = a;
        double sum = 0;

        for (int i = 1; i < n; i++) {
            x = a + i * h;
            sum += f(x);
        }

        sum = 2 * sum + (f(a) + f(b));
        //System.out.println("Counter = " + counter);
        return sum * h / 2;
    }

    //медленная функция:
    public static double integrateSimpson0(double a, double b, double h, int N) {
        // 1/3
        double sum = 1.0 / 3.0 * (f(a) + f(b));//

        // 4/3
        for (int i = 1; i < N - 1; i += 2) {
            double x = a + h * i;
            sum += 4.0 / 3.0 * f(x);
        }

        // 2/3
        for (int i = 2; i < N - 1; i += 2) {
            double x = a + h * i;
            sum += 2.0 / 3.0 * f(x);
        }

        return sum * h;
    }

    // быстрая функция:
    public static double simpson(double a, double b, double hh, int n) {
        double range = b - a;
        double nn = (double) n;// это чтобы не кастовать n к даблу в каждом действии
        double sum1 = f(a + range / (nn * 2.0)); // нашёл значение функции от (а + 1/2 шага)
        double sum2 = 0.0;
        for (int i = 1; i < n; i++) {
            double x1 = a + range * ((double) i + 0.5) / nn;//пошагово вычисляю зн. икс в серединах между точками разбиения
            sum1 += f(x1);
            double x2 = a + range * (double) i / nn;// пошагово вычисляю зн. икс во всех точках разбиения
            sum2 += f(x2);
        }
        return range * (f(a) + f(b) + sum1 * 4.0 + sum2 * 2.0)  / (nn * 6.0);
    }

    public static void main(String[] args) {
        double aa, bb, dif;
        System.out.println("\nTrapezii: ");
        Razb = 10;// число разбиений
        N = Razb;
        n = Razb / 2;
        h = (b - a) / N;
        H = (b - a) / n;
        System.out.println("Trapezii(H) : " + trapezoid(a, b, n) + ", H = " + H);
        System.out.println("Trapezii(h) : " + trapezoid(a, b, N) + ", h = " + h);
        aa = trapezoid(a, b, n);
        bb = trapezoid(a, b, N);
        dif = Math.abs(Math.abs(bb) - Math.abs(aa));

        while (dif > e) {
            //correct = aa + 1.0 / 3.0 * (aa - bb);
            dif = Math.abs(Math.abs(bb) - Math.abs(aa));
            Razb += 100;
            N = Razb; //большее число разбиений
            n = Razb / 2;//меньшее число разбиений
            h = (b - a) / N;//меньший шаг
            H = (b - a) / n;//больший шаг
            aa = trapezoid(a, b, n);
            bb = trapezoid(a, b, N);
            System.out.println("    Correct = " + aa + ", h = " + h + "");
            System.out.println("    Correct = " + bb + ", H = " + H + "");
        }
        System.out.println("Точность : " + e);


        System.out.println("\nSimpson: ");
        Razb = 10;// число разбиений
        N = Razb;
        n = Razb / 2;
        h = (b - a) / N;
        H = (b - a) / n;
        aa = simpson(a, b, h, N);
        bb = simpson(a, b, H, n);
        double correct = 0, correct2 = 0;
        dif = Math.abs(Math.abs(bb) - Math.abs(aa));
        System.out.println("Simpson(h) : " + aa + ", h = " + h);
        System.out.println("Simpson(H) : " + bb + ", H = " + H);
        while (dif > 3.0 * e) {// если здесь д.б. цикл, то как его реализовать?
            dif = Math.abs(Math.abs(bb) - Math.abs(aa));
            Razb += 10;
            N = Razb; //большее число разбиений
            n = Razb / 2;//меньшее число разбиений
            h = (b - a) / N;//меньший шаг
            H = (b - a) / n;//больший шаг
            aa = simpson(a, b, h, N);
            bb = simpson(a, b, H, n);
            System.out.println("    Correct = " + aa + ", h = " + h + "");
            System.out.println("    Correct = " + bb + ", H = " + H + "");
        }
        // correct = correct + 1.0 / 3.0 * (aa - bb);
        correct = aa + 1.0 / 3.0 * (aa - bb);
        System.out.println("Точность : " + e);
    }// ln(2) = 0.6931471805599
    //Simpson при шаге 0.01 даёт погрешность десять в минус восьмой, трапеции тоже быстрее должны быть
}