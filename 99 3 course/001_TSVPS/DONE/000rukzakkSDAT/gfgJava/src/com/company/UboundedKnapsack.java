package com.company;

// Java program to find maximum achievable
// value with a knapsack of weight W and
// multiple instances allowed.
public class UboundedKnapsack {
    static int cnt1 = 0;
    static int cnt2 = 0;
    static int cnt3 = 0;

    private static int max(int i, int j) {
        return (i > j) ? i : j;//вернуть максимальное из i & j
    }

    // Returns the maximum value with knapsack of W capacity
    private static int unboundedKnapsack(int W, int n, int[] val, int[] wt) {
        // dp[i] is going to store maximum value
        // with knapsack capacity i.
        int dp[] = new int[W + 1];

        // Fill dp[] using above recursive formula
        for (int i = 0; i <= W; i++) {
            for (int j = 0; j < n; j++) {
                if (wt[j] <= i) {
                    dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);

                }
            }
        }
        for(int i = 0; i<dp.length; i++){
            //System.out.println("dp["+i+"] = "+dp[i]);
        }
        return dp[W];
    }

    // Driver program
    public static void main(String[] args) {

        int W = 100;
        int[][] result = new int[3][];
        String[] names = {"sugar", "socks", "TV"};
        int val[] = {10, 30, 200};
        int wt[] = {5, 10, 55};
        int n = val.length;
        System.out.println(unboundedKnapsack(W, n, val, wt));
        System.out.println("cnt1 = "+ cnt1+", cnt2 = "+ cnt2+", cnt3 = "+ cnt3);
    }
}