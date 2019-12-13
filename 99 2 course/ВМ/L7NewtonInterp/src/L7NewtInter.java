// Java Program to interpolate using  
// newton forward interpolation 

class L7NewtInter {

    static double u_cal(double u, int n) {//рассчёт u по соответствующему номеру конечной разности
        double temp = u;
        for (int i = 1; i < n; i++)
            temp = temp * (u - i);
        return temp;
    }

    static int fact(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }

    public static void main(String[] args) {
        int n = 4;
        double x[] = {1, 1.2, 1.4, 1.6};

        double y[][] = new double[n][n];
        y[0][0] = 1;
        y[1][0] = 1.0954;
        y[2][0] = 1.1832;
        y[3][0] = 1.2649;

        for (int i = 1; i < n; i++) {//создание таблицы разностей
            for (int j = 0; j < n - i; j++)
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
        for (int i = 0; i < n; i++) {// Показ таблицы разностей
            System.out.print(x[i] + "\t");
            for (int j = 0; j < n - i; j++)
                System.out.print(y[i][j] + "\t");
            System.out.println();
        }
        double value = 1.44;// Точка для интерполяции

        double sum = y[0][0];// значение ф-ции при х[0] теперь занесено в sum
        double u = (value - x[0]) / (x[1] - x[0]);//x[1]-x[0] д.б. константой
        for (int i = 1; i < n; i++) {
            sum = sum + (u_cal(u, i) * y[0][i]) /
                    fact(i);
        }
        System.out.println("\n Value at " + value + " is " + String.format("%.6g%n", sum));
    }
} 