import java.io.IOException;

public class Test3 {
    public static void main(String[] args) throws Exception {
        try {
            System.out.println("1");
            throw new IOException(); // 1
           // System.out.println("1");//unreacheable statement
             } catch (IOException ex) { System.out.println("2");
            throw new IOException(); // 2

             } catch (Exception ex) {
            System.out.println("3");
// 3
        } finally {
            System.out.println("4");
// 4
        }
        System.out.println("5");
// 5
//        try {
//            throw new FirstException1().getCause();
//        } finally {
//            throw new SecondException2();
//           // System.out.println("fig");
//        }
    }
}

class FirstException1 extends Exception {
}

class SecondException2 extends Exception {
}