import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Codechef {
    static int cnt = 0, cnt2 = 0;

    private static int[][] StrassenMultiply(int[][] A, int[][] B) {

        int n = A.length;


        int[][] res = new int[n][n];

        // if the input matrix is 1x1
        if (n == 1) {
            cnt2 += 1;
            res[0][0] = A[0][0] * B[0][0];
        } else {
            // cnt2 += 25;
            // first matrix
            int[][] a = new int[n / 2][n / 2];
            int[][] b = new int[n / 2][n / 2];
            int[][] c = new int[n / 2][n / 2];
            int[][] d = new int[n / 2][n / 2];

            // second matrix
            int[][] e = new int[n / 2][n / 2];
            int[][] f = new int[n / 2][n / 2];
            int[][] g = new int[n / 2][n / 2];
            int[][] h = new int[n / 2][n / 2];

            // dividing matrix A into 4 parts
            divideArray(A, a, 0, 0);//заполнили матрицу a "левой верхней четвертинкой исходной матрицы A
            divideArray(A, b, 0, n / 2);
            divideArray(A, c, n / 2, 0);
            divideArray(A, d, n / 2, n / 2);

            // dividing matrix B into 4 parts
            divideArray(B, e, 0, 0);
            divideArray(B, f, 0, n / 2);
            divideArray(B, g, n / 2, 0);
            divideArray(B, h, n / 2, n / 2);//Разделили исходные матрицы на 4 части каждую
//в итоге создали 8 подматриц

//из этих 8 подматриц сделаем новые по схеме:
            /**
             p1 = (a + d)(e + h)
             p2 = (c + d)e
             p3 = a(f - h)
             p4 = d(g - e)
             p5 = (a + b)h
             p6 = (c - a) (e + f)
             p7 = (b - d) (g + h)
             **/
            int[][] p1 = StrassenMultiply(addMatrices(a, d), addMatrices(e, h));
            int[][] p2 = StrassenMultiply(addMatrices(c, d), e);
            int[][] p3 = StrassenMultiply(a, subMatrices(f, h));
            int[][] p4 = StrassenMultiply(d, subMatrices(g, e));
            int[][] p5 = StrassenMultiply(addMatrices(a, b), h);
            int[][] p6 = StrassenMultiply(subMatrices(c, a), addMatrices(e, f));
            int[][] p7 = StrassenMultiply(subMatrices(b, d), addMatrices(g, h));


            /**
             C11 = p1 + p4 - p5 + p7
             C12 = p3 + p5
             C21 = p2 + p4
             C22 = p1 - p2 + p3 + p6
             **/

            int[][] C11 = addMatrices(subMatrices(addMatrices(p1, p4), p5), p7);// у Цешек размеры n/2
            int[][] C12 = addMatrices(p3, p5);
            int[][] C21 = addMatrices(p2, p4);
            int[][] C22 = addMatrices(subMatrices(addMatrices(p1, p3), p2), p6);

            // собираем подмассивы обратно в один
            copySubArray(C11, res, 0, 0);//у res при этом размеры n
            copySubArray(C12, res, 0, n / 2);//т.е. здесь мы собираем матрицу обратно в res
            copySubArray(C21, res, n / 2, 0);
            copySubArray(C22, res, n / 2, n / 2);
            cnt2 += 25;
        }
        return res;//и возвращаем её
    }

    public static int[][] simplMul(int[][] A, int[][] B) {
        int[][] res = new int[A.length][A.length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A.length; j++) {
                for (int k = 0; k < A.length; k++) {
                    res[i][j] += A[i][k] * B[k][j];
                    cnt++;
                }

            }
        }
        return res;
    }

    /*void simpleMul(double **matrix1, double **matrix2, double **resultMatrix, int order) {
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                for (int k = 0; k < order; k++) {
                    resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                    cnt++;
                }
            }
        }
    }*/


    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Введите размер матрицы:");
        int order = Integer.parseInt(br.readLine());

        int[][] A = new int[order][order];
        int[][] B = new int[order][order];
        /*A[0][0] = 1;
        A[0][1] = 2;
        A[1][0] = 3;
        A[1][1] = 4;
        B[0][0] = 5;
        B[0][1] = 6;
        B[1][0] = 7;
        B[1][1] = 8;*/
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
        System.out.println("Enter first matrix:");
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                // A[i][j] = Integer.parseInt(br.readLine());
                A[i][j] = (int) Math.pow(-1, (i + j));
            }
        }

        // введите вторую матрицу
        System.out.println("Enter second matrix:");
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                //B[i][j] = Integer.parseInt(br.readLine());
                B[i][j] = i + j;
            }
        }
        System.out.println("Умножение Штрассеном:\n");
        res = StrassenMultiply(A, B); //StrassenMultiply всегда возвращает матрицу
        printMatrix(res);
        System.out.println("\nТрудоёмкость:" + cnt2 + "\n");
        res = null;


       /* for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                //B[i][j] = Integer.parseInt(br.readLine());
                B[i][j] = i + j;
            }
        }
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                // A[i][j] = Integer.parseInt(br.readLine());
                A[i][j] = (int) Math.pow(-1, (i + j));
            }
        }*/
        System.out.println("Умножение простое:\n");
        res = simplMul(A, B);
        printMatrix(res);
        System.out.println("\nТрудоёмкость:" + cnt + "\n");
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
        System.out.println("Resultant Matrix ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    //делим матрицу на 4 части
    public static void divideArray(int[][] P, int[][] C, int iB, int jB) {//Переписываем кусок матрицы P в C
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)//в соотвтетствиии с парасметрами int iB, int jB
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)//на втором вызове jB = n/2 (2)
                C[i1][j1] = P[i2][j2];//причём при каждом новом вызове функции индексы рядов и столбцов нулевые
    }//(это для новой матрицы просто. А вот индексы "разбираемой" матрицы(iB, jB) задаются при вызове


    public static void copySubArray(int[][] C, int[][] P, int iB, int jB) {//собираем матрицу из 4-х кусков
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                P[i2][j2] = C[i1][j1];
    }

}