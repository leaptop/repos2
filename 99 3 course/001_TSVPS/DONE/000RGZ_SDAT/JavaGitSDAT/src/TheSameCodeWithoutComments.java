import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class TheSameCodeWithoutComments {
    static int cntSimple = 0, cntStrassen = 0;
    public static int[][] simplMul(int[][] A, int[][] B) {
        int[][] res = new int[A.length][A.length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A.length; j++) {
                for (int k = 0; k < A.length; k++) {
                    res[i][j] += A[i][k] * B[k][j];
                    cntSimple += 1;
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
            int[][] A1 = new int[n / 2][n / 2];
            int[][] A2 = new int[n / 2][n / 2];
            int[][] A3 = new int[n / 2][n / 2];
            int[][] A4 = new int[n / 2][n / 2];
            int[][] B1 = new int[n / 2][n / 2];
            int[][] B2 = new int[n / 2][n / 2];
            int[][] B3 = new int[n / 2][n / 2];
            int[][] B4 = new int[n / 2][n / 2];
            matrDivision(A, A1, 0, 0);
            matrDivision(A, A2, 0, n / 2);
            matrDivision(A, A3, n / 2, 0);
            matrDivision(A, A4, n / 2, n / 2);
            matrDivision(B, B1, 0, 0);
            matrDivision(B, B2, 0, n / 2);
            matrDivision(B, B3, n / 2, 0);
            matrDivision(B, B4, n / 2, n / 2);
            int[][] M1 = StrassMul(subMatrices(A2, A4), addMatrices(B3, B4));
            int[][] M2 = StrassMul(addMatrices(A1, A4), addMatrices(B1, B4));
            int[][] M3 = StrassMul(subMatrices(A1, A3), addMatrices(B1, B2));
            int[][] M4 = StrassMul(addMatrices(A1, A2), B4);
            int[][] M5 = StrassMul(A1, subMatrices(B2, B4));
            int[][] M6 = StrassMul(A4, subMatrices(B3, B1));
            int[][] M7 = StrassMul(addMatrices(A3, A4), B1);
            int[][] C11 = addMatrices(subMatrices(addMatrices(M2, M6), M4), M1);
            int[][] C12 = addMatrices(M4, M5);
            int[][] C21 = addMatrices(M6, M7);
            int[][] C22 = subMatrices(subMatrices(addMatrices(M2, M5), M7), M3);
            assembleMatrices(C11, res, 0, 0);
            assembleMatrices(C12, res, 0, n / 2);
            assembleMatrices(C21, res, n / 2, 0);
            assembleMatrices(C22, res, n / 2, n / 2);
        }
        return res;
    }
//    public static void main(String[] args) throws NumberFormatException, IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        System.out.println("Введите размер матрицы:");
//        int order = Integer.parseInt(br.readLine());
//        int[][] A = new int[order][order];
//        int[][] B = new int[order][order];
//        int[][] res = new int[order][order];
//        for (int i = 0; i < order; i++) {
//            for (int j = 0; j < order; j++) {
//                A[i][j] = (int) Math.pow(-1, (i + j));
//            }
//        }
//        for (int i = 0; i < order; i++) {
//            for (int j = 0; j < order; j++) {
//                B[i][j] = i + j;
//            }
//        }
//        res = StrassMul(A, B);
//        printMatrix(res);
//        System.out.println("\nТрудоёмкость Штрассен:" + cntStrassen + "\n");
//        res = null;
//        res = simplMul(A, B);
//        printMatrix(res);
//        System.out.println("\nТрудоёмкость простого:" + cntSimple + "\n");
//    }
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
    public static void matrDivision(int[][] P, int[][] C, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                C[i1][j1] = P[i2][j2];
    }
    public static void assembleMatrices(int[][] C, int[][] P, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
            for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                P[i2][j2] = C[i1][j1];
    }
}