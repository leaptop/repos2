/*procedure karatsuba(num1, num2)// wikipedia pseudocode. Doesn't work
  if (num1 < 10) or (num2 < 10)
    return num1 * num2

  /* Calculates the size of the numbers. */
// m = min(size_base10(num1), size_base10(num2))
//         m2 = floor(m / 2)
/*m2 = ceil(m / 2) will also work */

/* Split the digit sequences in the middle. */
//        high1, low1 = split_at(num1, m2)
//         high2, low2 = split_at(num2, m2)

/* 3 calls made to numbers approximately half the size. */
//         z0 = karatsuba(low1, low2)
//         z1 = karatsuba((low1 + high1), (low2 + high2))
//          z2 = karatsuba(high1, high2)

//         return (z2 * 10 ^ (m2 * 2)) + ((z1 - z2 - z0) * 10 ^ m2) + z0

public class Main {
    int func(int num1, int num2) {
        if (num1 < 10 || num2 < 10) return num1 * num2;
        int m = Math.min(String.valueOf(Math.abs(num1)).length(), String.valueOf(Math.abs(num2)).length());
        int m2 = (int)Math.floor( m / 2);//floor?
        int high1 = num1 / (String.valueOf(Math.abs(num1)).length() * 10);
        int low1 = num1 / (m2 * 10);
        int high2 = num1 / (String.valueOf(Math.abs(num2)).length() * 10);
        int low2 = num1 / (m2 * 10);
        int z0 = func(low1, low2);
        int z1 = func((low1 + high1), (low2 + high2));
        int z2 = func(high1, high2);
        return (z2 * 10 ^ (m2 * 2)) + ((z1 - z2 - z0) * 10 ^ m2) + z0;
    }

    public static void main(String[] args) {
        Main m = new Main();
        System.out.println("result = "+ m.func(21, 49));
    }
}
