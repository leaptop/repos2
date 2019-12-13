import java.util.Random;
import java.util.Scanner;

class Main {
    private static int c = 0;
    private static int  mm = 0;

    static void mergeSort(int arr[], int n) {
        int curr_size;//изменяется от одного до n/2
        int left_start;/*выбираю начальный индекс
         левого подмассива для слияния*/

        /*
        Сливаю подмассивы снизу вверх.
        Сначала сливаю подмассивы размера один,
        чтобы создать отсортированные подмассивы размера 2,
        потом сливаю подмассивы размера 2, чтобы создать
        отсортированные подмассивы размера 4 и т.д.
         */
        for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
            /*
            Выбираю начальную точку разных
            подмассивов текущего размера
             */

            for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
              /*
              ищу конечную точку левого подмассива.
              mid+1(один) - начальная точка правого
               */
                int mid = Math.min(left_start + curr_size - 1, n - 1);

                int right_end = Math.min(left_start + 2 * curr_size - 1, n - 1);
/*
Сливаю подмассивы arr[left_start...mid] и arr[mid+1...right_end]
 */
                merge(arr, left_start, mid, right_end);

                //printArray(arr,);
            }
            System.out.println();
        }
    }

    /*  Функция для слияния двух половин arr[l(L)..m] и
    arr[m+1(one)..r] массива arr[] */
    static void merge(int arr[], int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Создаю временные массивы */
        int L[] = new int[n1];
        int R[] = new int[n2];

        /* Копирую данные во временные массивы L[] и R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        /* Сливаю временные массмвы обратно к arr[l(L)..r]*/
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
                System.out.printf(arr[k] + " ");
                mm++;
            } else {
                arr[k] = R[j];
                j++;
                System.out.printf(arr[k] + " ");
                mm++;
            }
            k++;
            c++;
        }
		/*Копирую оставшиеся элементы L[]
		если они ещё есть*/
        while (i < n1) {
            arr[k] = L[i];
            i++;
            System.out.printf(arr[k] + " ");
            k++;
            mm++;
        }

		/*Копирую оставшиеся элементы R[]
		если они ещё есть*/
        while (j < n2) {
            arr[k] = R[j];
            j++;
            System.out.printf(arr[k] + " ");
            k++;
            mm++;
        }
        System.out.printf("|");
    }

    /*  Функция для вывода массива*/
    static void printArray(int A[], int size) {
        int i;
        for (i = 0; i < size; i++)
            System.out.printf("%d ", A[i]);
        System.out.printf("\n");
    }

    public static void main(String[] args) {
        // int arr[] = {12, 11, 13, 5, 6, 7};
        // int n = arr.length;
        System.out.println("insert a size of array a: ");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println("insert next number of array: ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        System.out.printf("Given array is \n");
        printArray(arr, n);
        mergeSort(arr, n);

        System.out.printf("\nSorted array is \n");
        printArray(arr, n);

        System.out.println("Сравнения: " + String.valueOf(c));
        System.out.println("Перемещения: " + String.valueOf(mm));
    }
}
