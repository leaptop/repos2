
// здесь тупо разложили формулу DFT по коэффициентам
public class Main {
    public static void main(String[] args) {
        double[] array = new double[kaef_two * kaef_one];
        ComplNum[] res = new ComplNum[kaef_two * kaef_one];
        ComplNum[] back_res = new ComplNum[kaef_two * kaef_one];

        System.out.println("Source array: ");
      //  for (int i = 0; i < kaef_two * kaef_one; i++) {array[i] = i;System.out.printf("%f ", array[i]);}

        array[0] = 1;
        array[1] = 0;
        array[2] = 1;
        array[3] = 0;
        array[4] = 1;
        array[5] = 1;
        array[6] = 0;
        array[7] = 1;
        array[8] = 0;
       // array[9] = 0;

        for (int i = 0; i < kaef_two * kaef_one; i++)
            System.out.printf("%f ", array[i]);

        half_quick_transform(array, res);
        System.out.println("\nReal half quick: ");
        for (int i = 0; i < kaef_two * kaef_one; i++)
            System.out.printf("%f ", res[i].real);
        System.out.println("\nImag half quick: ");
        for (int i = 0; i < kaef_two * kaef_one; i++)
            System.out.printf("%f ", res[i].image);

        back_half_quick_transform(res, back_res);
        System.out.println("\nReal back half quick: ");
        for (int i = 0; i < kaef_two * kaef_one; i++)
            System.out.printf("%f ", back_res[i].real);
        System.out.println("\nImag back half quick: ");
        for (int i = 0; i < kaef_two * kaef_one; i++)
            System.out.printf("%f ", back_res[i].image);

        System.out.printf("\n\nOperations: %d\n\n", count_1 + count_2);
    }

    private static double pi = Math.PI;
    private static int kaef_one = 3, kaef_two = 3;//kaef_one - is p1 in the textbook, kaef_two is p2
    private static int count_1 = 0, count_2 = 0;//для подсчета трудемкости

    private static ComplNum complNumMultiplication(ComplNum a, ComplNum b) {//перемножение компл. чисел
        ComplNum result = new ComplNum();
        result.real = a.real * b.real - a.image * b.image;
        result.image = a.real * b.image + a.image * b.real;
        return result;
    }


    private static ComplNum first_transform(double[] array, int k_1, int j_2) {//counting A(1) in half-fast transform
        double coef;
        ComplNum sum = new ComplNum();
        ComplNum temp = new ComplNum();
        for (int j_1 = 0; j_1 < kaef_one; j_1++) {
            count_1 += 5;
            coef = (double) (j_1 * k_1) / kaef_one;
            temp.real = Math.cos(-2 * pi * coef) * array[j_2 + kaef_two * j_1];
            temp.image = Math.sin(-2 * pi * coef) * array[j_2 + kaef_two * j_1];
            sum.real += temp.real;
            sum.image += temp.image;
        }
        sum.real /= kaef_one;
        sum.image /= kaef_one;
        return sum;
    }

    private static ComplNum second_transform(ComplNum[][] array, int k_1, int k_2) {
        int k;
        double coef;
        ComplNum sum = new ComplNum();
        ComplNum temp = new ComplNum();
        for (int j_2 = 0; j_2 < kaef_two; j_2++) {
            count_2 += 7;
            k = k_1 + kaef_one * k_2;
            coef = (double) (j_2 * k) / (kaef_one * kaef_two);
            temp.real = Math.cos(-2 * pi * coef);
            temp.image = Math.sin(-2 * pi * coef);
            ComplNum res_mul = complNumMultiplication(array[k_1][j_2], temp);//что здесь в двойном массиве?
            sum.real += res_mul.real;
            sum.image += res_mul.image;
        }
        sum.real /= kaef_two;
        sum.image /= kaef_two;
        return sum;
    }

    private static ComplNum back_first_transform(ComplNum[] array, int k_1, int j_2) {
        double coef;
        ComplNum sum = new ComplNum();
        ComplNum temp = new ComplNum();
        for (int j_1 = 0; j_1 < kaef_one; j_1++) {
            coef = (double) (j_1 * k_1) / kaef_one;
            temp.real = Math.cos(2 * pi * coef);
            temp.image = Math.sin(2 * pi * coef);
            ComplNum res_mul = complNumMultiplication(temp, array[j_2 + kaef_two * j_1]);
            sum.real += res_mul.real;
            sum.image += res_mul.image;
        }
        return sum;
    }

    private static ComplNum back_second_transform(ComplNum[] array, int k_1, int k_2) {
        int k;
        double coef;
        ComplNum sum = new ComplNum();
        ComplNum temp = new ComplNum();
        for (int j_2 = 0; j_2 < kaef_two; j_2++) {
            ComplNum a_1 = back_first_transform(array, k_1, j_2);
            k = k_1 + kaef_one * k_2;
            coef = (double) (j_2 * k) / (kaef_one * kaef_two);
            temp.real = Math.cos(2 * pi * coef);
            temp.image = Math.sin(2 * pi * coef);
            ComplNum res_mul = complNumMultiplication(a_1, temp);
            sum.real += res_mul.real;
            sum.image += res_mul.image;
        }
        return sum;
    }

    private static void half_quick_transform(double[] source, ComplNum[] result) {
        int i = 0;
        ComplNum[][] a1 = new ComplNum[kaef_two * kaef_one][kaef_two * kaef_one];

        for (int j_2 = 0; j_2 < kaef_two; j_2++) {
            for (int k_1 = 0; k_1 < kaef_one; k_1++) {
                a1[k_1][j_2] = first_transform(source, k_1, j_2);
            }
        }
        for (int k_2 = 0; k_2 < kaef_two; k_2++) {
            for (int k_1 = 0; k_1 < kaef_one; k_1++) {
                result[i] = second_transform(a1, k_1, k_2);
                i++;
            }
        }
    }

    private static void back_half_quick_transform(ComplNum[] source, ComplNum[] result) {
        int i = 0;
        for (int k_2 = 0; k_2 < kaef_two; k_2++) {
            for (int k_1 = 0; k_1 < kaef_one; k_1++) {
                result[i] = back_second_transform(source, k_1, k_2);
                i++;
            }
        }
    }


}
