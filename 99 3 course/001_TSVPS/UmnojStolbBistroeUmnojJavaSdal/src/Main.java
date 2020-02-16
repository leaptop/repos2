public class Main {//Всё чисто по методичке
    // long an = Integer.parseInt(strSplit(k, aString)[0]);//брать циферки надо так, (а не так: long an = a / 10;) иначе косячится программа, вычисления не те получаются

    long x = 999999999, y = 999999999, countObi = 0, countUmno = 0, countPro = 0, countKar = 0;

    long obi(long a, long b) {//обычное умножение столбиком/////
        long sum = 0;
        long min = 0, max = 0;
        if (a > b) {
            min = b;
            max = a;
        } else {
            min = a;
            max = b;
        }
        long x = max, y = min;
        int maxLength = String.valueOf(Math.abs(max)).length();
        int minLength = String.valueOf(Math.abs(min)).length();
        long[] aa = new long[minLength];
        for (int i = 0; i < minLength; i++) {//разбираю минимальное число на циферки
            aa[i] = min % 10;
            min = min / 10;

        }
        for (int i = 0; i < minLength; i++) {
            max *= (aa[i] * Math.pow(10, i));
            sum += max;
            max = x;
            countObi += maxLength;
            //if(max == 0)
        }
        countObi += minLength;
        return sum;
    }

    long umno(long a, long b) {//алгоритм 2.7
        if (a < 10 || b < 10) {
            if (a == 0 || b == 0) {
                countUmno--;
                return a * b;
            }//на ноль не умножают
            else {
                countUmno++;
                return a * b;
            }

        }
        String aString = Integer.toString((int) a);
        String bString = Integer.toString((int) b);
        int n = Math.max(aString.length(), bString.length());
        int k = n / 2;
        long an = Integer.parseInt(strSplit(k, aString)[0]);
        long bn = Integer.parseInt(strSplit(k, aString)[1]);
        long cn = Integer.parseInt(strSplit(k, bString)[0]);
        long dn = Integer.parseInt(strSplit(k, bString)[1]);
        long stepen1 = (int) Math.pow(10, 2 * k);
        long stepen2 = (int) Math.pow(10, k);
        countUmno += 7;
        return umno(an, cn) * (stepen1) + (umno(an, dn) + umno(bn, cn)) * (stepen2) + umno(bn, dn);
    }

    long T2_7(int n) {
        return T2_7(n / 2) + n;
    }

    long pro(long a, long b) {//алгоритм 2.8
        if (a < 10 || b < 10) return a * b;
        //long an = a / 10;
        //long cn = b / 10;
        //long bn = a % 10;
        //long dn = b % 10;
        String aString = Integer.toString((int) a);
        String bString = Integer.toString((int) b);
        int n = Math.max(aString.length(), bString.length());
        int k = n / 2;
        long an = Integer.parseInt(strSplit(k, aString)[0]);
        long bn = Integer.parseInt(strSplit(k, aString)[1]);
        long cn = Integer.parseInt(strSplit(k, bString)[0]);
        long dn = Integer.parseInt(strSplit(k, bString)[1]);
        long u = pro((an + bn), (cn + dn));
        long v = pro(an, cn);
        long w = pro(bn, dn);
        long stepen1 = (int) Math.pow(10, 2 * k);
        long stepen2 = (int) Math.pow(10, k);
        countPro += 3;
        return (v * stepen1 + (u - v - w) * stepen2 + w);
    }

    long kar(long a, long b) {
        if (a < 10 || b < 10) {
            if (a == 0 || b == 0) {
                countKar--;
                return a * b;
            }//на ноль не умножают
            else {
                countKar++;
                return a * b;
            }
        } else {
            String aString = Integer.toString((int) a);//сделал строки из целых, чтобы не было косяков потом
            String bString = Integer.toString((int) b);
            int n = Math.max(aString.length(), bString.length());
            int k = n / 2;
            long an = Integer.parseInt(strSplit(k, aString)[0]);
            long bn = Integer.parseInt(strSplit(k, aString)[1]);
            long cn = Integer.parseInt(strSplit(k, bString)[0]);
            long dn = Integer.parseInt(strSplit(k, bString)[1]);
            long w = kar(bn, dn);
            long v = kar(an, cn);
            long u = kar((bn + an), (dn + cn));
            //countKar += 3;
            countKar += 3;
            if (w == 0) countKar -= 1;
            if (v == 0) countKar -= 1;
            if (u == 0) countKar -= 1;
            if (w == 0 && v == 0 && w == 0) countKar -= 1;
            return (v * (long) Math.pow(10, 2 * k) + ((u - v - w) * (long) Math.pow(10, k)) + w);
        }

    }

    long TKar(long n) {//T(n) = 3 T(n/2) + 4n
        if (n == 0) return 0;
        else
            return 3 * TKar(n / 2) + 4 * n;
    }

    long TKar2(long n) {//T(n) ≈ n logk(n)....
        if (n == 0) return 0;
        else
            return n * log2(3);
    }

    public static long log2(long n) {
        if (n <= 0) throw new IllegalArgumentException();
        return 31 - Integer.numberOfLeadingZeros((int)n);
    }

    static String[] strSplit(int index, String string) {
        String first = "",
                last = "";
        int actualIndex = string.length() - index;
        for (int i = 0; i < actualIndex; i++) {
            first += string.charAt(i);
        }
        for (int i = (int) actualIndex; i < string.length(); i++) {
            last += string.charAt(i);
        }
        return new String[]{first, last};
    }

    public static void main(String[] args) {
        Main mn = new Main();
      //  System.out.print("умножение столбиком :        " + mn.obi(mn.x, mn.y));
      //  System.out.println("  Трудоёмкость: " + mn.countObi);
        System.out.print("умножение алгоритмом 2.7:    " + mn.umno(mn.x, mn.y));
        System.out.println("  Трудоёмкость: " + mn.countUmno);
        //System.out.println("  Трудоёмкость по формуле T(n) = 4·T(n/2) + 1·n: " + mn.countUmno);
        //System.out.print("умножение алгоритмом 2.8:    " + mn.pro(mn.x, mn.y));
        // System.out.println("  Трудоёмкость: " + mn.countPro);
        System.out.print("2.8 исправл.:                " + mn.kar(mn.x, mn.y));
        System.out.print("  Трудоёмкость: " + mn.countKar);
       // System.out.println(" Трудоёмкость по формуле: " + mn.TKar2(mn.x));
        //System.out.println("log2 = "+ log2(1024));
    }

}
