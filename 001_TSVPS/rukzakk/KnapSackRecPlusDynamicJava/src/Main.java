public class Main {//нельзя брать только часть предмета, нельзя брать один предмет несколько раз

    int knapsackRec(int[] w, int[] v, int n, int W) {//возвращает максимальную сумму
        if (n <= 0) {
            return 0;
        } else if (w[n - 1] > W) {
            return knapsackRec(w, v, n - 1, W);
        } else {
            return Math.max(knapsackRec(w, v, n - 1, W), v[n - 1]
                    + knapsackRec(w, v, n - 1, W - w[n - 1]));
        }
    }

    int knapsackDP(int[] w, int[] v, int n, int W) {
        if (n <= 0 || W <= 0) {
            return 0;
        }

        int[][] m = new int[n + 1][W + 1];
        for (int j = 0; j <= W; j++) {
            m[0][j] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (w[i - 1] > j) {
                    m[i][j] = m[i - 1][j];
                } else {
                    m[i][j] = Math.max(
                            m[i - 1][j],
                            m[i - 1][j - w[i - 1]] + v[i - 1]);
                }
            }
        }
        return m[n][W];
    }

    public static void main(String[] args) {
        Main ob = new Main();
        int[] weight = {1, 3, 5, 6, 7};//вес 1 предмета
        int[] value = {1, 8, 18, 22, 28};//цена этого предмета
        int n = weight.length;
        int W = 11;//максимальный вес, который можно набрать
        System.out.println(" Максимальная стоимость: " +
                ob.knapsackRec(weight, value, n, W));

    }

}
