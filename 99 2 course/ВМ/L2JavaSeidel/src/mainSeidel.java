import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class mainSeidel {
    public static final int MAX_ITERATIONS = 50;
    private double[][] M;

    public mainSeidel(double[][] matrix) {
        M = matrix;
    }

    public void solveSeidel() {
        int iterations = 0;
        int n = M.length;
        double[] X = new double[n];
        Arrays.fill(X, 0);// зануляем матрицу решений

        while (true) {
            for (int i = 0; i < n; i++) {
                double sum = M[i][n]; //сначала в sum добавляется свободный член

                for (int j = 0; j < n; j++)
                    if (j != i)//если это не искомая переменная, то работаем
                        sum -= M[i][j] * X[j];//переносим коэффициенты в правую часть,
//домножая их на соответствующие значения Х из матрицы решений. Делаем это для n значений текущей строки

                X[i] = sum / M[i][i];//делим sum на коэффициент искомой переменной. Всё как в тетради.
            }//5 знаков после запятой
//  X[j] сразу получает доступ к новым приближенным значениям
            System.out.print("Итерация " + iterations + " {");
            for (int i = 0; i < n; i++) {
                System.out.printf("%2.5f", X[i]);
                System.out.print("   ");
            }
            System.out.println("}");

            iterations++;
            if (iterations == MAX_ITERATIONS) break;
        }
    }

    public void solveMPI()//(МПИ)
    {
        int iterations = 0;
        int n = M.length;
        double[] X = new double[n];
        double[] T = new double[n];
        Arrays.fill(X, 0);// зануляем матрицу решений

        while (true) {
            for (int i = 0; i < n; i++) {
                double sum = M[i][n]; //сначала в sum добавляется свободный член

                for (int j = 0; j < n; j++)
                    if (j != i)//если это не искомая переменная, то работаем
                        sum -= M[i][j] * X[j];//переносим коэффициенты в правую часть,
//домножая их на соответствующие значения Х из матрицы решений. Делаем это для n значений текущей строки

                T[i] = sum / M[i][i];//делим sum на коэффициент искомой переменной.
            }//только с коэффициентами бы ещё разобраться
            for (int d = 0; d < n; d++)
                X[d] = T[d];

            System.out.print("Итерация " + iterations + " {");
            for (int i = 0; i < n; i++) {
                System.out.printf("%2.5f", X[i]);
                System.out.print("   ");
            }
            System.out.println("}");

            iterations++;
            if (iterations == MAX_ITERATIONS) break;
        }
    }

    public static void main2(String[] args) throws IOException {
        int n;
        double[][] M;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Введите число переменных:");
        n = Integer.parseInt(reader.readLine());
        M = new double[n][n + 1];
        System.out.println("Введите дополненную матрицу");//augment - увеличивать, дополнять

        for (int i = 0; i < n; i++) {
            StringTokenizer strtk = new StringTokenizer(reader.readLine());

            while (strtk.hasMoreTokens())
                for (int j = 0; j < n + 1 && strtk.hasMoreTokens(); j++)
                    M[i][j] = Integer.parseInt(strtk.nextToken());
        }
        mainSeidel sei = new mainSeidel(M);
        sei.solveSeidel();
    }
}
/*
2 -1 1 1
-1 2 -1 0
3 1 -2 -3
*/