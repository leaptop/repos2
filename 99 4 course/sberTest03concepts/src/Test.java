import java.util.AbstractSet;
import java.util.Arrays;
import java.util.List;

public class Test {

    static List<Integer> a = Arrays.asList(1, 2, 3, 4, 5);

    public static void main(String args[]) {
        for (int i = 0; i < a.size(); i++) {
            if (a.get(i) > 1) a.remove(i);
    }
       // AbstractSet<String> abss = new AbstractSet<String>();
        System.out.println(a);

//        public static void main(String[] args) { String city = null;
//
//            if (city.equals("Moscow")) {
//
//                System.out.print("true");
//
//            } else {
//
//                System.out.print("false");
//
//            } finally {
//
//                System.out.print("finally");
//
//            }
//
//        }
    }
}