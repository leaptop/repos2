import java.util.Random;
import java.util.Scanner;

public class SelectSort {

    static void ss() {
        int c = 0, m = 0;
        Random rand = new Random();
        int n = 100;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = rand.nextInt(100);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int sh = 0; sh < n; sh++) System.out.print(a[sh] + " ");
            int minI = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[minI]) {//searching for an index of the smallest element in the list, that's left
                    c++;
                    minI = j;
                }
            int tmp = a[minI];
            a[minI] = a[i];
            a[i] = tmp;
            m++;

            System.out.println();
        }
        System.out.println("Comparisons: " + c + " Moves: " + m);
    }

    public static void main(String[] args) {
        int c = 0, m = 0;
        System.out.println("insert a size of array a: ");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println("insert next number of array: ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            //for (int sh = 0; sh < n; sh++) System.out.print(a[sh] + " ");
            int minI = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[minI]) {//searching for an index of the smallest element in the list, that's left
                    minI = j;
                }
                c++;
            }
            if (a[minI] < a[i]) {
                int tmp = a[minI];
                a[minI] = a[i];
                a[i] = tmp;
                m += 3;
            }

        }
        for (int ii = 0; ii < n; ii++) System.out.print(a[ii] + " ");
        System.out.println("Comparisons: " + c + " Moves: " + m);
    }
}
