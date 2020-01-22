import java.lang.Math;
import java.util.Random;


public class Main {
    static double pi = Math.PI;
    static int n = 9;//размер исходного массива
    static int count = 0;//для подсчета трудемкости

    static ComplNum complNumMultiplication(ComplNum a, ComplNum b) {//перемножение компл. чисел
        ComplNum result = new ComplNum();
        result.real = a.real * b.real - a.image * b.image;
        result.image = a.real * b.image + a.image * b.real;
        return result;
    }

    static void forwardDFT(double array[], ComplNum result[]) {//прямое преобразование Фурье
        ComplNum A = new ComplNum();
        ComplNum sum = new ComplNum();
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                count += 5;//it's written(5) in the textbook
                //экспонент нет, т.к. сразу применили формулу Эйлера
                A.real = Math.cos((-2 * pi * k * j) / n) * array[j];//counting the piece of A[k], that's
                // in the sum in formula (just the real part) i.e. f0*exp(-2pi*i*k*j/N)
                A.image = Math.sin((-2 * pi * k * j) / n) * array[j];//the same, but for the image part
                sum.real += A.real;//summation of the pieces
                sum.image += A.image;
            }
            sum.real /= n;
            sum.image /= n;
            result[k].real = sum.real;//saving A0, A1 etc
            result[k].image = sum.image;
            sum.real = 0;
            sum.image = 0;
        }
    }

    static void backwardsDFT(ComplNum res[], ComplNum result[]) {//taking the result of dierct transform as res
        ComplNum A = new ComplNum();//the methods have the same difficulty(direct and bacward)
        ComplNum sum = new ComplNum();
        ComplNum res_mul = new ComplNum();
        sum.real = 0;
        sum.image = 0;
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {//the formula from the texbook
                A.real = Math.cos((2 * pi * k * j) / n);
                A.image = Math.sin((2 * pi * k * j) / n);
                res_mul = complNumMultiplication(A, res[j]);
                sum.real += res_mul.real;
                sum.image += res_mul.image;
            }
            result[k].real = sum.real;//appointing the new numbers for the new resulting complex numbers
            result[k].image = sum.image;//yes, the backward transform is also complex for some reason
           // if (result[k].image < 10e-10) result[k].image = 0;
            sum.real = 0;
            sum.image = 0;
        }
    }

    public static void main(String[] args) {
        double array[] = new double[n];
        ComplNum res[] = new ComplNum[n];//for A's in forward DFT (direct DFT outcome)
        ComplNum result[] = new ComplNum[n];//for the backward DFT outcome
        for (int i = 0; i < n; i++) {
            res[i] = new ComplNum();
            result[i] = new ComplNum();
        }
        Random rand = new Random();
        System.out.println("Source array: ");
        array[0] = 1;
        array[1] = 0;
        array[2] = 1;
        array[3] = 0;
        array[4] = 1;
        array[5] = 1;
        array[6] = 0;
        array[7] = 1;
        array[8] = 0;
        for (int i = 0; i < n; i++) {
            //array[i] = rand.nextInt(2);
            System.out.print(array[i] + "  ");
        }
        System.out.println();

        forwardDFT(array, res);
      //  System.out.println("\nReal part of direct transform: ");
       // System.out.println("прямое");
        for (int i = 0; i < n; i++) {
            //System.out.printf("%f ", res[i].real);
        }
        //System.out.println("\nImage part of direct transform: ");
        System.out.println("pramoe");
        for (int i = 0; i < n; i++) {
            System.out.printf("%f ", res[i].real);
            System.out.print(" ");
            System.out.printf("%f \n", res[i].image);
            //System.out.print("\n");
        }
        System.out.println();


        backwardsDFT(res, result);
       // System.out.println("\nReal part of back transform: ");
        for (int i = 0; i < n; i++) {
            //System.out.printf("%f ", result[i].real);
        }
       // System.out.println("\nImage part of back transform: ");
        System.out.println("obratnoe");
        for (int i = 0; i < n; i++) {
            System.out.printf("%f ", result[i].real);
            System.out.print(" ");
            System.out.printf("%f \n", result[i].image);
            //System.out.print("\n; ");
        }
        System.out.println("\nDifficulty: " + count);
    }
}
