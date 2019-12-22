class Main {
    static char name;

    //Функция для вывода оптимального решения
    static void printParenthesis(int i, int j, int n, int[][] bracket) {
        //Если только одна матрица осталась в текущем сегменте
        if (i == j) {
            System.out.print(name++);
            return;
        }
        System.out.print('(');
        // Recursively put brackets around subexpression
        // from i to bracket[j][i].
        // Note that "*((bracket+j*n)+i)" is similar to
        // bracket[i][j]
        printParenthesis(i, bracket[j][i], n, bracket);

        // Recursively put brackets around subexpression
        // from bracket[j][i] + 1 to i.
        printParenthesis(bracket[j][i] + 1, j, n, bracket);

        System.out.print(')');
    }

    // Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
    // Please refer below article for details of this
    // function
    // https://goo.gl/k6EYKj
    static void matrMulTask(int[] p, int n) {
        //для простоты добавлены доп.ряд и доп.столбец в m[0][], m[][0]. Они не используются
        int[][] m = new int[n][n];
        /* m[i,j] = Minimum number of scalar multiplications needed to compute the
         * matrix A[i]A[i+1]...A[j] = A[i..j] where dimension of A[i] is p[i-1] x p[i] */
        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                m[i][j] = Integer.MAX_VALUE;
                for (int k = i; k <= j - 1; k++) {
                    // q = cost/scalar multiplications
                    //q = cost/скалярное произведение
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        // Each entry m[j,ji=k shows// where to split the product arr// i,i+1....j for the minimum cost.
                        //Каждый вход m[j,ji=k показывает где разделить произведение r
                        //i, i+1...j за минимальную цену
                        m[j][i] = k;
                    }
                }
            }
        }
        name = 'A';//первую матрицу называем A, вторую B и т.д.
        System.out.print("Оптимальная расстановка скобок: ");
        printParenthesis(1, n - 1, n, m);//нулевой матрицы нет, начинаем с первой
        System.out.print("\nЧисло умножений :" + m[1][n - 1]);
    }

    public static void main(String[] args) {
        int[] r = {10, 20, 50, 1, 100, 10};
        int n = r.length;
        matrMulTask(r, n);
    }
}