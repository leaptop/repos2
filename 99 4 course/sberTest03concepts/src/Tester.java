import java.util.ArrayList;
import java.util.List;

public class Tester {
    public static void main(String[] args) {
        B b = new B();
        List list = new ArrayList();
        b.m(list);
        for (int i = 0; i<list.size();i++){
            System.out.println(list.get(i));
            System.out.println("list.get(i)");
        }

    }
}
