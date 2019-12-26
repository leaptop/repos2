package com.company;//сам пишу мешок рюкзак

public class Main {

    public static int f(int mm) {
        int s = 0, M = 13;
        int[] m = {3, 5, 8};
        int[] c = {8, 14, 23};
        for (int i = 0; i < m.length; i++) {
            s = Math.max(f(M - m[i])+c[i], f(M - m[i + 1]+c[i+1]));
            if(mm<0)return s;
        }
        return s;
       // return 0;
    }

    public static void main(String[] args) {
        int M = 13;
        f(0);
        System.out.println("s = "+f(0));
    }
}
