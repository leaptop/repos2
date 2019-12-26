class Main {
    static char name;
    static void printParenthesis(int i, int j, int n, int[][] bracket) {
        if (i == j) {
            System.out.print(name++);
            return;
        }
        System.out.print('(');
        printParenthesis(i, bracket[j][i], n, bracket);
        printParenthesis(bracket[j][i] + 1, j, n, bracket);
        System.out.print(')');
    }
    static void matrMulTask(int[] p, int n) {
        int[][] m = new int[n][n];
        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                m[i][j] = Integer.MAX_VALUE;
                for (int k = i; k <= j - 1; k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        m[j][i] = k;
                    }
                }
            }
        }
        name = 'A';
        System.out.print("Оптимальная расстановка скобок: ");
        printParenthesis(1, n - 1, n, m);
        System.out.print("\nЧисло умножений :" + m[1][n - 1]);
    }
    public static void main(String[] args) {
        int[] r = {10, 20, 50, 1, 100, 10};
        int n = r.length;
        matrMulTask(r, n);
    }
}