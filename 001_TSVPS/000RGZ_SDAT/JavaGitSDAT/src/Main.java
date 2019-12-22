import java.io.BufferedReader;// порядок матрицы д.б. степенью двойки для алгоритма Штрассена
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int cntSimple = 0, cntStrassen = 0;

    public static int[][] simplMul(int[][] A, int[][] B) {
        int[][] res = new int[A.length][A.length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A.length; j++) {
                for (int k = 0; k < A.length; k++) {
                    res[i][j] += A[i][k] * B[k][j];
                    cntSimple += 2;
                }
            }
        }
        return res;
    }

    public static int[][] StrassMul(int[][] A, int[][] B) {

        int n = A.length;

        int[][] res = new int[n][n];

        if (n == 1) {
            cntStrassen += 1;
            res[0][0] = A[0][0] * B[0][0];
        } else {

            // инициализирую новые подматрицы
            int[][] A1 = new int[n / 2][n / 2];
            int[][] A2 = new int[n / 2][n / 2];
            int[][] A3 = new int[n / 2][n / 2];
            int[][] A4 = new int[n / 2][n / 2];

            // инициализирую новые подматрицы
            int[][] B1 = new int[n / 2][n / 2];
            int[][] B2 = new int[n / 2][n / 2];
            int[][] B3 = new int[n / 2][n / 2];
            int[][] B4 = new int[n / 2][n / 2];

            // разбиваем первую матрицу
            matrDivision(A, A1, 0, 0);//заполнили матрицу A1 "левой верхней четвертинкой исходной матрицы A
            matrDivision(A, A2, 0, n / 2);
            matrDivision(A, A3, n / 2, 0);
            matrDivision(A, A4, n / 2, n / 2);

            // разбиваем вторую матрицу
            matrDivision(B, B1, 0, 0);
            matrDivision(B, B2, 0, n / 2);
            matrDivision(B, B3, n / 2, 0);
            matrDivision(B, B4, n / 2, n / 2);//Разделили исходные матрицы на 4 части каждую
//в итоге создали 8 подматриц

//из этих 8 подматриц сделаем новые по схеме:
            /**
             M1 = (A1 + A4)(B1 + B4)
             M2 = (A3 + A4)B1
             M3 = A1(B2 - B4)
             M4 = A4(B3 - B1)
             M5 = (A1 + A2)B4
             M6 = (A3 - A1) (B1 + B2)
             M7 = (A2 - A4) (B3 + B4)
             C11 = M1 + M4 - M5 + M7
             C12 = M3 + M5
             C21 = M2 + M4
             C22 = M1 - M2 + M3 + M6
             **/
            int[][] M1 = StrassMul(addMatrices(A1, A4), addMatrices(B1, B4));
            int[][] M2 = StrassMul(addMatrices(A3, A4), B1);
            int[][] M3 = StrassMul(A1, subMatrices(B2, B4));
            int[][] M4 = StrassMul(A4, subMatrices(B3, B1));
            int[][] M5 = StrassMul(addMatrices(A1, A2), B4);
            int[][] M6 = StrassMul(subMatrices(A3, A1), addMatrices(B1, B2));
            int[][] M7 = StrassMul(subMatrices(A2, A4), addMatrices(B3, B4));//до этой строки уходим вглубь
            // рекурсивно, разбивая матрицы до размера 1 на 1. Дальше собираем всё обратно
            int[][] C11 = addMatrices(subMatrices(addMatrices(M1, M4), M5), M7);// у Цешек размеры n/2
            int[][] C12 = addMatrices(M3, M5);
            int[][] C21 = addMatrices(M2, M4);
            int[][] C22 = addMatrices(subMatrices(addMatrices(M1, M3), M2), M6);

            // собираем подмассивы обратно в один
            assembleMatrices(C11, res, 0, 0);//у res при этом размеры n
            assembleMatrices(C12, res, 0, n / 2);//т.е. здесь мы собираем матрицу обратно в res
            assembleMatrices(C21, res, n / 2, 0);
            assembleMatrices(C22, res, n / 2, n / 2);
        }
        return res;//и возвращаем её
    }


    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Введите размер матрицы:");
        int order = Integer.parseInt(br.readLine());

        int[][] A = new int[order][order];
        int[][] B = new int[order][order];
        A[0][0] = 1;
        A[0][1] = -1;
        A[0][2] = 1;
        A[1][0] = 1;
        A[1][1] = -1;
        A[1][2] = 1;
        A[2][0] = -1;
        A[2][1] = 1;
        A[2][2] = -1;
        B[0][0] = 0;
        B[0][1] = 1;
        B[0][2] = 2;
        B[1][0] = 3;
        B[1][1] = 4;
        B[1][2] = 5;
        B[2][0] = 6;
        B[2][1] = 7;
        B[2][2] = 8;
        int[][] res = new int[order][order];

        // введите первую матрицу
       // System.out.println("введите первую матрицу:");
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                // A[i][j] = Integer.parseInt(br.readLine());
                A[i][j] = (int) Math.pow(-1, (i + j));
            }
        }

        // введите вторую матрицу
       // System.out.println("введите вторую матрицу:");
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                //B[i][j] = Integer.parseInt(br.readLine());
                B[i][j] = i + j;
            }
        }
      //  System.out.println("Умножение Штрассеном:\n");
        res = StrassMul(A, B); //StrassMul всегда возвращает матрицу
        //printMatrix(res);
        System.out.println("\nТрудоёмкость Штрассен:" + cntStrassen + "\n");
        res = null;

      //  System.out.println("Умножение простое:\n");
        res = simplMul(A, B);
      //  printMatrix(res);
        System.out.println("\nТрудоёмкость простого:" + cntSimple + "\n");
    }


    public static int[][] addMatrices(int[][] a, int[][] b) {
        int n = a.length;
        int[][] res = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = a[i][j] + b[i][j];
            }
        }
        return res;
    }

    public static int[][] subMatrices(int[][] a, int[][] b) {
        int n = a.length;
        int[][] res = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = a[i][j] - b[i][j];

            }
        }
        return res;
    }

    public static void printMatrix(int[][] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    //делим матрицу на 4 части
    public static void matrDivision(int[][] P, int[][] C, int iB, int jB) {//Переписываем кусок матрицы P в C
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)//в соотвтетствиии с парасметрами int iB, int jB
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)//на втором вызове jB = n/2 (2)
                C[i1][j1] = P[i2][j2];//причём при каждом новом вызове функции индексы рядов и столбцов нулевые
    }//(это для новой матрицы просто. А вот индексы "разбираемой" матрицы(iB, jB) задаются при вызове


    public static void assembleMatrices(int[][] C, int[][] P, int iB, int jB) {//собираем матрицу из 4-х кусков
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                P[i2][j2] = C[i1][j1];
    }

}