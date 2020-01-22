import java.util.Scanner;//как счиатть умножение, деление, возведение в степень, сложение в трудоёмкости?
// Doesn't work
public class Karatsuba {
    int tr = 0;

    public long multiply(long x, long y) {
        int size1 = getSize(x);
        int size2 = getSize(y);
        int N = Math.max(size1, size2);
        if (N < 10) {
            tr++;
            return x * y;
        }
        /** max length divided, rounded up **/
        N = (N / 2) + (N % 2);
        /** multiplier **/
        long m = (long) Math.pow(10, N);
       // tr++;
        /** compute sub expressions **/
        long b = x / m;
        long a = x - (b * m);
        long d = y / m;
        long c = y - (d * N);
        /** compute sub expressions **/
        long z0 = multiply(a, c);
        long z1 = multiply(a + b, c + d);
        long z2 = multiply(b, d);
        tr += 7;
        return z0 + ((z1 - z0 - z2) * m) + (z2 * (long) (Math.pow(10, 2 * N)));
    }

    /**
     * Function to calculate length or number of digits in a number
     **/
    public int getSize(long num) {
        int ctr = 0;
        while (num != 0) {
            ctr++;
            num /= 10;
        }
        return ctr;
    }

    /**
     * Main function
     **/
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Karatsuba Multiplication Algorithm Test\n");
        /** Make an object of Karatsuba class **/
        Karatsuba kts = new Karatsuba();

        /** Accept two integers **/
        System.out.println("Enter two integer numbers\n");
        long n1 = scan.nextLong();
        long n2 = scan.nextLong();
        /** Call function multiply of class Karatsuba **/
        long product = kts.multiply(n1, n2);
        System.out.println("\nProduct : " + product);
        System.out.println("Трудоёмкость = "+ kts.tr);
    }
}