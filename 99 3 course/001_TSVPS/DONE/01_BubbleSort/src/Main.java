import java.util.Random;
import java.util.Scanner;

public class Main {
    static void bs() {
        int c = 0, m = 0;
        Random rand = new Random();
        int n = 10;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = rand.nextInt(50);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int sh = 0; sh < n; sh++) System.out.print(a[sh] + " ");
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {//this is it. Ypu have to compare two neighboring elements. This is authentic bubble
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                    m++;
                }
                c++;
            }
            System.out.println();
        }
        System.out.println("Comparisons: " + c + " Moves: " + m);
    }

    public static void main(String[] args) {
        System.out.println("insert a size of array a: ");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int c = 0, m = 0;
        int[] a = new int[n];
        System.out.println("insert next number of array: ");
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            //for (int sh = 0; sh < n; sh++) {//System.out.print(a[sh] + " ");
                for (int j = 0; j < n - i - 1; j++) {
                    if (a[j] > a[j + 1]) {//this is it. Ypu have to compare two neighboring elements. This is authentic bubble
                        int tmp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = tmp;
                        m++;
                    }
                    c++;
                }
                // System.out.println();
                //bs();


        }
        for (int ii = 0; ii < n; ii++) System.out.print(a[ii] + " ");
        System.out.println("\nComparisons: " + c + " Moves: " + m);
    }
}
